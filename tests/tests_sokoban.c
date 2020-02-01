/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tests_game
*/

#include <criterion/criterion.h>
#include "my_sokoban.h"
#include "game.h"

Test(sokoban, check_position_player)
{
    char *map_2d[5] = {"#####", "#XPO#", "#   #", "#####"};
    entity pos = get_position_player(map_2d);

    cr_assert_eq(pos.y, 1);
    cr_assert_eq(pos.x, 2);
}

Test(sokoban, check_size_map)
{
    char *map = "#####\n#PX0#\n#####\n";
    map_s size = get_size(map);

    cr_assert_eq(size.h, 3);
    cr_assert_eq(size.w, 6);
}

Test(sokoban, check_box_pos)
{
    char *map_2d[5] = {"#####", "#PXO#", "#OX #", "#####"};
    entity nb[2] = {0};

    fill_entity(nb, map_2d);
    cr_assert_eq(nb[0].x, 3);
    cr_assert_eq(nb[0].y, 1);
    cr_assert_eq(nb[1].x, 1);
    cr_assert_eq(nb[1].y, 2);
}

Test(sokoban, game_win)
{
    char **map_2d = malloc(sizeof(char * ) * 4);
    entity *nb = malloc(sizeof(entity) * 1);
    char *map = "#####\n#XP #\n#####\n";

    nb[0].c = 1;
    nb[0].x = 1;
    nb[0].y = 1;
    map_2d[0] = strdup("#####");
    map_2d[1] = strdup("#XP #");
    map_2d[2] = strdup("#####");
    map_2d[3] = NULL;
    cr_assert_eq(game_status(map_2d, nb, 1, strdup(map)), 0);
}

Test(sokoban, game_loose)
{
    char **map_2d = malloc(sizeof(char * ) * 4);
    entity *nb = malloc(sizeof(entity) * 1);
    char *map = "#####\n#PXO#\n#####\n";

    nb[0].c = 1;
    nb[0].x = 1;
    nb[0].y = 1;
    map_2d[0] = strdup("#####");
    map_2d[1] = strdup("#OXP#");
    map_2d[2] = strdup("#####");
    map_2d[3] = NULL;
    cr_assert_eq(game_status(map_2d, nb, 1, strdup(map)), 1);
}