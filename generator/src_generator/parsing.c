/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** parsing
*/

#include "generator.h"

void get_default(int x, int y, generator_t *generate)
{
    int tmp = rand();
    int default_ = tmp % ((generate->x + generate->y) / 2) + 1;

    if (default_ == 1)
        generate->maze_tab[x][y] = WAY;
    else {
        generate->maze_tab[x][y] = '0';
        generate->maze_tab[x + 1][y] == WAY ? generate->maze_tab[x][y] =
        WALL : 0;
        generate->maze_tab[x][y + 1] == WAY ? generate->maze_tab[x][y] =
        WALL : 0;
        generate->maze_tab[x - 1][y] == WAY ? generate->maze_tab[x][y] =
        WALL : 0;
        generate->maze_tab[x][y - 1] == WAY ? generate->maze_tab[x][y] =
        WALL : 0;
    }
}

int default_maze(generator_t *generate)
{
    int res = 5;

    if (generate->maze_tab[generate->maze_x + 1][generate->maze_y] == 'P')
        return (default_end(generate->maze_x + 1, generate->maze_y, generate));
    if (generate->maze_tab[generate->maze_x][generate->maze_y + 1] == 'P')
        return (default_end(generate->maze_x, generate->maze_y + 1, generate));
    if (generate->maze_tab[generate->maze_x - 1][generate->maze_y] == 'P')
        return (default_end(generate->maze_x - 1, generate->maze_y, generate));
    if (generate->maze_tab[generate->maze_x][generate->maze_y - 1] == 'P')
        return (default_end(generate->maze_x, generate->maze_y - 1, generate));
    return (res);
}

int look_for_place(int end, int east, int west, generator_t *generate)
{
    end == west ? generate->maze_tab[generate->maze_x - 1][generate->maze_y]
    = 'P' : 0;
    end == east ? generate->maze_tab[generate->maze_x + 1][generate->maze_y]
    = 'P' : 0;

    if ((end = and_fnct(generate)) > 1 || end == 5)
        return (end);
    return (SUCCESS);
}

int parse_all(generator_t *generate)
{
    int end = 5;
    int result = 0;
    int north = 0;
    int south = 0;
    int east = 0;
    int west = 0;
    generate->maze_tab[generate->maze_x + 1][generate->maze_y] == '0'
    ? east = result += 1 : 0;
    generate->maze_tab[generate->maze_x][generate->maze_y + 1] == '0'
    ? north = result += 1 : 0;
    generate->maze_tab[generate->maze_x - 1][generate->maze_y] == '0'
    ? west = result += 1 : 0;
    generate->maze_tab[generate->maze_x][generate->maze_y - 1] == '0'
    ? south = result += 1 : 0;
    result != 0 ? end = rand() % result + 1 : 0;
    end == south ? generate->maze_tab[generate->maze_x][generate->maze_y - 1]
    = 'P' : 0;
    end == north ? generate->maze_tab[generate->maze_x][generate->maze_y + 1]
    = 'P' : 0;
    return (end = look_for_place(end, east, west, generate));
}

int maze_parsing(generator_t *generator)
{
    linked_t *list = EMPTY;
    int result = 0;
    int a = 0;

    if (init_list(&generator->linked, generator) == -1)
        return (-1);
    generator->maze_tab[generator->maze_x][generator->maze_y] = WAY;
    while ((result = parse_all(generator)) != SUCCESS) {
        if (result == 5) {
            list = generator->linked;
            generator->linked = generator->linked->head;
            free_fcnt(list);
            if (!generator->linked)
                break;
            generator->maze_y = generator->linked->p[1];
            generator->maze_x = generator->linked->p[0];
        }
        a += 1;
    }
    return (SUCCESS);
}
