#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
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

	mem = malloc(nitems * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nitems * size);
	return (mem);
}


char	*ft_strcpy(char *dest, const char *src)
{
	size_t i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ptr;
	size_t	len1, len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcpy(ptr + len1, s2);
	free(s1);
	return (ptr);
}


unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int i = 0;

	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}


char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}


char	*ft_strdup(const char *src)
{
	char	*place;
	size_t	i;

	place = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!place)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		place[i] = src[i];
		i++;
	}
	place[i] = '\0';
	return (place);
}

