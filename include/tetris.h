/*
** tetris.h for tetris in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:25:21 2016 maud marel
** Last update Tue Mar  1 13:38:07 2016 Mathieu Sauvau
*/

#ifndef TETRIS_H_
# define TETRIS_H_
# define UNUSED __attribute__((__unused__))

#include <stdio.h>
#include <stdlib.h>

enum		check_opt
  {
    LEVEL,
    LEFT,
    RIGHT,
    TURN,
    DROP,
    QUIT,
    PAUSE,
    SIZE,
    NEXT,
    MAX_CHECK_OPT
  };

enum		check_opt_simp
  {
    LEVEL_S,
    LEFT_S,
    RIGHT_S,
    TURN_S,
    DROP_S,
    QUIT_S,
    PAUSE_S,
    NEXT_S,
    MAX_CHECK_OPT_SIMP
  };

typedef	struct	s_tetrimino
{
  int		index;
  int		height;
  int		width;
  int		color;
  int		x;
  int		y;
  char		*name;
  char		**tetrimino;
}		t_tetri;

typedef	struct			s_list_tetrimino
{
  t_tetri			tetrimino;
  struct s_list_tetrimino	*next;
  struct s_list_tetrimino	*prev;
}				t_list_tetri;

typedef struct	s_options
{
  char		level;
  int		row;
  int		col;
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
  t_list_tetri	*list_tetri;
  char		**tab_pos;
  int		high_score;
  int		score;
  int		lines;
  int		start_time;
  int		time;
  int		level;
  int		speed;
}		t_tetris;

typedef struct	s_check_opt
{
  char		*opt;
  void		(*ft_com)(t_tetris *, char *);
}		t_check_opt;

typedef struct	s_check_opt_smp
{
  char		*opt;
  void		(*ft_simp)(t_tetris *, char *);
}		t_check_opt_simp;

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
void		change_level_simp(t_tetris *, char *);
void		change_key_left_simp(t_tetris *, char *);
void		change_key_right_simp(t_tetris *, char *);
void		change_key_turn_simp(t_tetris *, char *);
void		change_key_drop_simp(t_tetris *, char *);
void		change_key_quit_simp(t_tetris *, char *);
void		change_key_pause_simp(t_tetris *, char *);
void		change_without_next_simp(t_tetris *, char *);

int		my_strcmp(char *, char *);

#endif /* !TETRIS_H_ */
