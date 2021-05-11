#include "libft.h"

char	*ft_strjoin_free(char *dest, char *src)
{
	char	*new_str;
	int		i;
	int		dest_len;
	int		src_len;

	if (!dest || !src)
		return (NULL);
	i = -1;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	new_str = malloc((dest_len + src_len + 1) * sizeof(*new_str));
	if (!new_str)
	{
		ft_strdel(&dest);
		return (NULL);
	}
	while (dest[++i])
		new_str[i] = dest[i];
	i = -1;
	while (src[++i])
		new_str[dest_len++] = src[i];
	new_str[dest_len] = '\0';
	ft_strdel(&dest);
	return (new_str);
}
