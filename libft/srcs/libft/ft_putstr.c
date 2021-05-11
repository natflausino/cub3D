#include "libft.h"

void	ft_putstr(char *s)
{
	size_t	len;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		ft_putchar(*(s + i));
		i++;
	}
}
