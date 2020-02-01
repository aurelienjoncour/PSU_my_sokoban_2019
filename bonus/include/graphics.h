/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** graphics
*/

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include "assets.h"

void draw_map(assets_t *image, char **map_2d, sfRenderWindow *window);

void destroy_ressource(assets_t *image, char **map_2d, char *sokoban);

assets_t *load_sprite(void);

void destroy_ressource(assets_t *image, char **map_2d, char *sokoban);

#endif /* !GRAPHICS_H_ */
