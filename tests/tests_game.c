/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tests_game
*/

#include <criterion/criterion.h>
#include "my_sokoban.h"
#include "game.h"

Test(sokoban, check_loose)
{
    char *map_2d[5] = {"#####", "#XPO#", "#   #", "#####"};
    char *map_2d_1[5] = {"#####", "#   #", "#XPO#", "#####"};
    char *map_2d_2[5] = {"#####", "#OPX#", "#   #", "#####"};
    char *map_2d_3[5] = {"#####", "#   #", "#OPX#", "#####"};
    char *map_2d_4[5] = {"#####", "#   #", "#OXP#", "#####"};
    int nb_boxes = 1;

    cr_assert(loose(map_2d, nb_boxes));
    cr_assert(loose(map_2d_1, nb_boxes));
    cr_assert(loose(map_2d_2, nb_boxes));
    cr_assert(loose(map_2d_3, nb_boxes));
    cr_assert_not(loose(map_2d_4, nb_boxes));
}

Test(sokoban, check_win)
{
    char *map_2d[5] = {"#####", "#OXP#", "#   #", "#####"};
    char *map_2d_1[5] = {"#####", "#XP #", "#   #", "#####"};
    entity tab[1] = {{'P', 1, 1}};

    cr_assert(win(map_2d_1, tab, 1));
    cr_assert_not(win(map_2d, tab, 1));
}