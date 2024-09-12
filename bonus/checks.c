/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:16:06 by aeid              #+#    #+#             */
/*   Updated: 2024/02/18 22:21:54 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong_bonus.h"

void	check_args(int argc, char **argv)
{
	int		fd;
	char	*p;

	if (argc != 2)
		error_message(ERROR_ARGS);
	p = ft_strrchr(argv[1], '.');
	if (*argv[1] == '\0' || ft_strncmp(p, ".ber", 4))
		error_message(ERROR_MFILE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message(ERROR_OPEN);
	close(fd);
}

int	check_map(t_map *map)
{
	char	**copy;

	if (!check_map_elements(map))
		return (0);
	else if (!check_raws(map))
		return (0);
	else if (!check_walls(map))
		return (0);
	else if (map->columns < 3 || map->columns == map->rows)
		return (0);
	else if ((map->player != 1) || (map->door != 1) || (map->sprite < 1))
		return (0);
	copy = copy_map(map);
	if (!copy)
		return (0);
	if (!fill_path(copy))
	{
		free_matrix(copy);
		return (0);
	}
	free_matrix(copy);
	return (1);
}

int	check_images(t_map *mlx)
{
	int	i;

	i = 0;
	while (i < (NUM_ELE - 1))
	{
		if (mlx->imags[i].img == NULL)
		{
			i = 0;
			while (i < (NUM_ELE - 1))
			{
				if (mlx->imags[i].img != NULL)
					mlx_destroy_image(mlx->mlxptr, mlx->imags[i].img);
				i++;
			}
			return (0);
		}
		i++;
	}
	return (1);
}
