#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 4
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char    *get_next_line(int fd);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *str);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *src);

#endif