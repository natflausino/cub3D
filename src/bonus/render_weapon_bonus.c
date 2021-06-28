#include "../../includes/bonus/cub3d_bonus.h"

void	render_weapon(t_game *game)
{
	int	color;

	game->pos.x = game->file.width - (game->file.width / 1.8);
	game->pos_weapon.x = game->file.width - (game->file.width / 1.3);
	while (game->pos.x < (game->file.width - (game->file.width / 3)))
	{
		game->pos.y = game->file.height - (game->file.height / 2.7);
		game->pos_weapon.y = 0;
		while (game->pos.y < game->file.height)
		{
			color = get_color_weapon(&game->weapon_tex[game->weapon],
					game->pos_weapon.x, game->pos_weapon.y);
			if (color != 0xffffff)
				image_put_pixel(game, game->pos.x, game->pos.y, color);
			game->pos.y++;
			game->pos_weapon.y++;
		}
		game->pos_weapon.x++;
		game->pos.x++;
	}
}

int	get_color_weapon(t_tex *weapon_tex, int weapon_x, int weapon_y)
{
	return (*(unsigned int *)(weapon_tex->addr
		+ (weapon_y * (weapon_tex->l_len) + weapon_x
			* (weapon_tex->bpp / 8))));
}
