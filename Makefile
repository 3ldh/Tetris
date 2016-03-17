##
## Makefile for Makefile in /home/mmaud/Rendu/Semestre_2/System_Unix/
##
## Made by Maud MAREL
## Login   <marel_m@epitech.net>
##
## Started on  Sun Jan 31 11:11:37 2016 Maud MAREL
## Last update Thu Mar 17 12:22:55 2016 Mathieu Sauvau
##

NAME		=	tetris

ARGS		=	srcs/actions_arg/

DISP		=	srcs/display/

OPTS		=	srcs/change_options/

TETRI		=	srcs/stock_check_tetriminos/

FREE		=	srcs/free/

SRCS		=	srcs/main.c \
			$(ARGS)get_next_line.c \
			$(ARGS)check_arg.c \
			$(ARGS)read_arg.c \
			$(ARGS)init_options.c \
			$(ARGS)verif_size_all.c \
			$(DISP)display_help.c \
			$(DISP)display_help_error.c \
			$(DISP)display_debug.c \
			$(DISP)display_debug_key.c \
			$(OPTS)change_key_drop.c \
			$(OPTS)change_key_left.c \
			$(OPTS)change_key_pause.c \
			$(OPTS)change_key_quit.c \
			$(OPTS)change_key_right.c \
			$(OPTS)change_key_turn.c \
			$(OPTS)change_level.c \
			$(OPTS)change_map_size.c \
			$(OPTS)hide_next.c \
			$(OPTS)wrong_options.c \
			srcs/ncurses/init.c \
			srcs/ncurses/movement.c \
			srcs/ncurses/collision.c \
			srcs/ncurses/print_game.c \
			srcs/ncurses/mechanic.c \
			srcs/ncurses/main_loop.c \
			srcs/ncurses/purge_tetri.c \
			srcs/ncurses/key.c \
			srcs/ncurses/key2.c \
			srcs/ncurses/cpy_tetri.c \
			srcs/ncurses/rotate.c \
			srcs/ncurses/get_star.c \
			srcs/ncurses/re_init.c \
			$(TETRI)check_tetriminos.c \
			$(TETRI)stock.c \
			$(TETRI)put_in_list.c \
			$(TETRI)stock_tetrimino.c \
			$(FREE)free_options.c \
			$(FREE)free_struct.c \

OBJS		=	$(SRCS:.c=.o)

LDFLAGS		=	-Llib -lmy -lncurses

CFLAGS		+=	-W -Wall -Wextra

CFLAGS		+=	-Iinclude/

CFLAGS		+=	$(LIBS)

FLAGS		=	$(LDFLAGS)

CC		=	gcc

RM		=	rm -f

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(FLAGS)

all:			$(NAME)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
