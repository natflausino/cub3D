#include "../../includes/bonus/cub3d_bonus.h"

char	*full_line(t_game *game, char *line)
{
	int		i;
	int		size_line;
	char	*tmp;

	tmp = line;
	size_line = ft_strlen(line);
	i = 0;
	if (size_line < game->file.map_col)
	{
		line = (char *)ft_calloc(1, sizeof(char) * (game->file.map_col + 1));
		while (i < game->file.map_col)
		{
			if (i < (int)ft_strlen(tmp))
				line[i] = tmp[i];
			else
				line[i] = ' ';
			i++;
		}
		line[i] = '\0';
		free(tmp);
	}
	return (line);
}

void	check_line(t_game *game, char *line, int fd)
{
	int	i;

	i = -1;
	if (ft_strstr(line, "R ") || ft_strstr(line, "NO ")
		|| ft_strstr(line, "SO ") || ft_strstr(line, "WE ")
		|| ft_strstr(line, "EA ") || ft_strstr(line, "F ")
		|| ft_strstr(line, "D ") || ft_strstr(line, "C ") || line[0] == '\0')
	{
		if (line[0] != '\0')
			game->file.args++;
		get_param(game, line);
	}
	else if (find_map(line))
	{
		map_extract(game, line, fd);
		while (game->file.tab[++i] != NULL)
			game->file.tab[i] = full_line(game, game->file.tab[i]);
		is_map_closed(game, game->file.tab);
		map_check(game);
		map_check2(game, game->file.tab);
		inside_map(game->file.tab);
	}
}

int	map_col_size(int fd)
{
	int		max;
	int		size;
	int		gnl;
	char	*line;

	gnl = 1;
	size = 0;
	max = 0;
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &line);
		if (find_map(line))
		{
			size = ft_strlen(line);
			if (size > max)
				max = size;
		}
		free(line);
	}
	return (max);
}

void	reset_path(t_game *game)
{
	game->file.no_path = NULL;
	game->file.ea_path = NULL;
	game->file.we_path = NULL;
	game->file.so_path = NULL;
	game->file.d_path = NULL;
	game->file.f_path = NULL;
}

int	find_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
