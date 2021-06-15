#include "libft.h"

size_t	ft_strclen(const char *str, const char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
