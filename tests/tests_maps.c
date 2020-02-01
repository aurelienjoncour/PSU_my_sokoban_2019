/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tests_maps
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include "my_sokoban.h"
#include "map.h"

Test(map, open_map_without_error)
{
    int nb_boxes = 0;
    char *map_sokoban = map("map", &nb_boxes);

    cr_assert_str_eq(map_sokoban, "#####\n#PXO#\n#####\n");
}

Test(map, error_char)
{
    int nb_boxes = 0;
    char *map_sokoban = map("map_error", &nb_boxes);

    cr_assert_eq(map_sokoban, NULL);
}

Test(map, to_many_player)
{
    int nb_boxes = 0;
    char *map_sokoban = map("map_player", &nb_boxes);

    cr_assert_eq(map_sokoban, NULL);
}

Test(map, no_files)
{
    int nb_boxes = 0;
    char *map_sokoban = map("pasmap", &nb_boxes);
    char *vide = map("map_empty", &nb_boxes);

    cr_assert_eq(map_sokoban, NULL);
    cr_assert_eq(vide, NULL);
}

Test(map, fill_O)
{
    char **map_2d = malloc(sizeof(char * ) * 4);
    entity *nb = malloc(sizeof(entity) * 1);

    nb[0].c = 1;
    nb[0].x = 1;
    nb[0].y = 1;
    map_2d[0] = strdup("#####");
    map_2d[1] = strdup("# P #");
    map_2d[2] = strdup("#####");
    map_2d[3] = NULL;
    case_vide(map_2d, nb, 1);
    cr_assert_str_eq(map_2d[1], "#OP #");
}