/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "generator.h"

int default_end(int x, int y, generator_t *generate)
{
    int end_ = 0;
    generate->maze_tab[x + 1][y] == WAY ? end_ += 1 : 0;
    generate->maze_tab[x][y + 1] == WAY ? end_ += 1 : 0;
    generate->maze_tab[x - 1][y] == WAY ? end_ += 1 : 0;
    generate->maze_tab[x][y - 1] == WAY ? end_ += 1 : 0;

    if (end_ <= 1) {
        generate->maze_x = x;
        generate->maze_y = y;
    } else
        get_default(x, y, generate);
    return (end_);
}

int end_fnct(int x, int y, generator_t *generate)
{
    int end_ = 0;
    generate->maze_tab[x + 1][y] == WAY ? end_ += 1 : 0;
    generate->maze_tab[x][y + 1] == WAY ? end_ += 1 : 0;
    generate->maze_tab[x - 1][y] == WAY ? end_ += 1 : 0;
    generate->maze_tab[x][y - 1] == WAY ? end_ += 1 : 0;

    if (end_ <= 1) {
        generate->maze_x = x;
        generate->maze_y = y;
    } else
        generate->maze_tab[x][y] = WALL;
    return (end_);
}

int generation(generator_t *generate)
{
    srand(time(EMPTY));

    do {
        if (generate->end == 0) {
            generate->end = 1;
            generate->linked = EMPTY;
        }
        if (maze_parsing(generate) == -1)
            return (-1);
    }
    while (generate->linked);
    write_my_maze(generate);
    free_all(generate);
    return (SUCCESS);
}

int start_maze_generation(int n_args, char **args)
{
    generator_t *generate = EMPTY;

    if ((generate = initialize_generator(n_args, args)) == EMPTY)
        return (-1);
    if (get_maze(generate) == -1)
        return (-1);
    if (generation(generate) == -1)
        return (-1);
    return (SUCCESS);
}

int main (int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("USAGE:\n\t./generator x y [perfect]\nDESCRIPTION:\n\t");
        my_printf("As the perfect argument is optional, ");
        my_printf("the default generation will be imperfect maze.\n");
        return (SUCCESS);
    }
    if (check_args(ac, av) == -1) {
        my_printf(BAD_ARGS);
        return (FAILURE);
    }
    if (start_maze_generation(ac, av) == -1)
        return (FAILURE);
    return (SUCCESS);
}
