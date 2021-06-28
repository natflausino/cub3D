#include "../../includes/mandatory/cub3d.h"

void	check_horiz(t_game *game, int *horzhit)
{
	double	next_x;
	double	next_y;

	next_x = game->ray.interc_x;
	next_y = game->ray.interc_y;
	while (next_x >= 0 && next_x < (game->block * game->file.map_col)
		&& next_y >= 0 && next_y < (game->block * game->file.map_row))
	{
		if (is_wall(game, next_x, (next_y - game->ray.face_up)) == '1')
		{
			*horzhit = 1;
			game->ray.hit_hx = next_x;
			game->ray.hit_hy = next_y;
			break ;
		}
		else
		{
			if (is_wall(game, next_x, next_y - game->ray.face_up) == '2')
				sprite_visible(game, next_x, next_y - game->ray.face_up);
			next_x += game->ray.x_step;
			next_y += game->ray.y_step;
		}
	}
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

void	check_vert(t_game *game, int *verthit)
{
	double	next_x;
	double	next_y;

	next_x = game->ray.interc_x;
	next_y = game->ray.interc_y;
	while (next_x >= 0 && next_x < (game->block * game->file.map_col)
		&& next_y >= 0 && next_y < (game->block * game->file.map_row))
	{
		if (is_wall(game, (next_x - game->ray.face_le), next_y) == '1')
		{
			*verthit = 1;
			game->ray.hit_vx = next_x;
			game->ray.hit_vy = next_y;
			break ;
		}
		else
		{
			if (is_wall(game, next_x - game->ray.face_le, next_y) == '2')
				sprite_visible(game, next_x - game->ray.face_le, next_y);
			next_x += game->ray.x_step;
			next_y += game->ray.y_step;
		}
	}
}

void	vert_cast(t_game *game, int *verthit)
{
	game->ray.interc_x = floor(game->player.x / game->block) * game->block;
	if (game->ray.face_ri)
		game->ray.interc_x += game->block;
	game->ray.interc_y = game->player.y + (game->ray.interc_x - game->player.x)
		* tan(game->ray.angle);
	game->ray.x_step = game->block;
	if (game->ray.face_le)
		game->ray.x_step *= -1;
	game->ray.y_step = game->block * tan(game->ray.angle);
	if ((game->ray.face_up && game->ray.y_step > 0)
		|| (game->ray.face_dw && game->ray.y_step < 0))
		game->ray.y_step *= -1;
	check_vert(game, verthit);
}

double	dist2points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
