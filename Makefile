# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 09:37:57 by ccastill          #+#    #+#              #
#    Updated: 2020/07/24 12:26:11 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDES = cub3d.h ./mlx/minilibx-linux/mlx.h

FUN = Prueba.c \

OBJ = $(FUN:.c=.o)
		
FLAGS = gcc -I -Wall -Wextra -Werror 

MLXFLAG = -lmlx -lXext -lX11

MLX =  ./mlx/minilibx-linux/libmlx.a 
MLX_CC = ./mlx/minilibx-linux
MINILIBX = -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_CC)

$(NAME): $(OBJ) $(MLX) $(INCLUDES) 
	@$(FLAGS) $(FUN) $(MLX) -L$(MLX_CC) -lmlx $(MINILIBX) -o $(NAME)
 	
#-lmlx -lXext -lX11 -lm -lbsd  Posible opción.

clean:
	@rm -f $(OBJS_PRINTF) $(OBJS_LIBFT) *.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	
re: fclean all


# La siguiente línea de compilación funciona : cc Prueba.c -L ./mlx/minilibx-linux/ -lmlx -lXext -lX11 -lm -lbsd