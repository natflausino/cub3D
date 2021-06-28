#include "../../includes/bonus/cub3d_bonus.h"

char	*type_define(int tex, int id)
{
	char	*type;
	char	*temp;

	type = ft_itoa(id);
	if (tex == SP)
		temp = ft_strjoin("./text/sprites/sprite", type);
	else if (tex == LIFE)
		temp = ft_strjoin("./text/textures/hud/hearts_", type);
	else if (tex == ITEM)
		temp = ft_strjoin("./text/item/item_", type);
	else if (tex == WEAPON)
		temp = ft_strjoin("./text/weapon/weapon_", type);
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

void	load_life(t_game *game)
{
	int		i;
	char	*type;

	i = 0;
	while (i <= 3)
	{
		type = type_define(LIFE, i);
		game->life_tex[i].img = mlx_xpm_file_to_image(game->data.mlx, type,
				&game->life_tex[i].tex_width, &game->life_tex[i].tex_height);
		if (!(game->life_tex[i].img))
			return_error(-22);
		game->life_tex[i].addr = mlx_get_data_addr(game->life_tex[i].img,
				&game->life_tex[i].bpp, &game->life_tex[i].l_len,
				&game->life_tex[i].endian);
		if (!(game->life_tex[i].addr))
			return_error(-22);
		i++;
		free(type);
		type = NULL;
	}
}

void	load_item(t_game *game)
{
	int		i;
	char	*type;

	i = 0;
	while (i <= 6)
	{
		type = type_define(ITEM, i);
		game->item_tex[i].img = mlx_xpm_file_to_image(game->data.mlx, type,
				&game->item_tex[i].tex_width, &game->item_tex[i].tex_height);
		if (!(game->item_tex[i].img))
			return_error(-22);
		game->item_tex[i].addr = mlx_get_data_addr(game->item_tex[i].img,
				&game->item_tex[i].bpp, &game->item_tex[i].l_len,
				&game->item_tex[i].endian);
		if (!(game->item_tex[i].addr))
			return_error(-22);
		i++;
		free(type);
		type = NULL;
	}
}

void	load_weapon(t_game *game)
{
	int		i;
	char	*type;

	i = 0;
	while (i <= 1)
	{
		type = type_define(WEAPON, i);
		game->weapon_tex[i].img = mlx_xpm_file_to_image(game->data.mlx, type,
				&game->weapon_tex[i].tex_width,
				&game->weapon_tex[i].tex_height);
		if (!(game->weapon_tex[i].img))
			return_error(-22);
		game->weapon_tex[i].addr = mlx_get_data_addr(game->weapon_tex[i].img,
				&game->weapon_tex[i].bpp, &game->weapon_tex[i].l_len,
				&game->weapon_tex[i].endian);
		if (!(game->weapon_tex[i].addr))
			return_error(-22);
		i++;
		free(type);
		type = NULL;
	}
}
