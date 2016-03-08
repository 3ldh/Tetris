 /*
** tetris.h for tetris in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:25:21 2016 maud marel
** Last update Tue Mar  8 09:18:38 2016 maud marel
*/

#ifndef TETRIS_H_
# define TETRIS_H_
# define UNUSED __attribute__((__unused__))

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

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
    NEXT_S,
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
    MAX_CHECK_OPT_SIMP
  };

typedef	struct	s_tetrimino
{
  int		max;
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
  t_tetri			*tetrimino;
  int				nb_tetri;
  struct s_list_tetrimino	*next;
  struct s_list_tetrimino	*prev;
}				t_list_tetri;

typedef struct	s_options
{
  int		level;
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
  char		**board;
  int		high_score;
  int		score;
  int		lines;
  int		start_time;
  int		time;
  int		level;
  float		speed;
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

/*
** Init list
*/

t_list_tetri	*add_list_before(t_list_tetri *);
t_list_tetri	*which_order(t_tetris *, char *);
void		create_list(t_tetris *);

/*
** Stock infos
*/

int		check_form(t_list_tetri *, int);
int		stock(char *, t_tetris *, int, char *);
void		check_tetriminos(t_tetris *);
void		init_tetris(t_tetris *);

/*
** Change options
*/

void		check_arg(t_tetris *, int, char **);
void		read_arg(t_tetris *, int, char **);
int		check_complex_arg(t_tetris *, char *);
int		check_simp_arg(t_tetris *, char *, char *);
void		change_level(t_tetris *, char *);
void		change_key_left(t_tetris *, char *);
void		change_key_right(t_tetris *, char *);
void		change_key_turn(t_tetris *, char *);
void		change_key_drop(t_tetris *, char *);
void		change_key_quit(t_tetris *, char *);
void		change_key_pause(t_tetris *, char *);
void		change_map_size(t_tetris *, char *);
void		hide_next(t_tetris *, char *);
void		change_without_next(t_tetris *, char *);
void		change_level_simp(t_tetris *, char *);
void		change_key_left_simp(t_tetris *, char *);
void		change_key_right_simp(t_tetris *, char *);
void		change_key_turn_simp(t_tetris *, char *);
void		change_key_drop_simp(t_tetris *, char *);
void		change_key_quit_simp(t_tetris *, char *);
void		change_key_pause_simp(t_tetris *, char *);
void		change_without_next_simp(t_tetris *, char *);
void		wrong_options(char *);
void		verif_size_all(t_tetris *);

/*
** Display
*/

void		display_debug(t_tetris *, int);
void		display_debug_key(char *);
void		display_key(t_tetris *);
void		display_help(char *);
void		display_help_error();

/*
** Fonctions Lib
*/

char		*get_next_line(const int);
char		*my_realloc(char *, int);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
int		my_strlen(char *);
int		my_put_nbr(int);
void		my_putchar(char);
void		my_putstr(char *);
int		my_getnbr(char *);
char		*my_strcat(char *, char *);
void		my_putstr_error(char *);
void		my_putchar_error(char);
void		mode_canon(int i, int time, int nb_char);

/*
**GAME PART
*/
WINDOW		*create_newwin(int, int, int, int);
void		show_score(WINDOW *, t_tetris *);
void		init_tetri(t_tetri *tetri);
void		print_tetri(WINDOW *game, t_tetri *tetri);
void		check_color();
void		print_game(WINDOW *game, t_tetris *data, t_tetri *tetri);
bool		space_occupied_down(t_tetris *data, t_tetri *tetri);
bool		space_occupied_right(t_tetris *data, t_tetri *tetri);
bool		space_occupied_left(t_tetris *data, t_tetri *tetri);
bool		can_move_left(t_tetris *data, t_tetri *tetri);
bool		can_move_right(t_tetris *data, t_tetri *tetri);
t_list_tetri	*add_tetri(t_list_tetri *list, t_tetri *tetri);
int		max_tetri(t_list_tetri *list_tetri);
t_tetri		*cpy_tetri(t_tetri *tetri);
t_tetri		*random_tetri(t_list_tetri *list_tetri, int nb_tetri);
bool		can_move_down(t_tetris *data, t_tetri *tetri);
void		show_next(WINDOW *wnext,t_tetri *next);
void		update_board(t_tetris *tetris, t_tetri *tetri);
void		clear_line(t_tetris *data, int line);
void		fall(WINDOW *game, t_tetris *data);
void		line_completion(t_tetris *data, WINDOW *game);
t_list_tetri	*get_valid_tetri(t_list_tetri *all_tetri);
t_tetri		*rotate_tetri(t_tetri *tetri);
void		loop(WINDOW *game, WINDOW *score, WINDOW *wnext,
		     t_tetris *tetris);
void		loop(WINDOW *game, WINDOW *score, WINDOW *wnext,
		     t_tetris *tetris);
void		init_ncurses();
char		**init_board(t_tetris *tetris);
void		init_score(t_tetris *data);
void		center_tetri(t_list_tetri *list_tetri);
bool		check_window(t_tetris *tetris);
int		get_first_star_on_x(t_tetri *tetri);

#endif /* !TETRIS_H_ */
