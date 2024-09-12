/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:18:54 by aeid              #+#    #+#             */
/*   Updated: 2024/02/18 21:53:51 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong_bonus.h"

int	check_path(char **copy)
{
	int	i;
	int	j;

	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (copy[i][j] == 'E' || copy[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (map->map[++i])
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
			return (free_matrix(copy));
	}
	copy[i] = NULL;
	return (copy);
}

void	p_filler(char **copy, int *i, int *j)
{
	if (copy[*i][*j] == 'P')
	{
		if (copy[*i - 1][*j] != '1' && copy[*i - 1][*j] != 'P')
			copy[*i - 1][*j] = 'P';
		if (copy[*i + 1][*j] != '1' && copy[*i + 1][*j] != 'P')
			copy[*i + 1][*j] = 'P';
		if (copy[*i][*j + 1] != '1' && copy[*i][*j + 1] != 'P')
			copy[*i][*j + 1] = 'P';
		if (copy[*i][*j - 1] != '1' && copy[*i][*j - 1] != 'P')
			copy[*i][*j - 1] = 'P';
	}
}

int	check_currentp(char **copy, int *i, int *j)
{
	if ((copy[*i - 1][*j] != '1' && copy[*i - 1][*j] != 'P') || (copy[*i
			+ 1][*j] != '1' && copy[*i + 1][*j] != 'P') || (copy[*i][*j
			+ 1] != '1' && copy[*i][*j + 1] != 'P') || (copy[*i][*j - 1] != '1'
			&& copy[*i][*j - 1] != 'P'))
		return (1);
	else
		return (0);
}
