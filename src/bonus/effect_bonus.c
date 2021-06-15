#include "../../includes/bonus/cub3d_bonus.h"

void	damage_cure(t_game *game, int x, int y, int dist)
{
	if (is_wall(game, x - dist, y - dist) == '3'
		|| is_wall(game, x + dist, y - dist) == '3'
		|| is_wall(game, x - dist, y + dist) == '3'
		|| is_wall(game, x + dist, y + dist) == '3')
		game->sprite->damage = 1;
	if (is_wall(game, x - dist, y - dist) == '4'
		|| is_wall(game, x + dist, y - dist) == '4'
		|| is_wall(game, x - dist, y + dist) == '4'
		|| is_wall(game, x + dist, y + dist) == '4')
		game->sprite->cure = 1;
}

void	win(t_game *game, int x, int y, int dist)
{
	if (is_wall(game, x - dist, y - dist) == '5'
		|| is_wall(game, x + dist, y - dist) == '5'
		|| is_wall(game, x - dist, y + dist) == '5'
		|| is_wall(game, x + dist, y + dist) == '5')
		game->sprite->win = 1;
}

void	effect(t_game *game, int x, int y, int dist)
{
	damage_cure(game, x, y, dist);
	win(game, x, y, dist);
}
