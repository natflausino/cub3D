#include "../../includes/mandatory/cub3d.h"

void	texture_select(t_game *game)
{
	if (game->ray.was_hit_v == 0 && game->ray.face_up)
		game->tex[WALL].addr = (int *)mlx_get_data_addr(game->tex[S_TEX].img,
				&game->tex[S_TEX].bpp, &game->tex[S_TEX].l_len,
				&game->tex[S_TEX].endian);
	if (game->ray.was_hit_v == 0 && game->ray.face_dw)
		game->tex[WALL].addr = (int *)mlx_get_data_addr(game->tex[N_TEX].img,
				&game->tex[N_TEX].bpp, &game->tex[N_TEX].l_len,
				&game->tex[N_TEX].endian);
	if (game->ray.was_hit_v == 1 && game->ray.face_ri)
		game->tex[WALL].addr = (int *)mlx_get_data_addr(game->tex[W_TEX].img,
				&game->tex[W_TEX].bpp, &game->tex[W_TEX].l_len,
				&game->tex[W_TEX].endian);
	if (game->ray.was_hit_v == 1 && game->ray.face_le)
		game->tex[WALL].addr = (int *)mlx_get_data_addr(game->tex[E_TEX].img,
				&game->tex[E_TEX].bpp, &game->tex[E_TEX].l_len,
				&game->tex[E_TEX].endian);
}

void	texture_ident(t_game *game)
{
	if (game->ray.was_hit_v == 0 && game->ray.face_up)
		game->ident = S_TEX;
	if (game->ray.was_hit_v == 0 && game->ray.face_dw)
		game->ident = N_TEX;
	if (game->ray.was_hit_v == 1 && game->ray.face_ri)
		game->ident = W_TEX;
	if (game->ray.was_hit_v == 1 && game->ray.face_le)
		game->ident = E_TEX;
}

void	free_textures(t_game *game)
{
	if (game->file.no_path)
		free(game->file.no_path);
	if (game->file.so_path)
		free(game->file.so_path);
	if (game->file.ea_path)
		free(game->file.ea_path);
	if (game->file.we_path)
		free(game->file.we_path);
	if (game->file.s_path)
		free(game->file.s_path);
}

void	texture_load(t_game *game)
{
	game->tex[N_TEX].img = mlx_xpm_file_to_image(game->data.mlx,
			game->file.no_path, &game->tex[N_TEX].tex_width,
			&game->tex[N_TEX].tex_height);
	game->tex[S_TEX].img = mlx_xpm_file_to_image(game->data.mlx,
			game->file.so_path, &game->tex[S_TEX].tex_width,
			&game->tex[S_TEX].tex_height);
	game->tex[E_TEX].img = mlx_xpm_file_to_image(game->data.mlx,
			game->file.ea_path, &game->tex[E_TEX].tex_width,
			&game->tex[E_TEX].tex_height);
	game->tex[W_TEX].img = mlx_xpm_file_to_image(game->data.mlx,
			game->file.we_path, &game->tex[W_TEX].tex_width,
			&game->tex[W_TEX].tex_height);
	game->tex[SP].img = mlx_xpm_file_to_image(game->data.mlx,
			game->file.s_path, &game->tex[SP].tex_width,
			&game->tex[SP].tex_height);
	game->tex[SP].addr = (int *)mlx_get_data_addr(game->tex[SP].img,
			&game->tex[SP].bpp, &game->tex[SP].l_len, &game->tex[SP].endian);
}

void	calculate_texture(t_game *game, int *x_tex, int side)
{
	double	step_x;

	step_x = ((double)game->tex[side].tex_width / (double)game->block);
	if (game->ray.was_hit_v == 0)
	{
		*x_tex = (int)game->ray.wall_hitx % game->block;
	}
	else if (game->ray.was_hit_v == 1)
	{
		*x_tex = (int)game->ray.wall_hity % game->block;
	}
	*x_tex = (double)*x_tex * step_x;
}
