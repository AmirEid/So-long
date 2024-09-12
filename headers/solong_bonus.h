/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:48:14 by aeid              #+#    #+#             */
/*   Updated: 2024/02/19 16:11:49 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

# include "../headers/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARGS "Invalid number of arguments"
# define ERROR_MFILE "Invalid file type of .ber"
# define ERROR_OPEN "Failed to open the file"
# define ERROR_MAP "Invalid map"
# define ERROR_MEM "Failed to allocate memory"
# define ERROR_GAME "Failed to launch the game"
# define ERROR_PATH "One element is not accessable"

# define SIZE 50
# define NUM_ELE 8

# define PLEFT "xpm/player-left.xpm"
# define PRIGHT "xpm/duck.xpm"
# define DOORC "xpm/closed-door.xpm"
# define DOORO "xpm/door-open.xpm"
# define SPRITE "xpm/crackers.xpm"
# define TERRA "xpm/terrain.xpm"
# define WALL "xpm/wall.xpm"
# define ENEMY "xpm/enemy-11.xpm"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_image;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		door;
	int		player;
	int		sprite;
	void	*mlxptr;
	void	*window;
	t_image	imags[NUM_ELE];
	int		moves;
	int		p_p_x;
	int		p_p_y;
	int		flag;
	int		enemy;
}			t_map;

void		store_map(char *map_file, t_map *map);
void		read_map(char *map_file, t_map *map);
int			initiate_game(t_map *mlx);
void		initiate_map(t_map *map);
void		upload_images_to_window(t_map *map, int x, int y);
int			images_addresses(t_map *mlx);
void		generate_images(t_map *mlx);
int			check_map_elements(t_map *map);
int			base_case(char **copy);
int			fill_path(char **copy);
int			check_raws(t_map *map);
int			check_walls(t_map *map);
int			check_images(t_map *mlx);
int			check_map(t_map *map);
void		check_args(int argc, char **argv);
void		error_message(char *str);
void		free_map(t_map *map);
void		destroy_all(t_map *mlx);
char		**free_matrix(char **copy);
int			check_path(char **copy);
char		**copy_map(t_map *map);
void		p_filler(char **copy, int *i, int *j);
void		*ft_calloc(size_t n, size_t size);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t len);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *str, int c);
int			check_currentp(char **copy, int *i, int *j);
int			game_keys(int keycode, t_map *mlx);
void		go_up(t_map *map);
void		go_down(t_map *map);
void		go_right(t_map *map);
void		go_left(t_map *map);
void		end_game(t_map *map, const char *flag);
int			end_end(t_map *map);
void		ft_putnbr_fd(int n, int fd);
void		print_moves(t_map *map);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
char		*ft_itoa(int i);
void		find_enemy(t_map *map);
void		enemy_left(t_map *map, int i, int j);
void		enemy_right(t_map *map, int i, int j);
void		enemy_down(t_map *map, int i, int j);
void		enemy_up(t_map *map, int i, int j);
void		ft_randomizer(t_map *map, int i, int j);
int			loop_event(t_map *map);

#endif