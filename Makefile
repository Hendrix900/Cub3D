# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 09:37:57 by ccastill          #+#    #+#              #
#    Updated: 2020/09/29 01:54:24 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDES = cub3d.h ./lib/libft/libft.h ./lib/mlx/minilibx-linux/mlx.h

FUN = Prueba.c \

OBJ = $(FUN:.c=.o)
		
FLAGS = gcc -I -Wall -Wextra -Werror 

MLX =  ./lib//mlx/minilibx-linux/libmlx.a 
MLX_CC = ./lib//mlx/minilibx-linux
MINILIBX = -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(LIBFT): 
	@$(MAKE) -C ./lib/libft/
	
$(MLX):
	@$(MAKE) -C $(MLX_CC)

$(NAME): $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) 
	@$(FLAGS) $(FUN) $(LIBFT) $(MLX) -Lsrcs/libft -L$(MLX_CC) -lmlx $(MINILIBX) -o $(NAME)
 	
#-lmlx -lXext -lX11 -lm -lbsd  Posible opción.

clean:
	@rm -f $(OBJS) *.o ./lib/libft/*.o ./lib/Get_next_line/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	
re: fclean all


# La siguiente línea de compilación funciona : cc Prueba.c -L ./mlx/minilibx-linux/ -lmlx -lXext -lX11 -lm -lbsd