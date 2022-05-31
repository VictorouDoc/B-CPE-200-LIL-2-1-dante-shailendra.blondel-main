##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SOLVER	=	src_solver

SRC	=	$(SOLVER)/main.c	\
		$(SOLVER)/solver.c	\
		$(SOLVER)/init.c \
		$(SOLVER)/get_maze.c \
		$(SOLVER)/starting.c \
		$(SOLVER)/write.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

RM	=	rm -f

INCLUDE	=	-I ../include -o

NAME	=	solver

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
