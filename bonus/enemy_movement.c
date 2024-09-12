/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:35:14 by aeid              #+#    #+#             */
/*   Updated: 2024/02/19 17:40:32 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong_bonus.h"

void	enemy_up(t_map *map, int i, int j)
{
	if (map->map[i - 1][j] == '0')
	{
		map->map[i - 1][j] = 'N';
		map->map[i][j] = '0';
		upload_images_to_window(map, i - 1, j);
		upload_images_to_window(map, i, j);
	}
}

void	enemy_down(t_map *map, int i, int j)
{
	if (map->map[i + 1][j] == '0')
	{
		map->map[i + 1][j] = 'N';
		map->map[i][j] = '0';
		upload_images_to_window(map, i + 1, j);
		upload_images_to_window(map, i, j);
	}
}

void	enemy_right(t_map *map, int i, int j)
{
	if (map->map[i][j + 1] == '0')
	{
		map->map[i][j + 1] = 'N';
		map->map[i][j] = '0';
		upload_images_to_window(map, i, j + 1);
		upload_images_to_window(map, i, j);
	}
}

void	enemy_left(t_map *map, int i, int j)
{
	if (map->map[i][j - 1] == '0')
	{
		map->map[i][j - 1] = 'N';
		map->map[i][j] = '0';
		upload_images_to_window(map, i, j - 1);
		upload_images_to_window(map, i, j);
	}
}
