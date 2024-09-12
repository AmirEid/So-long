# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 16:29:01 by aeid              #+#    #+#              #
#    Updated: 2024/02/19 16:13:18 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LFLAGS = -Lminilibx-linux -lmlx -lmlx_Linux -lX11 -lXext -no-pie

HEADER_SRC = solong.h get_next_line.h
HEADER_DIR = headers/
H_PATH = $(addprefix $(HEADER_DIR), $(HEADER_SRC))

M_SRC = checks.c error.c main.c map_checks.c map.c path_checks_utils.c start_game.c game_keys.c movements.c
M_DIR = Mandatory/
M_PATH = $(addprefix $(M_DIR), $(M_SRC))
M_OBJ = $(M_PATH:.c=.o)

B_SRC = checks.c error.c main.c map_checks.c map.c path_checks_utils.c start_game.c game_keys.c movements.c loop_enemy.c enemy_movement.c
B_DIR = bonus/
B_PATH = $(addprefix $(B_DIR), $(B_SRC))
B_OBJ = $(B_PATH:.c=.o)

U_SRC = ft_calloc.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c
U_DIR = utils/
U_PATH = $(addprefix $(U_DIR), $(U_SRC))
U_OBJ = $(U_PATH:.c=.o)

G_SRC = get_next_line.c get_next_line_utils.c
G_DIR = Get_next_line/
G_PATH = $(addprefix $(G_DIR), $(G_SRC))
G_OBJ = $(G_PATH:.c=.o)

MLX_DIR = ./minilibx-linux/

%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(U_OBJ) $(G_OBJ) $(M_OBJ)
	make -C $(MLX_DIR) --no-print-directory
	$(CC) $(CFLAGS) $(U_OBJ) $(G_OBJ) $(M_OBJ) -o $(NAME) $(LFLAGS)

$(BONUS_NAME): $(U_OBJ) $(G_OBJ) $(B_OBJ)
	make -C $(MLX_DIR) --no-print-directory
	$(CC) $(CFLAGS) $(U_OBJ) $(G_OBJ) $(B_OBJ) -o $(BONUS_NAME) $(LFLAGS)

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	$(RM) $(U_OBJ)
	$(RM) $(G_OBJ)
	$(RM) $(M_OBJ)
	$(RM) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
	