/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** solver
*/

#ifndef _SOLVER_STRUCT_H_
    #define _SOLVER_STRUCT_H_

typedef struct buffer {
    int bytes;
    char *buffer;
    int fd;
    int size;
}buffer_t;

typedef struct solver {
    buffer_t *maze;
    int x;
    int y;
    char **tab;
}solver_t;

#endif
