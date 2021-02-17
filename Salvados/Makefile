# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 09:37:57 by ccastill          #+#    #+#              #
#    Updated: 2021/02/17 17:25:31 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
#Librerías
LIBRARY_MLX =  ./lib/mlx/minilibx-linux
LIBRARY_LIBFT = ./lib/libft
LIBRARY_GNL = ./lib/get_next_line

#Flags
MLXFLAGS := -L$(LIBRARY_MLX) ./lib/mlx/minilibx-linux/libmlx.a -lXext -lX11 -lmlx -lm
CFLAGS := -Wall -Wextra -Werror -I

#Compilación y borrado
CC := gcc
RM := rm -rf

MAIN_DIRECTORY := ./
ENGINE := $(wildcard $(MAIN_DIRECTORY)*.c) \
	$(wildcard $(LIBRARY_GNL)*.c) \
	$(wildcard $(MAIN_DIRECTORY)engine/*.c)
OBJS := $(ENGINE:%.c=%.o)	
	
all: libft minilibx $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(LIBRARY_GNL)*.c -o $(NAME) $(CFLAGS) $(MLXFLAG) -L$(LIBRARY_LIBFT) $(LIBRARY_LIBFT)/libft.a 

libft :
	make  -C $(LIBRARY_LIBFT)

minilibx : 
	make -C $(LIBRARY_MLX)
 	
clean:
		make -C $(LIBRARY_LIBFT) clean
		$(RM) $(OBJS)
fclean:
		make clean
		$(RM) $(NAME)
		make -C $(LIBRARY_LIBFT) fclean
	
re: 
	make fclean all

# La siguiente línea de compilación funciona : cc Prueba.c -L ./mlx/minilibx-linux/ -lmlx -lXext -lX11 -lm -lbsd