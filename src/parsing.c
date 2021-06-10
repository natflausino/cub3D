#include "../includes/cub3d.h"

void	screen_resolution(t_game *game)
{
	int		max_w;
	int		max_h;

	mlx_get_screen_size(game->data.mlx, &max_w, &max_h);
	if (game->file.width > max_w)
		game->file.width = max_w;
	if (game->file.height > max_h)
		game->file.height = max_h;
}

void	get_resolution(t_game *game, char *line)
{
	char	**split;
	char	*tmp;

	split = ft_split(line, ' ');
	if (ft_strlen_ptr(split) != 3 || !check_digit(split[1], "0123456789")
		|| !check_digit(split[2], "0123456789"))
	{
		free(line);
		table_free(split);
		return_error(-20);
	}
	tmp = split[1];
	split[1] = ft_substr(split[1], 0, 6);
	game->file.width = ft_atoi(split[1]);
	free(tmp);
	tmp = split[2];
	split[2] = ft_substr(split[2], 0, 6);
	game->file.height = ft_atoi(split[2]);
	free(tmp);
	screen_resolution(game);
	if (game->file.width <= 0 || game->file.height <= 0)
	{
		table_free(split);
		return_error(-20);
	}
	table_free(split);
}

void	get_texture(char *line, char **texture)
{
	char	*split;
	int		tex_count;

	split = ft_strtrim(line, " ");
	*texture = ft_strdup(split);
	tex_count = (int)ft_strlen(*texture);
	//if (open(*texture, O_RDONLY) == -1 || split[tex_count - 1] != 'm'
	//	|| split[tex_count - 2] != 'p' || split[tex_count - 3] != 'x')
	//{
	//	free(split);
	//	printf("ERROR: TEXTURE ERROR");
	//}
	if (open(*texture, O_RDONLY) == -1)
	{
		free(split);
		return_error(-21);
	}
	if (split[tex_count - 1] != 'm' || split[tex_count - 2] != 'p'
		|| split[tex_count - 3] != 'x')
	{
		free(split);
		return_error(-23);
	}
	free(split);
}

int	check_param(char *line)
{
	if ((ft_strstr(line, "R ") || ft_strstr(line, "R\t")) // talvez trocar por &&
		&& (ft_strstr(line, "SO ") || ft_strstr(line, "SO\t"))
		&& (ft_strstr(line, "NO ") || ft_strstr(line, "NO\t"))
		&& (ft_strstr(line, "WE ") || ft_strstr(line, "WE\t"))
		&& (ft_strstr(line, "EA ") || ft_strstr(line, "EA\t"))
		&& (ft_strstr(line, "F ") || ft_strstr(line, "F\t"))
		&& (ft_strstr(line, "C ") || ft_strstr(line, "C\t"))
		&& (ft_strstr(line, "S ") || ft_strstr(line, "S\t"))
		&& (line[0] == '\0'))
		return (1);
	//else// acrescentamos 07-may
		//return_error(-18);
	return (0);
}

void	get_param(t_game *game, char *line)
{
	if (line[0] == ' ')
	{
		free(line);
		return_error(-18);
	}
	if (line[0] == 'R')
		get_resolution(game, line);
	else if (line[0] == 'N' && line[1] == 'O')
		get_texture(line + 2, &game->file.no_path);
	else if (line[0] == 'S' && line[1] == 'O')
		get_texture(line + 2, &game->file.so_path);
	else if (line[0] == 'W' && line[1] == 'E')
		get_texture(line + 2, &game->file.we_path);
	else if (line[0] == 'E' && line[1] == 'A')
		get_texture(line + 2, &game->file.ea_path);
	else if (line[0] == 'S' && line[1] == ' ')
		get_texture(line + 1, &game->file.s_path);
	else if (line[0] == 'F' && game->floor_bool == 0)
	{
		game->floor_bool = 1;
		game->file.color_floor = (int)get_color(line + 1);
	}
	else if (line[0] == 'C' && game->celling_bool == 0)
	{
		game->celling_bool = 1;
		game->file.color_ceiling = (int)get_color(line + 1);
	}
}
