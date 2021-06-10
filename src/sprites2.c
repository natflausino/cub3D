#include "../includes/cub3d.h"

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

void	render_sprite(t_game *game)
{
	sort_sprite(game);
	sprite_angle(game);
	sprite_param(game);
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

	i = 0;
	k = 0;
	while (i < game->file.map_row)
	{
		j = 0;
		while (j < game->file.map_col)
		{
			if (game->file.tab[i][j] >= '2' && game->file.tab[i][j] <= '4')
			{
				game->sprite[k].index = game->file.tab[i][j] - '0';
				game->sprite[k].pos.x = (j * game->block) + (game->block / 2);
				game->sprite[k].pos.y = (i * game->block) + (game->block / 2);
				game->sprite[k].dist = dist2points(game->sprite[k].pos.x,
						game->sprite[k].pos.y, game->player.x, game->player.y);
				game->sprite[k].visible = 0;
				k++;
			}
			if (game->file.tab[i][j] == '3' && game->sprite->damage == 1)
			{
				game->life--;
				game->sprite->damage = 0;
				game->file.tab[i][j] = '0';
				game->num_sprite--;
				if (game->life == 0)
					close_window(game);
			}
			if (game->file.tab[i][j] == '4' && game->sprite->cure == 1)
			{
				game->life++;
				game->sprite->cure = 0;
				game->file.tab[i][j] = '0';
				game->num_sprite--;
			}
			if (game->file.tab[i][j] == '8' && game->open == 1)
			{
				game->file.tab[i][j] = '7';
				game->close = 0;
			}
			if (game->file.tab[i][j] == '7' && game->close == 1)
			{
				game->file.tab[i][j] = '8';
				game->open = 0;
			}
			j++;
		}
		i++;
	}
}

void	num_sprites(t_game *game)
{
	int	i;
	int	j;
	int	s_count;

	s_count = 0;
	i = 0;
	while (i < game->file.map_row)
	{
		j = 0;
		while (j < game->file.map_col)
		{
			if (game->file.tab[i][j] >= '2'
				&& game->file.tab[i][j] <= '4')
				s_count++;
			j++;
		}
		i++;
	}
	game->num_sprite = s_count;
}
