#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char		*tmp;

	tmp = ft_strdup(s1);
	free(s1);
	s1 = ft_strjoin(s2, tmp);
	free(tmp);
	free(s2);
	s2 = NULL;
	return (s1);
}
