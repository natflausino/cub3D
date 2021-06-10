#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int					i;
	char				*tmp;

	i = 0;
	tmp = (char *)s;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (*tmp)
			tmp++;
		return ((char *) tmp);
	}
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return ((char *)&tmp[i]);
		i++;
	}
	if (*tmp == '\0' && c == '\0')
	{
		return (tmp);
	}
	return (NULL);
}
