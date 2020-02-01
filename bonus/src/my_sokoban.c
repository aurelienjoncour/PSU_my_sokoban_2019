/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdbool.h>
#include "my_sokoban.h"
#include "move_player.h"
#include "game.h"
#include "map.h"
#include "other.h"
#include "my.h"
#include "assets.h"
#include "graphics.h"

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

void event_gestion(sfRenderWindow *window, sfEvent event, entity *player,
                    char **map_2d)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        sfRenderWindow_destroy(window);
        free_2d_array(map_2d);
        exit (0);
    }
    if (event.type == sfEvtKeyReleased) {
        move_player(map_2d, player, event);
    }
}

bool my_sokoban(sfRenderWindow *window, sfEvent event, char *sokoban_map,
                int nb_boxes)
{
    bool win_condition = false;
    char **map_2d = my_str_to_word_array(sokoban_map);
    entity *nb = malloc(sizeof(entity) * nb_boxes);
    entity player = get_position_player(map_2d);
    assets_t *image = load_sprite();

    fill_entity(nb, map_2d);
    while (sfRenderWindow_isOpen(window) && keep_open(map_2d, nb, nb_boxes,
            &win_condition)) {
        print_map(map_2d, nb, nb_boxes);
        draw_map(image, map_2d, window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace)
                restart_game(&map_2d, sokoban_map, &player);
            event_gestion(window, event, &player, map_2d);
        }
    }
    destroy_ressource(image, map_2d, sokoban_map);
    return win_condition;
}