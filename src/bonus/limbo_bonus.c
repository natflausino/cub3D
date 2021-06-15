#include "../../includes/bonus/cub3d_bonus.h"

int	limbo_floor(t_game *game, int color)
{
	if (game->life <= 1)
		color = 0x32135F;
	return (color);
}

int	limbo_wall(t_game *game, int color)
{
	if (game->life <= 1)
		color = 0x4D2277;
	return (color);
}

int	limbo_ceiling(t_game *game, int color)
{
	if (game->life <= 1)
		color = 0x4e4950;
	return (color);
}
