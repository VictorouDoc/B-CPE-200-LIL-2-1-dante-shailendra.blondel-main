##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

GENERATOR	=	src_generator

SRC	=	$(GENERATOR)/main.c \
		$(GENERATOR)/checker.c \
		$(GENERATOR)/init.c \
		$(GENERATOR)/write.c \
		$(GENERATOR)/get_maze.c \
		$(GENERATOR)/parsing.c \
		$(GENERATOR)/show.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

RM	=	rm -f

INCLUDE	=	-I ../include -o

NAME	=	generator

LIB	=	-L ../lib/my/

LIBC	=	-lmy

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB) $(LIBC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
