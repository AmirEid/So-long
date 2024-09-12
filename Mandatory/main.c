/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:30:19 by aeid              #+#    #+#             */
/*   Updated: 2024/02/19 16:49:15 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong.h"

void	print_moves(t_map *map)
{
	map->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(map->moves, 1);
	ft_putchar_fd('\n', 1);
}

static void	destroy_everything(t_map *map)
{
	mlx_loop_end(map->mlxptr);
	mlx_destroy_window(map->mlxptr, map->window);
	destroy_all(map);
	free_map(map);
	mlx_destroy_display(map->mlxptr);
	free(map->mlxptr);
}

static t_map	initialise_map(void)
{
	t_map	map;

	map.map = NULL;
	map.rows = 0;
	map.columns = 0;
	map.door = 0;
	map.player = 0;
	map.sprite = 0;
	map.moves = 0;
	map.flag = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	check_args(argc, argv);
	map = initialise_map();
	read_map(argv[1], &map);
	map.mlxptr = mlx_init();
	if (!initiate_game(&map))
	{
		mlx_destroy_window(map.mlxptr, map.window);
		mlx_destroy_display(map.mlxptr);
		free_map(&map);
		error_message(ERROR_GAME);
	}
	mlx_key_hook(map.window, game_keys, &map);
	mlx_hook(map.window, 17, 0, end_end, &map);
	mlx_loop(map.mlxptr);
	destroy_everything(&map);
	return (0);
}
