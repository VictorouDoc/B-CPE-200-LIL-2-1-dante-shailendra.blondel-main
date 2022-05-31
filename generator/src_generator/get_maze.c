/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** get_maze
*/

#include "generator.h"

void get_maze_end(generator_t *generate, int a, int c)
{
    generate->maze_tab[0][generate->y + 2] = '\0';
    while (a < generate->x + 1) {
        generate->maze_tab[a] = malloc(generate->y + 3);
        generate->maze_tab[a][0] = '1';
        c = 1;
        while (c <= generate->y) {
            generate->maze_tab[a][c] = '0';
            c++;
        }
        generate->maze_tab[a][generate->y + 1] = '1';
        generate->maze_tab[a][generate->y + 2] = '\0';
        a++;
    }
    generate->maze_tab[generate->x + 1] = malloc(generate->y + 3);
}

void place_fcnt(generator_t *generate, int d)
{
    while (d <= generate->y + 1) {
        generate->maze_tab[generate->x + 1][d] = '1';
        d++;
    }
    generate->maze_tab[generate->x + 1][generate->y + 2] = '\0';
    generate->maze_tab[generate->x + 2] = EMPTY;
}

int get_maze(generator_t *generate)
{
    int a = 1;
    int b = 0;
    int c = 1;
    int d = 0;

    if ((generate->maze_tab = malloc((generate->x + 3) * sizeof(char *))) ==
    EMPTY) {
        write_error(BAD_MALLOC);
        return (-1);
    }
    generate->maze_tab[0] = malloc(generate->y + 3);
    while (b <= generate->y + 1) {
        generate->maze_tab[0][b] = '1';
        b++;
    }
    get_maze_end(generate, a, c);
    place_fcnt(generate, d);
    return (SUCCESS);
}
