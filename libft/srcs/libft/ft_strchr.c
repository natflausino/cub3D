#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_in_s;

	if (c > 127)
		c %= 256;
	while (*s != '\0')
	{
		if (*s == c)
		{
			c_in_s = (char *)s;
			return (c_in_s);
		}
		s++;
	}
	if (*s == c)
	{
		c_in_s = (char *)s;
		return (c_in_s);
	}
	return (NULL);
}
