/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:05:46 by aeid              #+#    #+#             */
/*   Updated: 2024/02/18 21:53:16 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong_bonus.h"

void	error_message(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	destroy_all(t_map *mlx)
{
	int	i;

	i = 0;
	while (i < (NUM_ELE - 1))
	{
		mlx_destroy_image(mlx->mlxptr, mlx->imags[i].img);
		i++;
	}
}

char	**free_matrix(char **copy)
{
	int	i;

	i = 0;
	while (copy && copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
	return (NULL);
}

int	end_end(t_map *map)
{
	mlx_loop_end(map->mlxptr);
	return (0);
}
