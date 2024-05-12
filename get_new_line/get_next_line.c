#include "get_next_line.h"

static char    *read_line(int fd, char *line)
{
	char    *ptr;
	ssize_t bytes;

	ptr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (*line != '\0')
	{
		bytes = read(fd, ptr, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(ptr);
			return (NULL);
		}
		if (bytes == 0)
		{
			free(ptr);
			return (0);
		}
		line = ft_strjoin(line, ptr);
		free(ptr);
	}
	return (ptr);				
}
static char	*get_line(char *line)
{
	int	i;
	char	*ptr;

	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
		i++;
	ptr = ft_calloc(i + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, line, i);
	if (line[i] == '\n')
		ptr[i] = '\n';
	return (ptr);
}

char    *get_next_line(int fd)
{
	static char     *line;
	char	*one_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	one_line = get_line(line);

	return (one_line);
}


#include <stdio.h>
#include <fcntl.h>

int main() {
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd))!= NULL) {
		printf("%s", line);
		free(line);
	}

	close(fd);
	return 0;
}