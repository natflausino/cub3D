#include "../../includes/bonus/cub3d_bonus.h"

void	check_color(char **tab)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 3)
	{
		str = ft_strtrim(tab[i], " ");
		if (!check_digit(str, "0123456789"))
		{
			free(str);
			return_free_error(-24, tab);
		}
		i++;
		free(str);
	}
}

int	color_assemble(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

int	count_char(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int	get_color(char *line)
{
	char	**split;
	t_color	color;
	char	*tmp;
	int		c_count;

	c_count = 0;
	tmp = ft_strtrim(line, " ");
	c_count = count_char(line, ',');
	split = ft_split(tmp, ',');
	if (ft_strlen_ptr(split) != 3 || c_count != 2)
	{
		free(tmp);
		return_free_error(-24, split);
	}
	check_color(split);
	color.red = ft_atoi(split[0]);
	color.green = ft_atoi(split[1]);
	color.blue = ft_atoi(split[2]);
	free(tmp);
	table_free(split);
	if ((color.red > 255 || color.red < 0) || (color.green > 255
			|| color.green < 0) || (color.blue > 255 || color.blue < 0))
		return_error(-24);
	return (color_assemble(color.red, color.green, color.blue));
}

void	image_put(t_game *game, t_bmp *bmp, int file)
{
	int				color;
	unsigned char	*buffer;
	int				row;
	int				col;

	row = bmp->height - 1;
	buffer = ft_calloc(1, bmp->file_size);
	while (row >= 0)
	{
		col = 0;
		while (col < (int)bmp->width)
		{
			color = game->data.addr[(game->file.height - row)
				*bmp->width + col];
			buffer[row * bmp->width * 3 + col * 3 + 0] = color;
			buffer[row * bmp->width * 3 + col * 3 + 1] = color >> 8;
			buffer[row * bmp->width * 3 + col * 3 + 2] = color >> 16;
			col++;
		}
		row--;
	}
	write(file, buffer, bmp->file_size);
	free(buffer);
}
