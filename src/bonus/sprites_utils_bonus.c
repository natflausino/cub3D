#include "../../includes/bonus/cub3d_bonus.h"

void	find_sprite_2_aux(t_game *game, int i, int j)
{
	if (game->weapon == 0 && game->item != 6)
	{
		if (game->life > 0)
			game->life--;
		game->sprite->damage = 0;
		game->file.tab[i][j] = '0';
		game->num_sprite--;
	}
	else if (game->weapon == 1 && game->item != 6)
	{
		game->sprite->damage = 0;
		game->file.tab[i][j] = '0';
		game->num_sprite--;
	}
}

void	find_sprite_3(t_game *game, int i, int j)
{
	if (game->life < 3 && game->life > 0)
	{
		game->life++;
		game->sprite->cure = 0;
		game->file.tab[i][j] = '0';
		game->num_sprite--;
	}
}

void	find_sprite_3_aux(t_game *game, int i, int j)
{
	game->file.tab[i][j] = '7';
	game->close = 0;
}

void	find_sprite_3_aux1(t_game *game, int i, int j)
{
	game->file.tab[i][j] = '8';
	game->open = 0;
}

void	find_sprite_4(t_game *game, int i, int j)
{
	if (game->item < 6 && game->life > 0)
	{
		game->file.tab[i][j] = '0';
		game->sprite->win = 0;
		game->num_sprite--;
		game->item++;
	}
}
