#include "../../includes/bonus/cub3d_bonus.h"

void	inside_map(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] < '0' && tab[i][j] > '5') && tab[i][j] != ' '
				&& tab[i][j] != 'N' && tab[i][j] != 'S' && tab[i][j] != 'W'
				&& tab[i][j] != 'E')
				return_free_error(-18, tab);
			j++;
		}
		i++;
	}
}

void	is_map_closed(t_game *game, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < game->file.map_col)
	{
		if ((tab[0][j] != '1' && tab[0][j] != ' '))
			return_free_error(-16, tab);
		if (tab[game->file.map_row - 1][j] != '1'
				&& tab[game->file.map_row - 1][j] != ' ')
			return_free_error(-16, tab);
		j++;
	}
}

void	check_f_c(t_game *game, char *line)
{
	if (line[0] == 'F' && game->floor_bool == 0)
	{
		game->floor_bool = 1;
		get_texture(line + 1, &game->file.f_path);
	}
	else if (line[0] == 'C' && game->celling_bool == 0)
	{
		game->celling_bool = 1;
		game->file.color_ceiling = (int)get_color(line + 1);
	}
}
