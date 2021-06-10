#include "../includes/cub3d.h"

char	*type_define(int tex, int id)
{
	char	*type;
	char	*temp;

	type = ft_itoa(id);
	if (tex == SP)
		temp = ft_strjoin("./text/sprites/sprite", type);
	free(type);
	type = ft_strjoin(temp, ".xpm");
	free(temp);
	return (type);
}

void	load_sprite(t_game *game)
{
	int		i;
	char	*type;

	i = 0;
	while (i < game->num_sprite)
	{
		type = type_define(SP, game->sprite[i].index);
		game->sprite[i].tex.img = mlx_xpm_file_to_image(game->data.mlx, type,
				&game->sprite[i].tex.tex_width,
				&game->sprite[i].tex.tex_height);
		if (!(game->sprite[i].tex.img))
			return_error(-22);
		game->sprite[i].tex.addr = mlx_get_data_addr(game->sprite[i].tex.img,
				&game->sprite[i].tex.bpp, &game->sprite[i].tex.l_len,
				&game->sprite[i].tex.endian);
		if (!(game->sprite[i].tex.addr))
			return_error(-22);
		i++;
		free(type);
		type = NULL;
	}
}

void	free_sprites(t_game *game)
{
	int		i;
	char	*type;

	i = 0;
	if (game->sprite)
	{
		while (i < game->total_sprites)
		{
			if (game->sprite[i].tex.img)
			{
				mlx_destroy_image(game->data.mlx, game->sprite[i].tex.img);
				type = type_define(SP, game->sprite[i].index);
				free(type);
				type = NULL;
			}
			i++;
		}
	}
}
