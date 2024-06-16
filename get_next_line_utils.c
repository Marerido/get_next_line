/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunglaub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:43:08 by tunglaub          #+#    #+#             */
/*   Updated: 2024/06/15 17:43:29 by tunglaub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem;
	char	*str;
	size_t	total_size;
	size_t	i;

	i = 0;
	total_size = nitems * size;
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	str = mem;
	while (i < total_size)
	{
		str[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (free(s1), ptr);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
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

char	*ft_strdup(char *src)
{
	char	*place;
	int		i;

	i = 0;
	place = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!place)
		return (NULL);
	while (src[i] != '\0')
	{
		place[i] = src[i];
		i++;
	}
	place[i] = '\0';
	return (place);
}
