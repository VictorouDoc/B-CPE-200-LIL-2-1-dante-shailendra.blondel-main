/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-shailendra.blondel
** File description:
** generator
*/

#include <time.h>
#include <stdbool.h>
#include "generator_struct.h"
#include "my_get_nl.h"

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    #define SUCCESS (int) 0
    #define FAILURE (int) 84
    #define EMPTY NULL
    #define BAD_ARGS "ERROR: wrong arguments\nTry '-h' for help.\n"
    #define BAD_MALLOC "ERROR: malloc failed.\n"
    #define WAY '*'
    #define WALL 'X'

int check_args(int n_args, char **args);

void write_error(char *error);

generator_t *initialize_generator(int nb_args, char **args);

int get_maze(generator_t *generate);

int maze_parsing(generator_t *generator);

int init_list(linked_t **linked, generator_t *generate);

int parse_all(generator_t *generate);

int and_fnct(generator_t *generate);

int end_fnct(int x, int y, generator_t *generate);

int default_maze(generator_t *generate);

int default_end(int x, int y, generator_t *generate);

void get_default(int x, int y, generator_t *generate);

void write_my_maze(generator_t *generate);

void check_validity(generator_t *generate);

void show_array(generator_t *generate);

char *result_app(int occu, char *tab);

void free_all(generator_t *generate);

void free_fcnt(linked_t *list);

#endif
