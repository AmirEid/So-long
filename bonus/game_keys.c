/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:39:59 by aeid              #+#    #+#             */
/*   Updated: 2024/02/19 17:03:08 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong_bonus.h"

static void	open_the_door(t_map *mlx)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'E')
			{
				mlx->map[i][j] = 'W';
				upload_images_to_window(mlx, i, j);
				found = 1;
				break ;
			}
		}
		if (found)
			break ;
	}
}

static int	check_sprites(t_map *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}

static void	player_position(t_map *mlx)
{
	int	i;

	i = 0;
	mlx->p_p_y = -1;
	while (mlx->map[++mlx->p_p_y])
	{
		mlx->p_p_x = -1;
		while (mlx->map[mlx->p_p_y][++mlx->p_p_x])
		{
			if (mlx->map[mlx->p_p_y][mlx->p_p_x] == 'P')
			{
				i = 1;
				break ;
			}
		}
		if (i)
			break ;
	}
}

int	game_keys(int keycode, t_map *mlx)
{
	int	flag;

	player_position(mlx);
	flag = check_sprites(mlx);
	loop_event(mlx);
	if (flag)
		open_the_door(mlx);
	if (keycode == 0xff1b)
		mlx_loop_end(mlx->mlxptr);
	else if (keycode == 'w')
		go_up(mlx);
	else if (keycode == 's')
		go_down(mlx);
	else if (keycode == 'a')
		go_left(mlx);
	else if (keycode == 'd')
		go_right(mlx);
	return (0);
}
