/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** write
*/

#include "generator.h"

void write_my_maze(generator_t *generate)
{
    int tmp = 1;

    if ((generate->maze_tab[generate->x - 1][generate->y] == '0'
    || generate->maze_tab[generate->x - 1][generate->y] == WALL)
    && (generate->maze_tab[generate->x][generate->y - 1] == '0'
    || generate->maze_tab[generate->x][generate->y - 1] == WALL)) {
        while ((generate->maze_tab[generate->x][generate->y - tmp]
        == '0' || generate->maze_tab[generate->x][generate->y - tmp]
        == WALL) && tmp > 0) {
            generate->maze_tab[generate->x][generate->y - tmp] = WAY;
            tmp += 1;
        }
    }
    generate->maze_tab[generate->x][generate->y] = WAY;
    check_validity(generate);
    return (show_array(generate));
}

void *my_memset(void *string, int character, unsigned int nb_time)
{
    char *changer = (char *) string;

    for (unsigned int i = 0; i < nb_time; i++)
        changer[i] = (unsigned char) character;
    return (string);
}

void write_error(char *error)
{
    write(2, error, my_strlen(error));
}
