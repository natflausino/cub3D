#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char				*output;
	int					i;
	int					size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	output = ft_calloc(1, sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	i = 0;
	while ((char)s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
