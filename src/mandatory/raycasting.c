#include "../../includes/mandatory/cub3d.h"

void	dist2wall(t_game *game, double horz_dist, double vert_dist)
{
	game->ray.was_hit_v = 0;
	if (horz_dist < vert_dist)
	{
		game->ray.wall_dist = horz_dist;
		game->ray.wall_hitx = game->ray.hit_hx;
		game->ray.wall_hity = game->ray.hit_hy;
	}
	else
	{
		game->ray.wall_dist = vert_dist;
		game->ray.wall_hitx = game->ray.hit_vx;
		game->ray.wall_hity = game->ray.hit_vy;
		game->ray.was_hit_v = 1;
	}
}

void	find_dist(t_game *game, int horz_hit, int vert_hit)
{
	double	horz_dist;
	double	vert_dist;

	if (horz_hit)
		horz_dist = dist2points(game->player.x, game->player.y,
				game->ray.hit_hx, game->ray.hit_hy);
	else
		horz_dist = __INT_MAX__;
	if (vert_hit)
		vert_dist = dist2points(game->player.x, game->player.y,
				game->ray.hit_vx, game->ray.hit_vy);
	else
		vert_dist = __INT_MAX__;
	dist2wall(game, horz_dist, vert_dist);
}

void	ray_facing(t_game *game, double ray)
{
	game->ray.face_dw = 0;
	game->ray.face_up = 0;
	game->ray.face_ri = 0;
	game->ray.face_le = 0;
	if (ray > 0 && ray < PI)
	{
		game->ray.face_dw = 1;
	}
	if (!game->ray.face_dw)
	{
		game->ray.face_up = 1;
	}
	if (ray < 0.5 * PI || ray > 1.5 * PI)
	{
		game->ray.face_ri = 1;
	}
	if (!game->ray.face_ri)
	{
		game->ray.face_le = 1;
	}
}

void	raycast(t_game *game, double rayangle)
{
	int	horzhit;
	int	verthit;

	horzhit = 0;
	verthit = 0;
	game->ray.angle = normalize_angle(rayangle);
	ray_facing(game, game->ray.angle);
	horz_cast(game, &horzhit);
	vert_cast(game, &verthit);
	game->ray.was_hit_v = 0;
	find_dist(game, horzhit, verthit);
}

void	cast_all_rays(t_game *game)
{
	int		walls;
	double	rayangle;
	double	incstep;
	int		i;

	walls = game->file.width;
	rayangle = normalize_angle(game->player.rotation_angle - PI / 6.);
	incstep = PI / 3. / (double)walls;
	i = 0;
	find_sprite(game);
	while (i < walls)
	{
		rayangle = game->player.rotation_angle + atan((i - (walls / 2))
				/ game->dist2player);
		raycast(game, rayangle);
		game->ray.dist_wall[i] = game->ray.wall_dist;
		render_projection_walls(game, i);
		i++;
	}
	render_sprite(game);
}
