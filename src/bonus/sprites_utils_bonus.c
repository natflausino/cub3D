#include "../../includes/bonus/cub3d_bonus.h"

void	find_sprite_2_aux(t_game *game, int i, int j)
{
	game->life--;
	game->sprite->damage = 0;
	game->file.tab[i][j] = '0';
	game->num_sprite--;
	if (game->life == 0)
		close_window(game);
}

void	find_sprite_3(t_game *game, int i, int j)
{
	game->life++;
	game->sprite->cure = 0;
	game->file.tab[i][j] = '0';
	game->num_sprite--;
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
	game->file.tab[i][j] = '6';
}
