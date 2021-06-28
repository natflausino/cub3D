#include "../../includes/mandatory/cub3d.h"

void	sprite_height(t_game *game, int *start, int *end, int *i)
{
	if (*end - *start >= game->file.height)
	{
		*i += -(*start);
		*start = 0;
		*end = game->file.height;
	}
}

void	draw_sprite(t_game *game, int x, int s_pos, int sp)
{
	int		i;
	int		color;
	int		y;
	int		start;
	int		end;

	i = 0;
	y = 0;
	start = game->file.height / 2 - game->s_hei / 2;
	end = game->file.height / 2 + game->s_hei / 2;
	sprite_height(game, &start, &end, &i);
	while (start < end)
	{
		y = i * (double)game->tex[SP].tex_height / (double)game->s_hei;
		color = game->tex[SP].addr[y * game->tex[SP].tex_width
			+ (int)(x * (double)game->tex[SP].tex_height
				/ (double)game->s_hei)];
		if (color > 0x00ff00)
			if (s_pos + x >= 0 && s_pos + x < game->file.width)
				if (game->ray.dist_wall[x + s_pos] > game->sprite[sp].dist)
					game->data.addr[start * game->file.width + x + s_pos]
						= color;
		i++;
		start++;
	}
}

void	set_sprite(t_game *game, int i, int *s_pos)
{
	int	height;

	game->sprite[i].dist = game->sprite[i].dist * cos(game->sprite[i].angle
			- game->player.rotation_angle) + (game->block / 4);
	game->s_hei = (game->block / game->sprite[i].dist) * game->dist2player;
	height = game->s_hei;
	*s_pos = (tan(game->fov / 2) * game->dist2player)
		+ (tan(game->sprite[i].angle - game->player.rotation_angle)
			* game->dist2player) - (height / 2);
}

void	sprite_param(t_game *game)
{
	int	i;
	int	x;
	int	s_pos;

	i = 0;
	while (i < game->num_sprite)
	{
		if ((game->sprite[i].visible == 1)
			&& (cos(game->sprite[i].angle - game->player.rotation_angle) > 0))
		{
			x = 0;
			set_sprite(game, i, &s_pos);
			while ((x < game->s_hei) && (x + s_pos < game->file.width))
			{
				if (x + s_pos >= 0)
					draw_sprite(game, x, s_pos, i);
				x++;
			}
		}
		i++;
	}
}

void	sprite_angle(t_game *game)
{
	double	s_angle;
	double	x;
	double	y;
	int		i;

	i = 0;
	while (i < game->num_sprite)
	{
		s_angle = 0;
		x = game->sprite[i].pos.x - game->player.x;
		y = game->sprite[i].pos.y - game->player.y;
		s_angle = atan2(y, x);
		if (s_angle <= 0.)
			game->sprite[i].angle = (PI * 2) + s_angle;
		else
			game->sprite[i].angle = s_angle;
		game->sprite[i].angle = normalize_angle(game->sprite[i].angle);
		i++;
	}
}
