#include "../../includes/bonus/cub3d_bonus.h"

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
	free(game->sprite);
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
				&& game->file.tab[i][j] <= '5')
				s_count++;
			j++;
		}
		i++;
	}
	game->num_sprite = s_count;
}
