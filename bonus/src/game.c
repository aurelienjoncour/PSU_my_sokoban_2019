/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "my_sokoban.h"
#include "other.h"

static bool horizontal_move(char **map_2d, int i, int j)
{
    if ((map_2d[i - 1][j] == '#' || map_2d[i - 1][j] == 'X')
        && (map_2d[i][j - 1] == '#' || map_2d[i][j - 1] == 'X'))
        return true;
    else if ((map_2d[i + 1][j] == '#' || map_2d[i + 1][j] == 'X')
            && (map_2d[i][j + 1] == '#' || map_2d[i][j + 1] == 'X'))
        return true;
    else
        return false;
}

static bool vertical_move(char **map_2d, int i, int j)
{
    if ((map_2d[i - 1][j] == '#' || map_2d[i - 1][j] == 'X') &&
        (map_2d[i][j + 1] == '#' || map_2d[i][j + 1] == 'X'))
        return true;
    else if ((map_2d[i + 1][j] == '#' || map_2d[i + 1][j] == 'X') &&
            (map_2d[i][j - 1] == '#' || map_2d[i][j - 1] == 'X'))
        return true;
    else
        return false;
}

bool loose(char **map_2d, int nb_boxes)
{
    int bad_boxes = 0;

    for (int i = 0; map_2d[i] != NULL; i++)
        for (int j = 0; map_2d[i][j] != '\0'; j++)
            if (map_2d[i][j] == 'X')
                if (vertical_move(map_2d, i, j) ||
                    horizontal_move(map_2d, i, j))
                    bad_boxes++;
    if (bad_boxes == nb_boxes)
        return true;
    return false;
}

bool win(char **map_2d, entity tab[], int nb_boxes)
{
    int good_boxes = 0;

    for (int i = 0; map_2d[i] != NULL; i++) {
        for (int j = 0; map_2d[i][j] != '\0'; j++) {
            if (map_2d[i][j] == 'X' && tab[good_boxes].x == j &&
                tab[good_boxes].y == i)
                good_boxes++;
        }
    }
    if (good_boxes == nb_boxes)
        return true;
    return false;
}

bool keep_open(char **map_2d, entity tab[], int nb_boxes, bool *win_condition)
{
    if (win(map_2d, tab, nb_boxes)){
        *win_condition = true;
        return false;
    }
    if (loose(map_2d, nb_boxes))
        return false;
    return true;
}