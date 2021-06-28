#include "../../includes/bonus/cub3d_bonus.h"

void	sort_sprite(t_game *game)
{
	int			i;
	t_sprite	temp;

	i = 0;
	while (++i < game->num_sprite - 1)
	{
		if (game->sprite[i].dist < game->sprite[i + 1].dist)
		{
			temp = game->sprite[i];
			game->sprite[i] = game->sprite[i + 1];
			game->sprite[i + 1] = temp;
		}
		i++;
	}
}

void	sprite_visible(t_game *game, int x, int y)
{
	int	i;
	int	dist_x;
	int	dist_y;

	i = 0;
	while (i < game->num_sprite)
	{
		dist_x = x / game->block;
		dist_y = y / game->block;
		if ((dist_x == (int)game->sprite[i].pos.x / game->block)
			&& (dist_y == (int)game->sprite[i].pos.y / game->block))
		{
			game->sprite[i].action = 1;
			game->sprite[i].visible = 1;
		}
		i++;
	}
}

void	find_sprite(t_game *game)
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
			if (game->file.tab[i][j] >= '2' && game->file.tab[i][j] <= '5')
				find_sprite_2(game, i, j, &k);
			if (game->file.tab[i][j] == '3' && game->sprite->damage == 1)
				find_sprite_2_aux(game, i, j);
			if (game->file.tab[i][j] == '4' && game->sprite->cure == 1)
				find_sprite_3(game, i, j);
			if (game->file.tab[i][j] == '8' && game->open == 1)
				find_sprite_3_aux(game, i, j);
			if (game->file.tab[i][j] == '7' && game->close == 1)
				find_sprite_3_aux1(game, i, j);
			if (game->file.tab[i][j] == '5' && game->sprite->win == 1)
				find_sprite_4(game, i, j);
		}
	}
}

void	find_sprite_2(t_game *game, int i, int j, int *k)
{
	game->sprite[*k].dist = dist2points(game->sprite[*k].pos.x,
			game->sprite[*k].pos.y, game->player.x, game->player.y);
	game->sprite[*k].visible = 0;
	(*k)++;
}
