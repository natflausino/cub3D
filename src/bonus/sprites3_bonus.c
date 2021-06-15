#include "../../includes/bonus/cub3d_bonus.h"

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

void	render_sprite(t_game *game)
{
	sort_sprite(game);
	sprite_angle(game);
	sprite_param(game);
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
