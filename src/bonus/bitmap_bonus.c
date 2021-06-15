#include "../../includes/bonus/cub3d_bonus.h"

void	image_header(t_bmp *bmp, int file)
{
	unsigned char	str[54];

	ft_bzero(str, 54);
	ft_memcpy(str, "BM", 2);
	ft_memcpy(str + 2, &bmp->file_size, 4);
	ft_memcpy(str + 10, &bmp->offset_bits, 4);
	ft_memcpy(str + 14, &bmp->size_header, 4);
	ft_memcpy(str + 18, &bmp->width, 4);
	ft_memcpy(str + 22, &bmp->height, 4);
	ft_memcpy(str + 26, &bmp->planes, 2);
	ft_memcpy(str + 28, &bmp->bit_count, 2);
	ft_memcpy(str + 34, &bmp->image_size, 4);
	write(file, &str, 54);
}

void	fill_data(t_bmp *bmp, t_game *game)
{
	bmp->file_size = (game->file.width * game->file.height * 4) + 54;
	bmp->reserved1 = 0;
	bmp->reserved2 = 0;
	bmp->offset_bits = 0;
	bmp->size_header = 40;
	bmp->width = game->file.width;
	bmp->height = game->file.height;
	bmp->planes = 1;
	bmp->bit_count = 24;
	bmp->compression = 0;
	bmp->image_size = bmp->file_size - 54;
	bmp->ppm_x = 0;
	bmp->ppm_y = 0;
	bmp->clr_used = 0;
	bmp->clr_imported = 0;
}

void	image_create(t_game *game)
{
	t_bmp	bmp;
	int		file;

	file = 0;
	file = open("./screen_shot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (!file)
		return_error(-14);
	fill_data(&bmp, game);
	image_header(&bmp, file);
	image_put(game, &bmp, file);
}
