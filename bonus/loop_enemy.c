/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:32:04 by aeid              #+#    #+#             */
/*   Updated: 2024/02/19 17:14:02 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong_bonus.h"

void	ft_randomizer(t_map *map, int i, int j)
{
	if (rand() % 4 == 0)
		enemy_up(map, i, j);
	else if (rand() % 4 == 1)
		enemy_down(map, i, j);
	else if (rand() % 4 == 2)
		enemy_right(map, i, j);
	else if (rand() % 4 == 3)
		enemy_left(map, i, j);
}

void	find_enemy(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'N')
				ft_randomizer(map, i, j);
		}
	}
}

int	loop_event(t_map *map)
{
	find_enemy(map);
	return (0);
}
