#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * n + 1);
	if (temp == NULL)
		return (NULL);
	else
		ft_strlcpy(temp, str, n + 1);
	return (temp);
}
