#include "../../includes/bonus/cub3d_bonus.h"

int	close_window(t_game *game)
{
	free_sprites(game);
	free(game->sprite);
	game->sprite = NULL;
	free_textures(game);
	free(game->tex);
	game->tex = NULL;
	free(game->ray.dist_wall);
	game->ray.dist_wall = NULL;
	table_free(game->file.tab);
	game->file.tab = NULL;
	mlx_destroy_image(game->data.mlx, game->data.img);
	mlx_destroy_window(game->data.mlx, game->data.win);
	mlx_destroy_display(game->data.mlx);
	free(game->data.mlx);
	game->data.mlx = NULL;
	exit(0);
	return (0);
}

int	press_key(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	if (key == W)
		game->player.walk_direction = +1;
	if (key == S)
		game->player.walk_direction = -1;
	if (key == A)
		game->player.left_right = +1;
	if (key == D)
		game->player.left_right = -1;
	if (key == RIGHT)
		game->player.turn_direction = +1;
	if (key == LEFT)
		game->player.turn_direction = -1;
	if (key == ALT)
	{
		game->player.walk_speed = 10;
		game->player.turn_speed = 3 * (PI / 180);
	}
	if (key == SHIFT)
		game->open = 1;
	return (0);
}

int	release_key(int key, t_game *game)
{
	if (key == W)
		game->player.walk_direction = 0;
	if (key == S)
		game->player.walk_direction = 0;
	if (key == A)
		game->player.left_right = 0;
	if (key == D)
		game->player.left_right = 0;
	if (key == RIGHT)
		game->player.turn_direction = 0;
	if (key == LEFT)
		game->player.turn_direction = 0;
	if (key == ALT)
	{
		game->player.walk_speed = 5;
		game->player.turn_speed = 1.3 * (PI / 180);
	}
	if (key == SHIFT)
		game->close = 1;
	return (0);
}

void	table_free(char **tab)
{
	int	i;
	int	count;

	count = ft_strlen_ptr(tab);
	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
