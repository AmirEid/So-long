/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:32:44 by amireid           #+#    #+#             */
/*   Updated: 2024/02/18 21:18:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong.h"

void	generate_images(t_map *mlx)
{
	int	size;

	size = SIZE;
	mlx->imags[0].img = mlx_xpm_file_to_image(mlx->mlxptr, WALL, &size, &size);
	mlx->imags[1].img = mlx_xpm_file_to_image(mlx->mlxptr, TERRA, &size, &size);
	mlx->imags[2].img = mlx_xpm_file_to_image(mlx->mlxptr, PLEFT, &size, &size);
	mlx->imags[3].img = mlx_xpm_file_to_image(mlx->mlxptr, PRIGHT, &size,
			&size);
	mlx->imags[4].img = mlx_xpm_file_to_image(mlx->mlxptr, DOORC, &size, &size);
	mlx->imags[5].img = mlx_xpm_file_to_image(mlx->mlxptr, DOORO, &size, &size);
	mlx->imags[6].img = mlx_xpm_file_to_image(mlx->mlxptr, SPRITE, &size,
			&size);
	mlx->imags[7].img = NULL;
}

int	images_addresses(t_map *mlx)
{
	int	i;

	i = 0;
	while (mlx->imags[i].img)
	{
		mlx->imags[i].addr = mlx_get_data_addr(mlx->imags[i].img,
				&mlx->imags[i].bpp, &mlx->imags[i].size_line,
				&mlx->imags[i].endian);
		if (mlx->imags[i].addr == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	upload_images_to_window(t_map *map, int x, int y)
{
	if (map->map[x][y] == 'P')
		mlx_put_image_to_window(map->mlxptr, map->window, map->imags[3].img, y
			* 50, x * 50);
	if (map->map[x][y] == '1')
		mlx_put_image_to_window(map->mlxptr, map->window, map->imags[0].img, y
			* 50, x * 50);
	if (map->map[x][y] == '0')
		mlx_put_image_to_window(map->mlxptr, map->window, map->imags[1].img, y
			* 50, x * 50);
	if (map->map[x][y] == 'E')
		mlx_put_image_to_window(map->mlxptr, map->window, map->imags[4].img, y
			* 50, x * 50);
	if (map->map[x][y] == 'C')
		mlx_put_image_to_window(map->mlxptr, map->window, map->imags[6].img, y
			* 50, x * 50);
	if (map->map[x][y] == 'W')
		mlx_put_image_to_window(map->mlxptr, map->window, map->imags[5].img, y
			* 50, x * 50);
}

void	initiate_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			upload_images_to_window(map, i, j);
	}
}

int	initiate_game(t_map *mlx)
{
	mlx->window = mlx_new_window(mlx->mlxptr, ((mlx->columns) * 50),
			((mlx->rows) * 50), "Ducks are friends");
	if (!mlx->window)
		return (0);
	generate_images(mlx);
	if (!check_images(mlx))
		return (0);
	if (!images_addresses(mlx))
	{
		destroy_all(mlx);
		return (0);
	}
	initiate_map(mlx);
	return (1);
}
