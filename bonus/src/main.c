/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "my_sokoban.h"
#include "map.h"
#include "other.h"

static size_t usage(int exit_status)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban $(find map_directory/)\n");
    my_putstr("WARNING / IMPORTANT\n");
    my_putstr("The map file must represetant a 10x10 map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, containing '#'");
    my_putstr(" for walls, \n");
    my_putstr("         'P' for the player, 'X' for boxes and 'O' for storage");
    my_putstr(" locations.\n");
    return exit_status;
}

int lvl_loop(int ac, char **av)
{
    char *sokoban_map;
    int nb_boxes;
    int i = 2;
    sfRenderWindow *window = create_windows(640, 640);
    sfEvent event;
    map_s size;

    if (!window)
        return 84;
    do {
        sokoban_map = map(av[i], &nb_boxes);
        if (sokoban_map == NULL)
            return 84;
        size = get_size(sokoban_map);
        if (size.w < 10 && size.h < 10)
            return 84;
        i++;
    } while (my_sokoban(window, event, sokoban_map, nb_boxes) && i < ac);
    sfRenderWindow_destroy(window);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h')
        return usage(0);
    lvl_loop(ac, av);
    return 0;
}
