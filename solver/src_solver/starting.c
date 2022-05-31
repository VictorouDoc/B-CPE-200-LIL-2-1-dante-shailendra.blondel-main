/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** parsing
*/

#include "solver.h"

int start_solving(int x, int y, solver_t *solv)
{
    if (solv->tab[solv->y - 1][solv->x - 1] == 'o')
        return (SUCCESS);
    if (verif_if_end(x, y, solv) != false) {
        solv->tab[y][x] = 'o';
        if (start_solving(x + 1, y, solv) == SUCCESS)
            return (SUCCESS);
        if (start_solving(x, y + 1, solv) == SUCCESS)
            return (SUCCESS);
        if (start_solving(x - 1, y, solv) == SUCCESS)
            return (SUCCESS);
        if (start_solving(x, y - 1, solv) == SUCCESS)
            return (SUCCESS);
        solv->tab[y][x] = '*';
        return (-1);
    }
    return (-1);
}
