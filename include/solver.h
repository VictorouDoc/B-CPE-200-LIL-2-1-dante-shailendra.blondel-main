/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** solver
*/

#include "my_get_nl.h"
#include "solver_struct.h"
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#ifndef SOLVER_H_
    #define SOLVER_H_

    #define SUCCESS (int) 0
    #define FAILURE (int) 84
    #define EMPTY NULL
    #define BAD_MALLOC "ERROR: malloc failed.\n"
    #define BAD_MAZE "ERROR: unable to open maze.\n"
    #define INVALID_MAZE "ERROR: invalid maze.\n"
    #define NO_SOLUTION "no solution found\n"

void usage_fct(void);

int solver(char **av);

void write_error(char *error);

solver_t *init_solver(char **av);

buffer_t *get_maze(char **av);

int get_tab_length(char **tab);

int my_maze(int x, int y, char **tab);

int start_solving(int x, int y, solver_t *solv);

bool verif_if_end(int x, int y, solver_t *solv);

void my_show_array(char **array);

#endif
