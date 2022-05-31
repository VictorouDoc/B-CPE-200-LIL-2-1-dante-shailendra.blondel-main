/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** solver
*/

#include "solver.h"

void free_all(solver_t *solv)
{
    int free_var = 0;

    while (solv->tab[free_var] != EMPTY) {
        free(solv->tab[free_var]);
        free_var += 1;
    }
    free(solv->tab);
    free(solv->maze);
    free(solv);
}

int solver(char **av)
{
    solver_t *solv = init_solver(av);
    int maze_width = 0;
    int maze_height = 0;

    if (solv == EMPTY)
        return (-1);
    if (my_maze(solv->x, solv->y, solv->tab) == -1) {
        write_error(NO_SOLUTION);
        return (-1);
    }
    start_solving(maze_width, maze_height, solv);
    my_show_array(solv->tab);
    free_all(solv);
    return (SUCCESS);
}
