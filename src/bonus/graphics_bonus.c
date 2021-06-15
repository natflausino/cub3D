#include "../../includes/bonus/cub3d_bonus.h"

void	draw(t_game *game)
{
	cast_all_rays(game);
	if (game->life > 1)
	{
		minimap(game);
		minimap_player(game);
	}
	if (game->init == 1)
	{
		image_create(game);
		exit(0);
	}
}

void	screen_resolution(t_game *game)
{
	int		max_w;
	int		max_h;

	mlx_get_screen_size(game->data.mlx, &max_w, &max_h);
	if (game->file.width > max_w)
		game->file.width = max_w;
	if (game->file.height > max_h)
		game->file.height = max_h;
	if (game->file.width <= 0 || game->file.height <= 0)
		return_error(-20);
}

int	update(t_game *game)
{
	if (game->player.walk_direction || game->player.turn_direction
		|| game->player.left_right)
		move_player(game);
	if (game->init == 0)
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img, 0, 0);
	return (0);
}
