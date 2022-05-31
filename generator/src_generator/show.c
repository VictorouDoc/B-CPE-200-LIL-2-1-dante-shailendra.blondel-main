/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** free
*/

#include "generator.h"

void free_fcnt(linked_t *list)
{
    free(list->p);
    free(list);
}

void free_all(generator_t *generate)
{
    int free_v = 0;
    free(generate->linked);

    while (generate->maze_tab[free_v]) {
        free(generate->maze_tab[free_v]);
        free_v += 1;
    }
    free(generate->maze_tab);
    free(generate);
}

void show_array(generator_t *generate)
{
    int show = 1;
    int tmp = generate->x;
    int tmp_s = generate->y + 1;
    char *result = EMPTY;

    while (generate->maze_tab[show + 1]) {
        generate->maze_tab[show][tmp_s] = '\n';
        show == tmp &&
        generate->maze_tab[show][tmp_s] == '\n' ? generate->maze_tab[show]
        [tmp_s] = '\0' : 0;
        result = result_app(1, generate->maze_tab[show]);
        write(1, result, my_strlen(result));
        free(result);
        show += 1;
    }
}
