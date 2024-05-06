#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *ptr;
    int     lines;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    ptr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!ptr)
        return (NULL);
    lines = read(fd, ptr, BUFFER_SIZE);
    if (line == -1)
        return (NULL);
    else if (line == 0)
        return (0);
            
}