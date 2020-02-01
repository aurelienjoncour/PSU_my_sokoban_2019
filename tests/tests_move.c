/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tests_game
*/

#include <criterion/criterion.h>
#include <ncurses.h>
#include "my_sokoban.h"
#include "move_player.h"

Test(sokoban, move_player)
{
    char **map_2d = malloc(sizeof(char *) * 6);
    entity player = {0, 2, 2};

    map_2d[0] = strdup("#####");
    map_2d[1] = strdup("#   #");
    map_2d[2] = strdup("# P #");
    map_2d[3] = strdup("#   #");
    map_2d[4] = strdup("#####");
    map_2d[5] = NULL;
    event_keyboard(map_2d, &player, KEY_LEFT);
    cr_assert_str_eq(map_2d[2], "#P  #");
    event_keyboard(map_2d, &player, KEY_RIGHT);
    cr_assert_str_eq(map_2d[2], "# P #");
    event_keyboard(map_2d, &player, KEY_UP);
    cr_assert_str_eq(map_2d[1], "# P #");
    event_keyboard(map_2d, &player, KEY_DOWN);
    cr_assert_str_eq(map_2d[2], "# P #");
}

Test(sokoban, player_move_box)
{
    char **map_2d = malloc(sizeof(char *) * 7);

    map_2d[0] = strdup("#######");
    map_2d[1] = strdup("#  O  #");
    map_2d[2] = strdup("#  X  #");
    map_2d[3] = strdup("#  PXO#");
    map_2d[4] = strdup("# OXX #");
    map_2d[5] = strdup("#   O #");
    map_2d[6] = strdup("#######");
    event_keyboard(map_2d, &(entity){0, 3, 3}, KEY_RIGHT);
    cr_assert_str_eq(map_2d[3], "#   PX#");
    event_keyboard(map_2d, &(entity){0, 4, 3}, KEY_DOWN);
    cr_assert_str_eq(map_2d[5], "#   X #");
    event_keyboard(map_2d, &(entity){0, 4, 4}, KEY_LEFT);
    cr_assert_str_eq(map_2d[4], "# XP  #");
    event_keyboard(map_2d, &(entity){0, 3, 4}, KEY_UP);
    event_keyboard(map_2d, &(entity){0, 3, 3}, KEY_UP);
    cr_assert_str_eq(map_2d[1], "#  X  #");
    cr_assert_str_eq(map_2d[2], "#  P  #");
}

Test(sokoban, space_bar)
{
    cr_assert_eq(event_keyboard(NULL, NULL, 32), 32);
}