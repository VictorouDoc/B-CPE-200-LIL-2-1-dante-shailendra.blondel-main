/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** get_maze
*/

#include "solver.h"

bool verif_if_end(int x, int y, solver_t *solv)
{
    if (x < solv->x && y < solv->y && x >= 0 && y >= 0 &&
    solv->tab[y][x] == '*')
        return (true);
    return (false);
}

int verif_content(int i, int j, char **tab)
{
    if (tab[i][j] != 'X' && tab[i][j] != '*' &&
    tab[i][j] != '\n')
        return (-1);
    return (SUCCESS);
}

int my_maze(int x, int y, char **tab)
{
    int i = 0;
    int j = 0;
    int result = 0;

    while (tab[i] != EMPTY) {
        while (tab[i][j] != '\0') {
            result = verif_content(i, j, tab);
            j += 1;
        }
        i += 1;
    }
    if (tab[x - 1][y - 1] != '*' || tab[0][0] != '*')
        result = -1;
    if (result == -1)
        return (-1);
    return (SUCCESS);
}

int get_tab_length(char **tab)
{
    int len = 0;

    while (tab[len] != EMPTY) {
        len += 1;
    }
    return (len);
}

buffer_t *get_maze(char **av)
{
    buffer_t *maze = EMPTY;
    struct stat sb;

    if ((maze = malloc(sizeof(buffer_t))) == EMPTY) {
        write_error(BAD_MALLOC);
        return (EMPTY);
    }
    maze->fd = open(av[1], O_RDONLY);
    if (stat(av[1], &sb) == -1) {
        write_error(BAD_MAZE);
        return (EMPTY);
    }
    maze->bytes = sb.st_size;
    maze->buffer = malloc((maze->bytes + 1) * sizeof(char));
    maze->size = read(maze->fd, maze->buffer, maze->bytes);
    maze->buffer[maze->bytes] = '\0';
    return (maze);
}
