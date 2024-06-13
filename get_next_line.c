#include "get_next_line.h"
#include <stdio.h>

static char *read_line(int fd, char *line)
{
    char *buffer;
    ssize_t bytes;
    char *temp;

    if (!line)
        line = ft_calloc(1, sizeof(char));
    if (!line)
        return NULL;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
    {
        free(line);
        return NULL;
    }

    while (1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(line);
            free(buffer);
            return NULL;
        }
        if (bytes == 0)
            break;
        buffer[bytes] = '\0';
        temp = line;
        line = ft_strjoin(line, buffer);
        free(temp);
        if (!line)
        {
            free(buffer);
            return NULL;
        }
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return line;
}

static char *get_line(char *line)
{
    int i;
    char *ptr;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    ptr = ft_calloc(i + 2, sizeof(char));
    if (!ptr)
        return NULL;
    ft_strlcpy(ptr, line, i + 1);
    if (line[i] == '\n')
        ptr[i] = '\n';
    return ptr;
}

char *get_next_line(int fd)
{
    static char *line;
    char *one_line;
    char *temp;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return NULL;
    line = read_line(fd, line);
    if (!line || !*line)
    {
        free(line);
        line = NULL;
        return NULL;
    }
    one_line = get_line(line);
    temp = line;
    line = ft_strdup(line + ft_strlen(one_line));
    free(temp);
    if (!line || *line == '\0')
    {
        free(line);
        line = NULL;
    }
    return one_line;
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *print_line;
    int i;

    i = 1;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((print_line = get_next_line(fd)))
    {
        printf("line[%d]: %s\n", i, print_line);
        free(print_line);
        i++;
    }

    close(fd);
    return 0;
}
