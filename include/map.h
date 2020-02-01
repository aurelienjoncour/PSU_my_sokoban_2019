/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

char *map(char const *filepath, int *nb_boxes);

void free_2d_array(char **map_2d);

void print_map(char **map_2d, entity *nb, int nb_boxes, char *sokoban_map);

#endif /* !MAP_H_ */
