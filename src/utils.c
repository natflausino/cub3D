#include "../includes/cub3d.h"

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

void	table_free(char **tab)
{
	int	i;
	int	count;

	count = ft_strlen_ptr(tab);
	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

double	normalize_angle(double angle)
{
	double	norm_angle;

	norm_angle = remainder(angle, 2 * PI);
	if (norm_angle < 0)
	{
		norm_angle = (2 * PI) + norm_angle;
	}
	return (norm_angle);
}

double	dist2points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 -x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
