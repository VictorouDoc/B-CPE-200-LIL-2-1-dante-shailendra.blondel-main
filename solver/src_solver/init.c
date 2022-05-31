/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** init
*/

#include "solver.h"

solver_t *init_solver(char **av)
{
    solver_t *solv = EMPTY;

    if ((solv = malloc(sizeof(solver_t))) == EMPTY) {
        write_error(BAD_MALLOC);
        return (EMPTY);
    }
    if ((solv->maze = get_maze(av)) == EMPTY)
        return (EMPTY);
    solv->tab = my_str_to_word_array(solv->maze->buffer, "\n");
    solv->y = my_strlen(solv->tab[0]);
    solv->x = get_tab_length(solv->tab);
    return (solv);
}
