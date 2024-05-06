#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem;

	mem = (void *)malloc(nitems * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (nitems * size));
	return (mem);
}