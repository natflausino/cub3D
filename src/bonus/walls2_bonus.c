#include "../../includes/bonus/cub3d_bonus.h"

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
	if ((is_wall(game, x - dist, y - dist) >= '1'
			&& is_wall(game, x - dist, y - dist) <= '2')
		|| (is_wall(game, x + dist, y - dist) >= '1'
			&& is_wall(game, x + dist, y - dist) <= '2')
		|| (is_wall(game, x - dist, y + dist) >= '1'
			&& is_wall(game, x - dist, y + dist) <= '2')
		|| (is_wall(game, x + dist, y + dist) >= '1'
			&& is_wall(game, x + dist, y + dist) <= '2'))
		result = 1;
	effect(game, x, y, dist);
	if (is_wall(game, x - dist, y - dist) == '8'
		|| is_wall(game, x + dist, y - dist) == '8'
		|| is_wall(game, x - dist, y + dist) == '8'
		|| is_wall(game, x + dist, y + dist) == '8')
		result = door(game, x, y, dist);
	return (result);
}

int	door(t_game *game, int x, int y, int dist)
{
	int	result;

	if (game->open == 1)
		result = 0;
	else
		result = 1;
	return (result);
}
