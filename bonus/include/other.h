/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** other
*/

#ifndef OTHER_H_
#define OTHER_H_

#include "my_sokoban.h"
#include <SFML/Graphics.h>
#include <SFML/Config.h>

void msg_term(void);

void start_game(entity *nb, char **map_2d);

void free_2d_array(char **map_2d);

sfRenderWindow *create_windows(unsigned int w, unsigned int h);

void restart_game(char ***map_2d, char *map_sokoban, entity *player);

#endif /* !OTHER_H_ */
