/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:28:37 by aeid              #+#    #+#             */
/*   Updated: 2024/02/18 22:24:45 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong_bonus.h"

int	check_map_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->player++;
			else if (map->map[i][j] == 'C')
				map->sprite++;
			else if (map->map[i][j] == 'E')
				map->door++;
			else if (map->map[i][j] == 'N')
				map->enemy++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_case(char **copy)
{
	int	i;
	int	j;

	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (copy[i][j] == 'P')
			{
				if ((copy[i - 1][j] != '1' && copy[i - 1][j] != 'P') || (copy[i
						+ 1][j] != '1' && copy[i + 1][j] != 'P') || (copy[i][j
						+ 1] != '1' && copy[i][j + 1] != 'P') || (copy[i][j
						- 1] != '1' && copy[i][j - 1] != 'P'))
					return (1);
			}
		}
	}
	return (0);
}

int	fill_path(char **copy)
{
	int	i;
	int	j;

	if (!base_case(copy))
		return (check_path(copy));
	i = -1;
	while (copy[++i])
	{
		j = -1;
		while ((copy[i][++j]))
		{
			if (copy[i][j] == 'P' && check_currentp(copy, &i, &j))
			{
				p_filler(copy, &i, &j);
				fill_path(copy);
				return (check_path(copy));
			}
		}
	}
	return (1);
}

int	check_raws(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]);
		if (len != map->columns)
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] && map->map[map->rows - 1][i])
	{
		if (map->map[0][i] != '1' || map->map[map->rows - 1][i] != '1')
			return (0);
		else
			i++;
	}
	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] != '1' || map->map[i][map->columns - 1] != '1')
			return (0);
		else
			i++;
	}
	return (1);
}
