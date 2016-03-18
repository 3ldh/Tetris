##
## Makefile for Makefile in /PSU_2015_my_printf/lib/my
##
## Made by maud marel
## Login   <marel_m@epitech.net>
##
## Started on  Mon Nov  9 09:47:52 2015 maud marel
## Last update Fri Mar 18 14:31:59 2016 
##

SRC	=	my_putstr_error.c \
		my_putchar.c \
		my_putchar_error.c \
		my_power_rec.c \
		my_strlen.c \
		my_strcmp.c \
		my_strncmp.c \
		my_getnbr.c \
		my_strcpy.c \
		my_strdup.c \
		my_put_nbr.c \
		my_strncpy.c \
		my_strcat.c \
		my_strncat.c \
		my_realloc.c \
		my_putstr.c \

RM	=	rm -f

NAME	=	libmy.a

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
		ar rc libmy.a $(OBJ)
		ranlib libmy.a
		cp libmy.a ../

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
