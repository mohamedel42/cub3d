# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 10:30:04 by mel-kada          #+#    #+#              #
#    Updated: 2020/12/29 00:08:02 by mel-kada         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

SRCS_LIST = main.c\
			parser.c\
			start.c\
			utils.c\
			parse_resolution.c\
			parse_texture.c\
			parse_color.c\
			parse_map.c\
			check_map.c\
			parse_sprite.c\
			player.c\
			draw.c\
			raycast.c\
			move.c\
			textures.c\
			keys.c\
			sprite.c\
			adjust_map.c\
			math.c\
			exit.c\
			image.c

SRCS_PATH = srcs

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)

CC = gcc
OS_NAME = $(shell uname -s)
MLX_PATH = mlx_linux
MLX_FLAGS = -L $(MLX_PATH) -lX11 -lXext -lmlx -lm -lbsd

MLX_PATH = mlx_linux
MLX_FLAGS = -L $(MLX_PATH) -lX11 -lXext -lmlx -lm -lbsd

LIBFT_FLAGS = -Lsrcs/libft -lft
FLAGS = -g -Wall -Wextra -Werror
INCLUDES = -I mlx -I srcs/libft

all:	$(NAME)

.c.o:
		$(CC) $(INCLUDES) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C $(MLX_PATH)
			make -C srcs/libft
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) ${LIBFT_FLAGS} -L mlx_linux -lmlx -lm -lbsd -lX11 -lXext

clean:
		make -C $(MLX_PATH) clean
		make -C srcs/libft clean
		rm -f $(OBJS)

fclean:	clean
		rm -f srcs/libft/libft.a
		rm -f $(NAME)

re:		fclean
		make all

.PHONY : all clean fclean re
