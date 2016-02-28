/*
** get_next_line.c for get_next_line in /home/sauvau_m/rendu/CPE_2015_getnextline
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Jan  4 16:18:47 2016 Mathieu Sauvau
** Last update Sat Feb 27 14:20:04 2016 maud marel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	my_strlen(char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int    i;

  i = 0;
  while (src[i] != '\0')
    {
      if (i < n)
	dest[i] = src[i];
      else
	break;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char		*do_line(char *line, int cur_pos, char *buffer, int *total_read)
{
  char		*new_line;
  int		prev_line_len;

  prev_line_len = (line) ? my_strlen(line) : 0;
  if ((new_line = malloc((prev_line_len + cur_pos + 1)
  * sizeof(char *))) == NULL)
    return (NULL);
  my_strncpy(new_line, line ? line : "", prev_line_len);
  my_strncpy(new_line + prev_line_len, buffer, cur_pos);
  my_strncpy(buffer, buffer + cur_pos + 1, READ_SIZE);
  new_line[prev_line_len + cur_pos] = 0;
  if (line)
    free(line);
  *total_read += cur_pos + 1;
  return (new_line);
}

int		init(const int fd, char **line, int *cur_pos)
{
  if (fd < 0)
    return (-1);
  *cur_pos = 0;
  *line = NULL;
  return (0);
}

char		*get_next_line(const int fd)
{
  static int	rd;
  static char	buffer[READ_SIZE + 1];
  static int	total_read;
  int	        cur_pos;
  char		*line;

  if ((init(fd, &line, &cur_pos)) == -1)
    return (NULL);
  while (true)
    {
      if (total_read >= rd)
	{
	  total_read = 0;
	  cur_pos = 0;
	  if (!(rd = read(fd, buffer, READ_SIZE)))
	    return (line);
	  if (rd == -1)
	    return (NULL);
	}
      if (buffer[cur_pos] == '\n')
	return (line = do_line(line, cur_pos, buffer, &total_read));
      if (total_read + cur_pos == rd)
	line = do_line(line, cur_pos , buffer, &total_read);
      cur_pos++;
    }
}
