/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** generator_struct
*/

#ifndef GENERATOR_STRUCT_H_
    #define GENERATOR_STRUCT_H_

typedef struct linked {
    int *p;
    struct linked *head;
    struct linked *tail;
}linked_t;

typedef struct generator {
    linked_t *linked;
    char **maze_tab;
    char **arg;
    int len_arg;
    int maze_x;
    int maze_y;
    int x;
    int y;
    int end;
}generator_t;

#endif
