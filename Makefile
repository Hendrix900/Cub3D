# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 09:37:57 by ccastill          #+#    #+#              #
#    Updated: 2021/03/06 03:49:22 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDES = cub3d.h ./lib/libft/libft.h ./lib/mlx/minilibx-linux/mlx.h 

FLAGS = gcc -I -Wall -Wextra -Werror

FUN = cub3d.c ./engine/print_error.c ./engine/read_file.c ./engine/extract_resolution.c ./engine/extract_texture.c \
	./engine/extract_color.c ./engine/count_split.c ./engine/read_map.c ./engine/read_moremap.c ./engine/get_texture.c \
	./engine/init_player.c ./engine/raycasting.c

OBJ = $(FUN:.c=.o)

LIBFT = ./lib/libft/libft.a

PLATFORM := $(shell uname)

ifeq ($(PLATFORM), Linux)
	MLX =  ./lib/mlx/minilibx-linux/libmlx.a 
	MLX_CC = ./lib/mlx/minilibx-linux
	MINILIBX = -lmlx -lXext -lX11 -lm -lbsd
else
	MLX =  ./lib/mlx/minilibx_mac/libmlx.a 
	MLX_CC = ./lib/mlx/minilibx_mac
	MINILIBX = -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(LIBFT): 
	@$(MAKE) -C ./lib/libft/

$(MLX):
	@$(MAKE) -C $(MLX_CC)

$(NAME): $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) 
	@$(FLAGS) $(FUN) $(LIBFT) $(MLX) -Llib/libft -lft -L$(MLX_CC) -lmlx $(MINILIBX) -o $(NAME)

clean:
	@rm -f $(OBJ) *.o ./lib/libft/*.o ./lib/get_next_line/*.o ./engine/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)

re: clean fclean all