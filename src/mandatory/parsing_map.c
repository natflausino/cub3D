#include "../../includes/mandatory/cub3d.h"

void	count_arg(t_game *game, int fd)
{
	if (game->file.args != 8)
	{
		return_error(-18);
	}
	if (game->floor_bool == 0 || game->celling_bool == 0)
	{
		return_error(-24);
	}
}

void	map_extract(t_game *game, char *line, int fd)
{
	char	*str;
	char	*tmp;
	char	*new_line;
	int		gnl;

	gnl = -1;
	count_arg(game, fd);
	str = ft_strjoin(line, "@");
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &new_line);
		if (new_line[0] == '\0')
			new_line[0] = ' ';
		tmp = str;
		str = ft_strjoin(str, new_line);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, "@");
		free(tmp);
		free(new_line);
	}
	game->file.tab = ft_split(str, '@');
	free(str);
	game->file.map_row = ft_strlen_ptr(game->file.tab);
}

void	map_check(t_game *game)
{
	int		x;
	int		y;
	char	**tmp;

	x = 0;
	while (game->file.tab[x] != NULL)
	{
		y = 0;
		tmp = ft_split(game->file.tab[x], ' ');
		while (tmp[y] != NULL)
		{
			if ((tmp[y][0] != '1' && tmp[y][0] != ' ')
				|| (tmp[y][ft_strlen(tmp[y]) - 1] != '1'
				&& tmp[y][ft_strlen(tmp[y]) - 1] != ' '))
				return_free_error(-16, tmp);
			y++;
		}
		x++;
		table_free(tmp);
	}
}

void	map_check2(t_game *game, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->file.map_col)
	{
		i = 0;
		while (i < game->file.map_row)
		{
			if (tab[i][j] == ' ')
			{
				if (i > 0)
					if ((tab[i - 1][j] != '1') && (tab[i - 1][j] != ' '))
						return_free_error(-16, tab);
				if (i < game->file.map_row - 1)
					if (tab[i + 1][j] != '1' && tab[i + 1][j] != ' ')
						return_free_error(-16, tab);
			}
			i++;
		}
		j++;
	}
}
