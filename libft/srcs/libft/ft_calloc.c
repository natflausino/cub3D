#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*dest;

	total_size = size * count;
	dest = malloc(total_size);
	if (!dest)
		return (0);
	ft_memset(dest, 0, total_size);
	return (dest);
}
