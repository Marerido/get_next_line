#include "get_next_line.h"
#include <stdio.h>

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

	i = 0;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_calloc(1, sizeof(char));
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
	while (line[j] != '\n' && line[j] != '\0')
		j++;
	backup = ft_calloc(j + 1, sizeof(char));
	if (!backup)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		backup[i] = line[i];
		i++;
	}
	length = ft_strlen(line);
	str = ft_calloc(length + 1 - i, sizeof(char));
	i++;
	j = 0;
	while(line[i] != '\0')
	{
		str[j] = line[i];
		i++;
		j++;
	}
	return (str);
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
