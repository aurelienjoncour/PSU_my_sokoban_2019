/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include <stdbool.h>

bool win(char **map_2d, entity tab[], int nb_boxes);

bool loose(char **map_2d, int nb_boxes);

bool keep_open(char **map_2d, entity tab[], int nb_boxes, bool *win_condition);

#endif /* !GAME_H_ */