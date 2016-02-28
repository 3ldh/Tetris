/*
** get_next_line.h for get_next_line in /home/sauvau_m/rendu/CPE_2015_getnextline
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Dec 30 11:31:24 2015 Mathieu Sauvau
** Last update Sat Feb 27 14:38:39 2016 Mathieu Sauvau
*/

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

#ifndef  READ_SIZE
# define READ_SIZE (150)
#endif /* !READ_SIZE */

typedef enum{false, true} bool;
char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H */
