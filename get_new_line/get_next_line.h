#ifndef GET_NEXT_LINE
 #define GET_NEXT_LINE

 #ifndef BUFFER_SIZE
  #define BUFFER_SIZE 42
#endif


#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif