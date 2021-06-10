# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:45:31 by sbertali          #+#    #+#              #
#    Updated: 2021/05/11 21:35:16 by sbertali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX = libmlx.a
LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = libft
MLX_PATH = minilibx-linux

MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
SRC_PATH = ./src/

INCLUDES = -I includes

CC = clang
FLAGS = -Wall -Wextra -Werror
SANITIZE = @$(CC) $(FLAGS) -w -g -fsanitize=address -o $(NAME) $(OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)

SRC =	$(SRC_PATH)cub3d.c\
		$(SRC_PATH)bitmap.c\
		$(SRC_PATH)events.c\
		$(SRC_PATH)parsing_color.c\
		$(SRC_PATH)parsing_file.c\
		$(SRC_PATH)parsing_map.c\
		$(SRC_PATH)parsing.c\
		$(SRC_PATH)player.c\
		$(SRC_PATH)raycasting.c\
		$(SRC_PATH)raycasting2.c\
		$(SRC_PATH)sprites.c\
		$(SRC_PATH)sprites2.c\
		$(SRC_PATH)textures.c\
		$(SRC_PATH)utils.c\
		$(SRC_PATH)walls.c\
		$(SRC_PATH)error.c

OBJECTS = cub3d.o\
		bitmap.o\
		events.o\
		parsing_color.o\
		parsing_file.o\
		parsing_map.o\
		parsing.o\
		player.o\
		raycasting.o\
		raycasting2.o\
		sprites.o\
		sprites2.o\
		textures.o\
		utils.o\
		walls.o\
		error.o

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	@$(CC) $(FLAGS) -w -g -o $(NAME) $(OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJECTS): $(SRC_PATH) $(SRC)
	@$(CC) $(FLAGS) -w -g -c $(SRC)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS) $(NAME)

fclean:
	@rm -f $(NAME)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(OBJECTS) $(NAME) screen_shot.bmp

re: fclean all

san: all
	@$(SANITIZE)

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes