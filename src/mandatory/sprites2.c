#include "../../includes/mandatory/cub3d.h"

void	sort_sprite(t_game *game)
{
	int			i;
	int			j;
	double		temp;

	i = -1;
	while (++i < game->num_sprite - 1)
	{
		j = i;
		if (game->sprite[i].dist < game->sprite[j + 1].dist)
		{
			temp = game->sprite[i].dist;
			game->sprite[i].dist = game->sprite[j + 1].dist;
			game->sprite[j + 1].dist = temp;
			temp = game->sprite[i].visible;
			game->sprite[i].visible = game->sprite[j + 1].visible;
			game->sprite[j + 1].visible = temp;
			temp = game->sprite[i].pos.x;
			game->sprite[i].pos.x = game->sprite[j + 1].pos.x;
			game->sprite[j + 1].pos.x = temp;
			temp = game->sprite[i].pos.y;
			game->sprite[i].pos.y = game->sprite[j + 1].pos.y;
			game->sprite[j + 1].pos.y = temp;
			i = -1;
		}
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
			game->sprite[i].visible = 1;
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
			if (game->file.tab[i][j] == '2')
			{
				game->sprite[k].pos.x = (j * game->block) + (game->block / 2);
				game->sprite[k].pos.y = (i * game->block) + (game->block / 2);
				game->sprite[k].dist = dist2points(game->sprite[k].pos.x,
						game->sprite[k].pos.y, game->player.x, game->player.y);
				game->sprite[k].visible = 0;
				k++;
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
			if (game->file.tab[i][j] == '2')
				s_count++;
			j++;
		}
		i++;
	}
	game->num_sprite = s_count;
}
