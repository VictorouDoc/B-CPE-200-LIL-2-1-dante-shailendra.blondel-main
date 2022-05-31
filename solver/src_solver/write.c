/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** write
*/

#include "solver.h"

void write_fcnt(char *what, int i)
{
    if (i == 0)
        write(1, what, my_strlen(what));
    else {
        write(1, what, my_strlen(what));
        my_putchar('\n');
    }
}

void my_show_array(char **array)
{
    int var = 0;
    int see_after = 1;

    while (array[var]) {
        if (array[var + see_after])
            write_fcnt(array[var], see_after);
        if (!array[var + see_after])
            write_fcnt(array[var], 0);
        var += 1;
    }
}

void write_error(char *error)
{
    write(2, error, my_strlen(error));
}

void usage_fct(void)
{
    my_printf("USAGE:\n\t./solver maze.txt\nDESCRIPTION:\n\t");
    my_printf("Print solved maze on the standard output.\n");
    my_printf("\tIf there is no solution it prints ""no solution"" on");
    my_printf(" the same output.\n");
}
