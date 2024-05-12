#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 4
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

#endif