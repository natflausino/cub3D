#include "../../includes/bonus/cub3d_bonus.h"

void	draw_strip(t_game *game, int x, int side, int strip_height)
{
	int		color;
	int		i;
	int		x_tex;
	int		y_tex;
	int		start;

	i = 0;
	start = (game->file.height / 2) - (strip_height / 2);
	game->end = (game->file.height / 2) + (strip_height / 2);
	calculate_texture(game, &x_tex, side);
	if ((game->end - start) >= game->file.height)
	{
		i += -start;
		start = 0;
		game->end = game->file.height;
	}
	while (start < game->end)
	{
		y_tex = i * game->tex[side].tex_height / (double)strip_height;
		color = game->tex[WALL].addr[y_tex * game->tex[side].tex_width + x_tex];
		color = special_wall(game, color);
		game->data.addr[start * game->file.width + x] = color;
		i++;
		start++;
	}
}

void	render_projection_walls(t_game *game, int i)
{
	double	ray_dist;
	double	wall_height;
	double	true_dist;

	ray_dist = game->ray.wall_dist;
	true_dist = ray_dist * cos(game->ray.angle - game->player.rotation_angle);
	game->dist2player = (game->file.width / 2) / tan(game->fov / 2);
	wall_height = (double)(game->block / true_dist) *game->dist2player;
	color_floor_ceiling(game, wall_height, i);
	texture_select(game);
	texture_ident(game);
	draw_strip(game, i, game->ident, round(wall_height));
}

void	color_floor_ceiling(t_game *game, double wall_height, int i)
{
	int		j;
	int		color;
	double	start;
	int		end;

	start = (game->file.height / 2) - (wall_height / 2);
	end = (game->file.height / 2) + (wall_height / 2);
	j = 0;
	while (j < start)
	{
		color = game->file.color_ceiling;
		color = special_ceiling(game, color);
		if (j * game->file.width + i > 0)
			game->data.addr[j * game->file.width + i] = color;
		j++;
	}
	j = end;
	floor_texture(game, i, j, wall_height);
}

void	floor_texture(t_game *game, int i, int j, double wall_height)
{
	int		x_tex;
	int		y_tex;
	int		color;

	calculate_texture(game, &x_tex, F_TEX);
	while (j < game->file.height)
	{
		y_tex = j * game->tex[F_TEX].tex_height / (double)wall_height;
		color = game->tex[F_TEX].addr[(int)(x_tex
				* game->tex[F_TEX].tex_height + y_tex)];
		color = special_floor(game, color);
		if (color > 0x00ff00)
			game->data.addr[j * game->file.width + i] = color;
		j++;
	}
}
