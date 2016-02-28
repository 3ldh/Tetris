##
## Makefile for Makefile in /home/mmaud/Rendu/Semestre_2/System_Unix/
##
## Made by Maud MAREL
## Login   <marel_m@epitech.net>
##
## Started on  Sun Jan 31 11:11:37 2016 Maud MAREL
## Last update Sun Feb 28 23:04:10 2016 maud marel
##

NAME		=	tetris

OPTS		=	srcs/change_options/

SRCS		=	srcs/main.c \
			srcs/check_arg.c \
			srcs/display_help.c \
			srcs/init_options.c \
			srcs/mode_debug/display_debug.c \
			$(OPTS)change_key_drop.c \
			$(OPTS)change_key_left.c \
			$(OPTS)change_key_pause.c \
			$(OPTS)change_key_quit.c \
			$(OPTS)change_key_right.c \
			$(OPTS)change_key_turn.c \
			$(OPTS)change_level.c \
			$(OPTS)change_map_size.c \
			$(OPTS)change_without_next.c \

OBJS		=	$(SRCS:.c=.o)

LDFLAGS		=	-Llib -lmy

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
