/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:07:28 by aeid              #+#    #+#             */
/*   Updated: 2024/02/06 19:43:25 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong.h"

void	store_map(char *map_file, t_map *map)
{
	int	i;
	int	fd;

	map->map = (char **)ft_calloc(map->rows + 1, sizeof(char *));
	if (!map->map)
		error_message(ERROR_MEM);
	fd = open(map_file, O_RDONLY);
	i = 0;
	while (i < map->rows)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
		{
			error_message(ERROR_MAP);
			return (free_map(map));
		}
		if (i != map->rows - 1)
			map->map[i][ft_strlen(map->map[i]) - 1] = 0;
		i++;
	}
	map->columns = ft_strlen(map->map[0]);
	close(fd);
}

void	read_map(char *map_file, t_map *map)
{
	int		fd;
	char	*tmp;

	fd = open(map_file, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		map->rows++;
	}
	close(fd);
	if (map->rows < 3)
		error_message(ERROR_MAP);
	store_map(map_file, map);
	if (!check_map(map))
	{
		free_map(map);
		error_message(ERROR_MAP);
	}
}
