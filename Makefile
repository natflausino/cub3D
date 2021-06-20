NAME = cub3D

MLX = libmlx.a
LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = ./libraries/libft
MLX_PATH = ./libraries/minilibx-linux

MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
SRC_PATH = ./src/mandatory/
SRC_BONUS = ./src/bonus/

INCLUDES = -I includes

CC = clang
FLAGS = -Wall -Wextra -Werror
SANITIZE = @$(CC) $(FLAGS) -w -g -fsanitize=address -o $(NAME) $(OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)

SRC =	$(SRC_PATH)bitmap.c\
		$(SRC_PATH)cub3d.c\
		$(SRC_PATH)error.c\
		$(SRC_PATH)events.c\
		$(SRC_PATH)get_param.c\
		$(SRC_PATH)graphics.c\
		$(SRC_PATH)parsing_color.c\
		$(SRC_PATH)parsing_file.c\
		$(SRC_PATH)parsing_map.c\
		$(SRC_PATH)parsing_map2.c\
		$(SRC_PATH)player.c\
		$(SRC_PATH)raycasting.c\
		$(SRC_PATH)raycasting2.c\
		$(SRC_PATH)sprites.c\
		$(SRC_PATH)sprites2.c\
		$(SRC_PATH)textures.c\
		$(SRC_PATH)walls.c

OBJECTS = bitmap.o\
		cub3d.o\
		error.o\
		events.o\
		get_param.o\
		graphics.o\
		parsing_color.o\
		parsing_file.o\
		parsing_map.o\
		parsing_map2.o\
		player.o\
		raycasting.o\
		raycasting2.o\
		sprites.o\
		sprites2.o\
		textures.o\
		walls.o

BONUS_FILES = $(SRC_BONUS)bitmap_bonus.c\
			$(SRC_BONUS)cub3d_bonus.c\
			$(SRC_BONUS)effect_bonus.c\
			$(SRC_BONUS)error_bonus.c\
			$(SRC_BONUS)events_bonus.c\
			$(SRC_BONUS)get_param_bonus.c\
			$(SRC_BONUS)graphics_bonus.c\
			$(SRC_BONUS)limbo_bonus.c\
			$(SRC_BONUS)minimap_bonus.c\
			$(SRC_BONUS)parsing_color_bonus.c\
			$(SRC_BONUS)parsing_file_bonus.c\
			$(SRC_BONUS)parsing_map_bonus.c\
			$(SRC_BONUS)parsing_map2_bonus.c\
			$(SRC_BONUS)player_bonus.c\
			$(SRC_BONUS)raycasting_bonus.c\
			$(SRC_BONUS)raycasting2_bonus.c\
			$(SRC_BONUS)raycasting3_bonus.c\
			$(SRC_BONUS)sprites_bonus.c\
			$(SRC_BONUS)sprites_init_bonus.c\
			$(SRC_BONUS)sprites_utils_bonus.c\
			$(SRC_BONUS)sprites2_bonus.c\
			$(SRC_BONUS)sprites3_bonus.c\
			$(SRC_BONUS)textures_bonus.c\
			$(SRC_BONUS)textures2_bonus.c\
			$(SRC_BONUS)walls_bonus.c\
			$(SRC_BONUS)walls2_bonus.c

BONUS_OBJECTS = bitmap_bonus.o\
			cub3d_bonus.o\
			effect_bonus.o\
			error_bonus.o\
			events_bonus.o\
			get_param_bonus.o\
			graphics_bonus.o\
			limbo_bonus.o\
			minimap_bonus.o\
			parsing_color_bonus.o\
			parsing_file_bonus.o\
			parsing_map_bonus.o\
			parsing_map2_bonus.o\
			player_bonus.o\
			raycasting_bonus.o\
			raycasting2_bonus.o\
			raycasting3_bonus.o\
			sprites_bonus.o\
			sprites_init_bonus.o\
			sprites_utils_bonus.o\
			sprites2_bonus.o\
			sprites3_bonus.o\
			textures_bonus.o\
			textures2_bonus.o\
			walls_bonus.o\
			walls2_bonus.o\


all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	@$(CC) $(FLAGS) -w -g -o $(NAME) $(OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)

bonus: $(BONUS_OBJECTS) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) -w -g -o $(NAME) $(BONUS_OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJECTS): $(SRC_PATH) $(SRC)
	@$(CC) $(FLAGS) -w -g -c $(SRC)

$(BONUS_OBJECTS): $(SRC_BONUS) $(BONUS_FILES)
	@$(CC) $(FLAGS) -w -g -c $(BONUS_FILES)

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@rm -f $(BONUS_OBJECTS)

fclean:
	@rm -f $(NAME)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(OBJECTS) $(NAME) screen_shot.bmp
	@rm -f $(BONUS_OBJECTS) $(NAME) screen_shot.bmp

re: fclean all

rebonus: fclean bonus

san: all
	@$(SANITIZE)

rs: fclean all
	@$(SANITIZE)

.PHONY:		all clean fclean re bonus rebonus

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes