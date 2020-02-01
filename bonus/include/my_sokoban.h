/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct map_s map_s;

struct map_s {
    int w;
    int h;
};

typedef struct entity entity;

struct entity {
    char c;
    int x;
    int y;
};

bool my_sokoban(sfRenderWindow *window, sfEvent event, char *sokoban_map,
                int nb_boxes);

map_s get_size(char *sokoban_map);

void case_vide(char **map_2d, entity tab[], int nb_boxes);

entity get_position_player(char **map_2d);

void fill_entity(entity nb[], char **map_2d);

int game_status(char **map_2d, entity *nb, int nb_boxes, char *sokoban_map);

#endif /* !MY_SOKOBAN_H_ */