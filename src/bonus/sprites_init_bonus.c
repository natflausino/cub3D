#include "../../includes/bonus/cub3d_bonus.h"

void	find_sprite_init(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < game->file.map_row)
	{
		j = -1;
		while (++j < game->file.map_col)
		{
			if (game->file.tab[i][j] >= '2' && game->file.tab[i][j] <= '6')
				find_sprite_2_init(game, i, j, &k);
		}
	}
}

void	find_sprite_2_init(t_game *game, int i, int j, int *k)
{
	game->sprite[*k].index = game->file.tab[i][j] - '0';
	game->sprite[*k].pos.x = (j * game->block) + (game->block / 2);
	game->sprite[*k].pos.y = (i * game->block) + (game->block / 2);
	game->sprite[*k].dist = dist2points(game->sprite[*k].pos.x,
			game->sprite[*k].pos.y, game->player.x, game->player.y);
	game->sprite[*k].visible = 0;
	(*k)++;
}
