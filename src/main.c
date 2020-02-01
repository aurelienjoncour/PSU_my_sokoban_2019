/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"
#include "my_sokoban.h"
#include "map.h"

static size_t usage(int exit_status)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, containing '#'");
    my_putstr(" for walls, \n");
    my_putstr("         'P' for the player, 'X' for boxes and 'O' for storage");
    my_putstr(" locations.\n");
    return exit_status;
}

int main(int ac, char **av)
{
    char *sokoban_map;
    int nb_boxes;

    if (ac < 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h')
        return usage(0);
    sokoban_map = map(av[1], &nb_boxes);
    if (sokoban_map == NULL)
        return 84;
    my_sokoban(sokoban_map, nb_boxes, get_size(sokoban_map));
    return 0;
}