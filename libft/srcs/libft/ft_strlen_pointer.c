#include "libft.h"

int	ft_strlen_ptr(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}
