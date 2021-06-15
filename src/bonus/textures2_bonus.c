#include "../../includes/bonus/cub3d_bonus.h"

void	free_textures(t_game *game)
{
	if (game->file.no_path)
	{
		mlx_destroy_image(game->data.mlx, game->tex[N_TEX].img);
		free(game->file.no_path);
		game->file.no_path = NULL;
	}
	if (game->file.so_path)
	{
		mlx_destroy_image(game->data.mlx, game->tex[S_TEX].img);
		free(game->file.so_path);
		game->file.so_path = NULL;
	}
	if (game->file.ea_path)
	{
		mlx_destroy_image(game->data.mlx, game->tex[E_TEX].img);
		free(game->file.ea_path);
		game->file.ea_path = NULL;
	}
	if (game->file.we_path)
	{
		mlx_destroy_image(game->data.mlx, game->tex[W_TEX].img);
		free(game->file.we_path);
		game->file.we_path = NULL;
	}
	free_textures2(game);
}

void	free_textures2(t_game *game)
{
	if (game->file.d_path)
	{
		mlx_destroy_image(game->data.mlx, game->tex[D_TEX].img);
		free(game->file.d_path);
		game->file.d_path = NULL;
	}
	if (game->file.f_path)
	{
		mlx_destroy_image(game->data.mlx, game->tex[F_TEX].img);
		free(game->file.f_path);
		game->file.f_path = NULL;
	}
}
