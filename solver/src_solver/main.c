/*
** EPITECH PROJECT, 2022
** Makefile
** File description:
** main
*/

#include "solver.h"

int main (int ac, char **av)
{
    if (ac != 2) {
        my_printf("Must Contain a map.\n");
        return (FAILURE);
    }
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        usage_fct();
        return (SUCCESS);
    }
    if (solver(av) == -1)
        return (FAILURE);
    return (SUCCESS);
}
