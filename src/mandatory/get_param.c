#include "../../includes/mandatory/cub3d.h"

int	check_digit(char *tab, char *set)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	if (!tab || !*tab || !set)
		return (0);
	while (tab[i])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (tab[i] == set[j])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (0);
		i++;
	}
	return (1);
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
		return_free_error(-20, split);
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
	table_free(split);
}

void	get_texture(char *line, char **texture)
{
	char	*split;
	int		tex_count;

	split = ft_strtrim(line, " ");
	*texture = ft_strdup(split);
	tex_count = (int)ft_strlen(*texture);
	if (open(*texture, O_RDONLY) == -1)
	{
		free(split);
		free(*texture);
		return_error(-23);
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
	if ((ft_strstr(line, "R ") || ft_strstr(line, "R\t"))
		&& (ft_strstr(line, "SO ") || ft_strstr(line, "SO\t"))
		&& (ft_strstr(line, "NO ") || ft_strstr(line, "NO\t"))
		&& (ft_strstr(line, "WE ") || ft_strstr(line, "WE\t"))
		&& (ft_strstr(line, "EA ") || ft_strstr(line, "EA\t"))
		&& (ft_strstr(line, "F ") || ft_strstr(line, "F\t"))
		&& (ft_strstr(line, "C ") || ft_strstr(line, "C\t"))
		&& (ft_strstr(line, "S ") || ft_strstr(line, "S\t"))
		&& (line[0] == '\0'))
		return (1);
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
	if (line[0] == 'N' && line[1] == 'O' && game->file.no_path == 0)
		get_texture(line + 2, &game->file.no_path);
	else if (line[0] == 'S' && line[1] == 'O' && game->file.so_path == 0)
		get_texture(line + 2, &game->file.so_path);
	else if (line[0] == 'W' && line[1] == 'E' && game->file.we_path == 0)
		get_texture(line + 2, &game->file.we_path);
	else if (line[0] == 'E' && line[1] == 'A' && game->file.ea_path == 0)
		get_texture(line + 2, &game->file.ea_path);
	else if (line[0] == 'S' && line[1] == ' ' && game->file.s_path == 0)
		get_texture(line + 1, &game->file.s_path);
	else
		check_f_c(game, line);
}
