#include "../../includes/bonus/cub3d_bonus.h"

int	special_wall(t_game *game, int color)
{
	if (game->life == 1)
		color = 0xb48c36;
	if (game->life == 0)
		color = 0x3f403f;
	if (game->item == 6 && game->life != 0)
		color = 0xffce66;
	return (color);
}

int	special_floor(t_game *game, int color)
{
	if (game->life == 1)
		color = 0x0a0a0a;
	if (game->life == 0)
		color = 0x0a0a0a;
	if (game->item == 6 && game->life != 0)
		color = 0x3f1a04;
	return (color);
}

int	special_ceiling(t_game *game, int color)
{
	if (game->life == 1)
		color = 0x000000;
	if (game->life == 0)
		color = 0x000000;
	if (game->item == 6 && game->life != 0)
		color = 0x36b0b4;
	return (color);
}
