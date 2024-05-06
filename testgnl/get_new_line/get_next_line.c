#include "get_next_line.h"
static void print_newline_helper(char *buffer)
{
  while (*buffer && *buffer != '\0')
  {
    if (*buffer == '\n')
      *buffer = '\\';
    printf("%c", *buffer);
    buffer++;
  }
}

static char *read_from_file(int fd)
{
  int   bytes_read;
  char  *cup_buffer;
  static int  count;

  count = 1;
  printf("malloc#[%d]---", count++);
  cup_buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
  if (cup_buffer == NULL)
    return (NULL);
  bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
  print_newline_helper(cup_buffer);
  if (bytes_read <= 0)
    return (free(cup_buffer), NULL);
  return (cup_buffer);
}

char    *get_next_line(int fd)
{
  char  *basin_buffer;

  basin_buffer = read_from_file(fd);
  return(basin_buffer);
}


#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int    fd;
  char  *next_line;
  static int  count;

  count = 1;
  fd = open("text.txt", O_RDONLY);
  while (1)
  {
    next_line = get_next_line(fd);
    if (next_line == NULL)
      break ;
    count++;
    printf("[%d]:%s\n", count, next_line);
    free(next_line);
    next_line = NULL;
  }
  close(fd);
  return (0);
}

