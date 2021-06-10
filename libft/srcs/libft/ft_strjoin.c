#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long		i;
	char				*output;
	unsigned long		size1;
	unsigned long		size2;

	if (!(s1 && s2))
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	output = ft_calloc(1, sizeof(char) * (size1 + size2 + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		output[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		output[i] = s2[i - size1];
		i++;
	}
	output[i] = '\0';
	return (output);
}
