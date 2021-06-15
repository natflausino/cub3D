#include "../../includes/mandatory/cub3d.h"

double	normalize_angle(double angle)
{
	double	norm_angle;

	norm_angle = remainder(angle, 2 * PI);
	if (norm_angle < 0)
	{
		norm_angle = (2 * PI) + norm_angle;
	}
	return (norm_angle);
}

void	move_player(t_game *game)
{
	double	move_ws;
	double	move_ad;
	double	px;
	double	py;

	px = game->player.x;
	py = game->player.y;
	game->player.rotation_angle = normalize_angle(game->player.rotation_angle);
	game->player.rotation_angle += game->player.turn_direction
		* game->player.turn_speed;
	move_ws = game->player.walk_direction * game->player.walk_speed;
	move_ad = game->player.left_right * game->player.walk_speed;
	px = game->player.x + (cos(game->player.rotation_angle) * move_ws);
	py = game->player.y + (sin(game->player.rotation_angle) * move_ws);
	px = px + cos(game->player.rotation_angle - (90 * PI / 180)) * move_ad;
	py = py + sin(game->player.rotation_angle - (90 * PI / 180)) * move_ad;
	ray_facing(game, game->player.rotation_angle);
	if (check_wall(game, px, game->player.y) != 1)
		game->player.x = px;
	if (check_wall(game, game->player.x, py) != 1)
		game->player.y = py;
	draw(game);
}

void	player_position(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game->file.tab[i])
	{
		j = 0;
		while (game->file.tab[i][j])
		{
			if (game->file.tab[i][j] == 'N' || game->file.tab[i][j] == 'E'
				|| game->file.tab[i][j] == 'W' || game->file.tab[i][j] == 'S')
			{
				if (game->file.player_found == 1)
					return_free_error(-19, game->file.tab);
				game->player.x = j * game->block + (game->block / 2);
				game->player.y = i * game->block + (game->block / 2);
				game->file.player_found = 1;
			}
			j++;
		}
		i++;
	}
	if (game->file.player_found == 0)
		return_free_error(-19, game->file.tab);
}

void	player_facing(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x / game->block;
	y = game->player.y / game->block;
	if (game->file.tab[y][x] == 'N')
	{
		game->player.rotation_angle = 270 * PI / 180;
		game->file.tab[y][x] = '0';
	}
	if (game->file.tab[y][x] == 'S')
	{
		game->player.rotation_angle = 90 * PI / 180;
		game->file.tab[y][x] = '0';
	}
	if (game->file.tab[y][x] == 'E')
	{
		game->player.rotation_angle = 0;
		game->file.tab[y][x] = '0';
	}
	if (game->file.tab[y][x] == 'W')
	{
		game->player.rotation_angle = PI;
		game->file.tab[y][x] = '0';
	}
}
