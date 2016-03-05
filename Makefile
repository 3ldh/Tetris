##
## Makefile for Makefile in /home/mmaud/Rendu/Semestre_2/System_Unix/
##
## Made by Maud MAREL
## Login   <marel_m@epitech.net>
##
## Started on  Sun Jan 31 11:11:37 2016 Maud MAREL
## Last update Sat Mar  5 09:11:22 2016 maud marel
##

NAME		=	tetris

DISP		=	srcs/display/

OPTS		=	srcs/change_options/

TETRI		=	srcs/stock_check_tetriminos/

SRCS		=	srcs/main.c \
			srcs/check_arg.c \
			srcs/init_options.c \
			srcs/get_next_line.c \
			srcs/verif_size_all.c \
			$(DISP)display_help.c \
			$(DISP)display_help_error.c \
			$(DISP)display_debug.c \
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
			$(TETRI)check_tetriminos.c \
			$(TETRI)stock.c \
			$(TETRI)put_in_list.c \
			$(TETRI)stock_tetrimino.c \

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
