#include "../../includes/mandatory/cub3d.h"

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
	color = 0;
	while (start < game->end)
	{
		y_tex = i * game->tex[side].tex_height / (double)strip_height;
		color = game->tex[WALL].addr[y_tex * game->tex[side].tex_width + x_tex];
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

int	is_wall(t_game *game, int x, int y)
{
	int	block_size;
	int	x_map;
	int	y_map;

	block_size = game->block;
	x_map = (x / block_size);
	y_map = (y / block_size);
	return (game->file.tab[y_map][x_map]);
}

int	check_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;
	int	dist;
	int	result;

	x = new_x;
	y = new_y;
	dist = (game->block / 8);
	result = 0;
	if (is_wall(game, x - dist, y - dist) == '1'
		|| is_wall(game, x - dist, y - dist) == '2')
		result = 1;
	if (is_wall(game, x + dist, y - dist) == '1'
		|| is_wall(game, x + dist, y - dist) == '2')
		result = 1;
	if (is_wall(game, x - dist, y + dist) == '1'
		|| is_wall(game, x - dist, y + dist) == '2')
		result = 1;
	if (is_wall(game, x + dist, y + dist) == '1'
		|| is_wall(game, x + dist, y + dist) == '2')
		result = 1;
	return (result);
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
		if (j * game->file.width + i > 0)
			game->data.addr[j * game->file.width + i] = color;
		j++;
	}
	j = end;
	while (j < game->file.height)
	{
		color = game->file.color_floor;
		if (j * game->file.width + i > 0)
			game->data.addr[j * game->file.width + i] = color;
		j++;
	}
}
