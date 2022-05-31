/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** checker
*/

#include "generator.h"

char *result_app(int occu, char *tab)
{
    int res = 0;
    char *result = malloc(my_strlen(tab) + 1);

    while (tab[occu] != '\0') {
        tab[occu] == '0' ? tab[occu] = WALL : 0;
        result[res] = tab[occu];
        occu += 1;
        res += 1;
    }
    result[res] = '\0';
    return (result);
}

void check_validity(generator_t *generate)
{
    if (generate->maze_tab[generate->x - 1][generate->y - 1] == WAY
    && generate->maze_tab[generate->x][generate->y - 1] == WAY
    && generate->maze_tab[generate->x - 1][generate->y] == WAY
    && generate->maze_tab[generate->x][generate->y] == WAY)
        generate->maze_tab[generate->x - 1][generate->y - 1] = WALL;
}

int and_fnct(generator_t *generate)
{
    if (generate->len_arg == 3)
        return (default_maze(generate));
    if (generate->len_arg == 4) {
        if (generate->maze_tab[generate->maze_x + 1][generate->maze_y] == 'P')
            return (end_fnct(generate->maze_x + 1, generate->maze_y, generate));
        if (generate->maze_tab[generate->maze_x][generate->maze_y + 1] == 'P')
            return (end_fnct(generate->maze_x, generate->maze_y + 1, generate));
        if (generate->maze_tab[generate->maze_x - 1][generate->maze_y] == 'P')
            return (end_fnct(generate->maze_x - 1, generate->maze_y, generate));
        if (generate->maze_tab[generate->maze_x][generate->maze_y - 1] == 'P')
            return (end_fnct(generate->maze_x, generate->maze_y - 1, generate));
    }
    return (5);
}

int check_if_nb(char *value)
{
    for (; *value; value++)
        if (!(*value >= '0' && *value <= '9'))
            return (0);
    return (1);
}

int check_args(int n_args, char **args)
{
    if (!((n_args == 3   || n_args == 4) && check_if_nb(args[1]) == 1 &&
    check_if_nb(args[2]) == 1))
        return (-1);
    if (n_args == 4 && !(my_strcomp(args[3], "perfect") == 0 ||
    my_strcomp(args[3], "imperfect") == 0))
        return (-1);
    return (SUCCESS);
}
