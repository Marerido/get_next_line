#include "get_next_line.h"
#include <stdio.h>

static char	*read_file(int fd, char *line)
{
	char	*ptr;
	ssize_t	bytes;

	ptr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	
	bytes = read(fd, ptr, BUFFER_SIZE);
	if (bytes == -1)
	{
		free (ptr);
		return (NULL);
	}
	line = ft_strjoin(line, ptr);
	return (line);
}

static char	*extract_lines(char *line)
{
	char	*backup;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[j] != '\n' && line[j] != '\0')
		j++;
	backup = ft_calloc(j, sizeof(char));
	if (!backup)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		backup[i] = line[i];
		i++;
	}
	return (backup);
}

static char *other_lines(char *line)
{
	int	length;
	int	i;
	int	j;
	char	*ptr;

	i = 0;
	length = ft_strlen(line);
	ptr = ft_calloc(length - i, sizeof(char));
	i++;
	j = 0;
	while(line[i] != '\0')
	{
		ptr[j] = line[i];
		i++;
		j++;
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char	*ptr;
	char	*line;
	char	*backup;
	char	*str;
	ssize_t		bytes;
	int		i;
	int		j;
	int		length;
	char	*print;

	i = 0;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_calloc(1, sizeof(char));
	if (!ptr)
		return (NULL);
	line = read_file(fd, line);
	backup = extract_lines(line);
	str = other_lines(line);
	print = ft_strjoin(line, str);
	return (backup);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd;
	char	*print_line;

	fd = open("test1.txt", O_RDONLY);
	print_line = get_next_line(fd);
	if (print_line != NULL)
		printf("%s\n", print_line);
	print_line = NULL;
	close(fd);
	return (0);
}
