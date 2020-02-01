/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** other
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my_sokoban.h"
#include "my.h"

void msg_term(void)
{
    char *msg = "enlarge the terminal please";

    mvprintw(LINES / 2, COLS / 2 - 27 / 2, msg);
    refresh();
}

void start_game(entity *nb, char **map_2d)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    fill_entity(nb, map_2d);
}

void free_2d_array(char **map_2d)
{
    int i = 0;

    for (i = 0; map_2d[i] != NULL; i++)
        free(map_2d[i]);
    free(map_2d[i]);
    free(map_2d);
}