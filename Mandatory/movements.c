/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:24:22 by aeid              #+#    #+#             */
/*   Updated: 2024/02/19 12:41:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong.h"

void	end_game(t_map *map)
{
	ft_putstr_fd("You are back home safe with all the crackers!", 1);
	mlx_loop_end(map->mlxptr);
}

void	go_up(t_map *map)
{
	if (map->map[map->p_p_y - 1][map->p_p_x] != '1')
	{
		if (map->map[map->p_p_y - 1][map->p_p_x] == 'W')
			end_game(map);
		if ((map->map[map->p_p_y - 1][map->p_p_x] == '0' || map->map[map->p_p_y
				- 1][map->p_p_x] == 'C' || map->map[map->p_p_y
				- 1][map->p_p_x] == 'E') && map->flag == 0)
		{
			if (map->map[map->p_p_y - 1][map->p_p_x] == 'E')
				map->flag = 1;
			map->map[map->p_p_y - 1][map->p_p_x] = 'P';
			upload_images_to_window(map, map->p_p_y - 1, map->p_p_x);
			map->map[map->p_p_y][map->p_p_x] = '0';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
		}
		else
		{
			map->map[map->p_p_y - 1][map->p_p_x] = 'P';
			upload_images_to_window(map, map->p_p_y - 1, map->p_p_x);
			map->map[map->p_p_y][map->p_p_x] = 'E';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
			map->flag = 0;
		}
		print_moves(map);
	}
}

void	go_down(t_map *map)
{
	if (map->map[map->p_p_y + 1][map->p_p_x] != '1')
	{
		if (map->map[map->p_p_y + 1][map->p_p_x] == 'W')
			end_game(map);
		if ((map->map[map->p_p_y + 1][map->p_p_x] == '0' || map->map[map->p_p_y
				+ 1][map->p_p_x] == 'C' || map->map[map->p_p_y
				+ 1][map->p_p_x] == 'E') && map->flag == 0)
		{
			if (map->map[map->p_p_y + 1][map->p_p_x] == 'E')
				map->flag = 1;
			map->map[map->p_p_y + 1][map->p_p_x] = 'P';
			upload_images_to_window(map, map->p_p_y + 1, map->p_p_x);
			map->map[map->p_p_y][map->p_p_x] = '0';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
		}
		else
		{
			map->map[map->p_p_y + 1][map->p_p_x] = 'P';
			upload_images_to_window(map, map->p_p_y + 1, map->p_p_x);
			map->map[map->p_p_y][map->p_p_x] = 'E';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
			map->flag = 0;
		}
		print_moves(map);
	}
}

void	go_right(t_map *map)
{
	if (map->map[map->p_p_y][map->p_p_x + 1] != '1')
	{
		if (map->map[map->p_p_y][map->p_p_x + 1] == 'W')
			end_game(map);
		if (map->flag == 0)
		{
			if (map->map[map->p_p_y][map->p_p_x + 1] == 'E')
				map->flag = 1;
			map->map[map->p_p_y][map->p_p_x + 1] = 'P';
			upload_images_to_window(map, map->p_p_y, map->p_p_x + 1);
			map->map[map->p_p_y][map->p_p_x] = '0';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
		}
		else
		{
			map->map[map->p_p_y][map->p_p_x + 1] = 'P';
			upload_images_to_window(map, map->p_p_y, map->p_p_x + 1);
			map->map[map->p_p_y][map->p_p_x] = 'E';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
			map->flag = 0;
		}
		print_moves(map);
	}
}

void	go_left(t_map *map)
{
	if (map->map[map->p_p_y][map->p_p_x - 1] != '1')
	{
		if (map->map[map->p_p_y][map->p_p_x - 1] == 'W')
			end_game(map);
		if (map->flag == 0)
		{
			if (map->map[map->p_p_y][map->p_p_x - 1] == 'E')
				map->flag = 1;
			map->map[map->p_p_y][map->p_p_x - 1] = 'P';
			upload_images_to_window(map, map->p_p_y, map->p_p_x - 1);
			map->map[map->p_p_y][map->p_p_x] = '0';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
		}
		else
		{
			map->map[map->p_p_y][map->p_p_x - 1] = 'P';
			upload_images_to_window(map, map->p_p_y, map->p_p_x - 1);
			map->map[map->p_p_y][map->p_p_x] = 'E';
			upload_images_to_window(map, map->p_p_y, map->p_p_x);
			map->flag = 0;
		}
		print_moves(map);
	}
}
