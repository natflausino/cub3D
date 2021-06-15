#include "../../includes/bonus/cub3d_bonus.h"

void	check_horiz(t_game *game, int *horzhit)
{
	double	next_x;
	double	next_y;

	next_x = game->ray.interc_x;
	next_y = game->ray.interc_y;
	while (next_x >= 0 && next_x < (game->block * game->file.map_col)
		&& next_y >= 0 && next_y < (game->block * game->file.map_row))
	{
		if (is_wall(game, next_x, (next_y - game->ray.face_up)) == '1'
			|| is_wall(game, next_x, (next_y - game->ray.face_up)) == '8'
			|| is_wall(game, next_x, (next_y - game->ray.face_up)) == '9')
		{
			hor_door_collider(game, next_x, next_y);
			*horzhit = 1;
			game->ray.hit_hx = next_x;
			game->ray.hit_hy = next_y;
			break ;
		}
		else
		{
			hor_sprite_collider(game, next_x, next_y);
			next_x += game->ray.x_step;
			next_y += game->ray.y_step;
		}
	}
}

void	hor_door_collider(t_game *game, double next_x, double next_y)
{
	if (is_wall(game, next_x, (next_y - game->ray.face_up)) == '8')
		game->door = 1;
	else
		game->door = 0;
}

void	hor_sprite_collider(t_game *game, double next_x, double next_y)
{
	if (is_wall(game, next_x, next_y - game->ray.face_up) >= '2'
		&& is_wall(game, next_x, next_y - game->ray.face_up) <= '6')
		sprite_visible(game, next_x, next_y - game->ray.face_up);
}

void	horz_cast(t_game *game, int *horzhit)
{
	game->ray.interc_y = floor(game->player.y / game->block) * game->block;
	if (game->ray.face_dw)
		game->ray.interc_y += game->block;
	game->ray.interc_x = game->player.x + (game->ray.interc_y - game->player.y)
		/ tan(game->ray.angle);
	game->ray.y_step = game->block;
	if (game->ray.face_up)
		game->ray.y_step *= -1;
	game->ray.x_step = game->block / tan(game->ray.angle);
	if ((game->ray.face_le && game->ray.x_step > 0))
		game->ray.x_step *= -1;
	if ((game->ray.face_ri && game->ray.x_step < 0))
		game->ray.x_step *= -1;
	check_horiz(game, horzhit);
}
