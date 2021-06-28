#include "../../includes/bonus/cub3d_bonus.h"

void	render_item(t_game *game)
{
	int	color;

	game->pos.x = game->file.width - 153;
	game->pos_item.x = 163;
	while (game->pos.x < game->file.width)
	{
		game->pos.y = 80;
		game->pos_item.y = 0;
		while (game->pos.y < 160)
		{
			color = get_color_item(&game->item_tex[game->item],
					game->pos_item.x, game->pos_item.y);
			if (color != 0x000000)
				image_put_pixel(game, game->pos.x, game->pos.y, color);
			game->pos.y++;
			game->pos_item.y++;
		}
		game->pos_item.x++;
		game->pos.x++;
	}
}

int	get_color_item(t_tex *item_tex, int item_x, int item_y)
{
	return (*(unsigned int *)(item_tex->addr
		+ (item_y * item_tex->l_len + item_x
			* (item_tex->bpp / 8))));
}
