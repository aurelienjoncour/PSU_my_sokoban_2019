/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban
*/

#include <termios.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sokoban.h"
#include "move_player.h"
#include "game.h"
#include "map.h"
#include "other.h"
#include "my.h"

map_s get_size(char *sokoban_map)
{
    map_s size = {0};
    int tmp = 0;

    for (int i = 0; sokoban_map[i] != '\0'; i++) {
        tmp++;
        if (sokoban_map[i] == '\n') {
            if (tmp > size.w)
                size.w = tmp;
            size.h++;
            tmp = 0;
        }
    }
    return size;
}

void fill_entity(entity nb[], char **map_2d)
{
    int z = 0;

    for (int i = 0; map_2d[i] != NULL; i++) {
        for (int j = 0; map_2d[i][j] != '\0'; j++) {
            if (map_2d[i][j] == 'O') {
                nb[z].c = map_2d[i][j];
                nb[z].x = j;
                nb[z].y = i;
                z++;
            }
        }
    }
}

entity get_position_player(char **map_2d)
{
    entity pos = {0};
    for (int i = 0; map_2d[i] != NULL; i++) {
        for (int j = 0; map_2d[i][j] != '\0'; j++) {
            if (map_2d[i][j] == 'P') {
                pos.x = j;
                pos.y = i;
            }
        }
    }
    return pos;
}

int game_status(char **map_2d, entity *nb, int nb_boxes, char *sokoban_map)
{
    free(sokoban_map);
    if (win(map_2d, nb, nb_boxes)) {
        free_2d_array(map_2d);
        free(nb);
        return 0;
    }
    else {
        free_2d_array(map_2d);
        free(nb);
        return 1;
    }
}

void my_sokoban(char *sokoban_map, int nb_boxes, map_s size)
{
    char **map_2d = my_str_to_word_array(sokoban_map);
    entity *nb = malloc(sizeof(entity) * nb_boxes);
    entity player = get_position_player(map_2d);
    int i = 0;

    start_game(nb, map_2d);
    while (1) {
        clear();
        if (LINES < size.h || COLS < size.w)
            msg_term();
        else {
            print_map(map_2d, nb, nb_boxes, sokoban_map);
            i = event_keyboard(map_2d, &player, getch());
            if (i == ' ') {
                free_2d_array(map_2d);
                map_2d = my_str_to_word_array(sokoban_map);
                player = get_position_player(map_2d);
            }
        }
    }
}
