##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:
	make all -C ./lib/my/
	make all -C ./generator/
	make all -C ./solver/

clean:
	make clean -C ./lib/my/
	make clean -C ./generator/
	make clean -C ./solver/

fclean: clean
	make fclean -C ./lib/my/
	make fclean -C ./generator/
	make fclean -C ./solver/

re: fclean all
