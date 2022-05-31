/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** init
*/

#include "generator.h"

int init_list(linked_t **linked, generator_t *generate)
{
    linked_t *next = EMPTY;
    int *tmp = EMPTY;
    linked_t *prev = (*linked);

    if ((next = malloc(sizeof(linked_t))) == EMPTY
    || (tmp = malloc(sizeof(int) * 2)) == EMPTY) {
        write_error(BAD_MALLOC);
        return (-1);
    }
    tmp[1] = generate->maze_y;
    tmp[0] = generate->maze_x;
    next->tail = (*linked);
    next->p = tmp;
    (*linked) = next;
    (*linked)->head = prev;
    return (SUCCESS);
}

generator_t *initialize_generator(int nb_args, char **args)
{
    generator_t *generate = EMPTY;

    if ((generate =  malloc(sizeof(generator_t))) == EMPTY) {
        write_error(BAD_MALLOC);
        return (EMPTY);
    }
    generate->x = my_atoi(args[1]);
    generate->y = my_atoi(args[2]);
    if ((generate->x < 3) || (generate->y < 3)) {
        write_error("ERROR: x and y must be strictly greater than 2\n");
        return (EMPTY);
    }
    generate->maze_tab = EMPTY;
    generate->arg = args;
    generate->len_arg = nb_args;
    generate->maze_x = 1;
    generate->maze_y = 1;
    generate->end = 0;
    return (generate);
}
