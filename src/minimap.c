#include "../includes/cub3d.h"

void	image_pixel_put(t_game *game, int x, int y)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	char			*pixel;

	red = (unsigned char)game->color.red;
	green = (unsigned char)game->color.green;
	blue = (unsigned char)game->color.blue;
	pixel = game->data.addr + 2 * (y * (game->data.line_len / 8)) + (x * (game->data.bpp / 32));
	*(unsigned int *)pixel = (red << 16 | green << 8 | blue);
}

void	draw_rect(t_game *game)
{
	int		i;
	int		j;
	i = -1;
	while (++i < game->square.size)
	{
		j = -1;
		while (++j < game->square.size)
		{
			//printf("SQUARE X ->%i\n", game->square.x + j);
			//printf("SQUARE Y ->%i\n", game->square.y + i);
			image_pixel_put(game, game->square.x + j, game->square.y + i);
			//j++;
		}
		//i++;
	}
}

void	minimap(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	game->square.size = game->block / 8;
	while (row < game->file.map_row)
	{
		col = 0;
		game->square.y = game->square.size * row;
		while (col < game->file.map_col)
		{
			if (game->file.tab[row][col] == '1')
			{
				game->color.red = 255;
				game->color.green = 255;
				game->color.blue = 255;
			}
			else
			{
				game->color.red = 0;
				game->color.green = 0;
				game->color.blue = 0;
			}
			//col++;
			game->square.x = game->square.size * col++;
			draw_rect(game);
		}
		row++;
	}
}

void	minimap_player(t_game *game)
{
	game->color.red = 0;
	game->color.green = 255;
	game->color.blue = 0;
	game->square.size = game->block / 8;
	game->square.x = (game->player.x / game->square.size) - (game->square.size / 2);
	game->square.y = (game->player.y / game->square.size) - (game->square.size / 2);
	draw_rect(game);
}

// void	minimap_rays(t_game * game)
// {
// 	int i;
// 	t_int_coord	player;
// 	t_int_coord	wall;

// 	player.x = game->player.x * MAP_SCALE;
// 	player.y = game->player.y * MAP_SCALE;
// 	i = 0;
// 	while (i < game->file.width)
// 	{
// 		wall.x = game->rays[i].wall_hitx * MAP_SCALE;
// 		wall.y = game->rays[i].wall_hity * MAP_SCALE;
// 		draw_line(game, player, wall);
// 		i++;
// 	}
// 	//free(game->rays);
// }



// void	draw_line(t_game *game, t_int_coord p0, t_int_coord p1)
// {
// 	int	i;
// 	double	step;

// 	i = 0;
// 	double deltaX = (double)(p1.x - p0.x);
// 	double deltaY = (double)(p1.y - p0.y);

// 	if (fabs(deltaX) > fabs(deltaY))
// 		step = fabs(deltaX);
// 	else
// 		step = fabs(deltaY);
// 	deltaX = deltaX / step;
// 	deltaY = deltaY / step;
// 	double positionX = p0.x;
// 	double positionY = p0.y;
// 	while (i++ < step)
// 	{
// 		image_pixel_put(game, positionX, positionY);
// 		positionX += deltaX;
// 		positionY += deltaY;
// 		//i++;
// 	}
// }


/*void	draw_player(t_game *game, int x, int y, int r) //circular player
{
	double	i;
	double	angle;
	double	x1;
	double	y1;
	game->color.red = 255;
	game->color.green = 255;
	game->color.blue = 0;
	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * M_PI / 180);
		y1 = r * sin(angle * M_PI / 180);
		image_pixel_put(game, x + x1, y + y1, GRAY);
		i += 0.1;
	}
}*/

/******************************************************************************
**	MINIMAP == MORREU!!!
******************************************************************************/
/*
void put_rays(t_game *game)
{
	int i;
	i = 0;
	for (int i = 0; i < NUM_RAYS; i += 50)
	{
		draw_line(game, (game->player.x + cos(game->player.rotation_angle) * 30) * MAP_SCALE, (game->player.y + sin(game->player.rotation_angle) * 30) * MAP_SCALE);
	} angle + ((fov/col) i)
}*/
