#include "../../includes/bonus/cub3d_bonus.h"

void	image_put_pixel(t_game *game, int x, int y, int color)
{
	char			*pixel;

	pixel = game->data.addr + 2 * (y * (game->data.line_len / 8))
		+ (x * (game->data.bpp / 32));
	*(unsigned int *)pixel = color;
}

void	draw_rect(t_game *game, int color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->square.size)
	{
		j = -1;
		while (++j < game->square.size)
			image_put_pixel(game, game->square.x + j,
				game->square.y + i, color);
	}
}

void	minimap(t_game *game)
{
	int	row;
	int	col;
	int	color;

	row = 0;
	game->square.size = game->block / 8;
	while (row < game->file.map_row)
	{
		col = 0;
		game->square.y = game->square.size * row;
		while (col < game->file.map_col)
		{
			if (game->file.tab[row][col] == '1')
				color = 0x00FFFFFF;
			else
				color = 0x00000000;
			game->square.x = game->square.size * col++;
			draw_rect(game, color);
		}
		row++;
	}
}

void	minimap_player(t_game *game)
{
	int	color;

	color = 0x0000FF00;
	game->square.size = game->block / 8;
	game->square.x = (game->player.x / game->square.size)
		- (game->square.size / 2);
	game->square.y = (game->player.y / game->square.size)
		- (game->square.size / 2);
	draw_rect(game, color);
}
