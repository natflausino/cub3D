#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*s;

	size++;
	s = (char *)ft_calloc(1, sizeof(char) * size);
	if (!s)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (start >= ft_strlen(s))
		return (ft_strnew(0));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	return (ft_strndup(s + start, len));
}
