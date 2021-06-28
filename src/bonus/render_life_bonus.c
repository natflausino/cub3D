#include "../../includes/bonus/cub3d_bonus.h"

void	render_lifebar(t_game *game)
{
	int	color;

	game->pos.x = game->file.width - 153;
	game->pos_life.x = 163;
	while (game->pos.x < game->file.width)
	{
		game->pos.y = 0;
		game->pos_life.y = 0;
		while (game->pos.y < 80)
		{
			color = get_color_life(&game->life_tex[game->life],
					game->pos_life.x, game->pos_life.y);
			if (color != 0x000000)
				image_put_pixel(game, game->pos.x, game->pos.y, color);
			game->pos.y++;
			game->pos_life.y++;
		}
		game->pos_life.x++;
		game->pos.x++;
	}
}

int	get_color_life(t_tex *life_tex, int life_x, int life_y)
{
	return (*(unsigned int *)(life_tex->addr
		+ (life_y * life_tex->l_len + life_x
			* (life_tex->bpp / 8))));
}
