/*
** tetris.h for tetris in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:25:21 2016 maud marel
** Last update Mon Feb 29 18:26:05 2016 Mathieu Sauvau
*/

#ifndef TETRIS_H_
# define TETRIS_H_
# define UNUSED __attribute__((__unused__))

typedef	struct	s_tetrimino
{
  int		height;
  int		width;
  int		color;
  int		x;
  int		y;
  char		*name;
  char		**tetrimino;
}		t_tetri;

typedef	struct	s_list_tetrimino
{
  t_tetri	tetrimino;
  t_tetri	*next;
  t_tetri	*prev;
}		t_list_tetri;

typedef struct	s_options
{
  char		level;
  char		*row;
  char		*col;
  int		hide_next;
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
}		t_options;

typedef	struct	s_tetris
{
  t_options	*options;
  int		high_score;
  int		score;
  int		lines;
  int		start_time;
  int		time;
  int		level;
  int		speed;
}		t_tetris;

typedef int(**t_tab_com)(t_tetris *, char *);
typedef int(**t_tab_sim)(t_tetris *, char *);

void		check_arg(t_tetris *, int, char **);
void		display_help();
void		change_level(t_tetris *, char *);
void		change_key_left(t_tetris *, char *);
void		change_key_right(t_tetris *, char *);
void		change_key_turn(t_tetris *, char *);
void		change_key_drop(t_tetris *, char *);
void		change_key_quit(t_tetris *, char *);
void		change_key_pause(t_tetris *, char *);
void		change_map_size(t_tetris *, char *);
void		change_without_next(t_tetris *, char *);

int		my_strcmp(char *, char *);

#endif /* !TETRIS_H_ */
