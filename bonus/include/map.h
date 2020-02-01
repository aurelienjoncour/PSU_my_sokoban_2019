/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>
#include "assets.h"

char *map(char const *filepath, int *nb_boxes);

void free_2d_array(char **map_2d);

int print_map(char **map_2d, entity *nb, int nb_boxes);

void draw_map(assets_t *image, char **map_2d, sfRenderWindow *window);

#endif /* !MAP_H_ */
