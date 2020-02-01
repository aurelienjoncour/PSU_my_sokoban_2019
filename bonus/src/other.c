/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** other
*/

#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include "my_sokoban.h"
#include "my.h"

void free_2d_array(char **map_2d)
{
    int i = 0;

    for (i = 0; map_2d[i] != NULL; i++)
        free(map_2d[i]);
    free(map_2d[i]);
    free(map_2d);
}

sfRenderWindow *create_windows(unsigned int w, unsigned int h)
{
    sfVideoMode video_mode = {w, h, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, "My Sokoban", sfClose, NULL);
    return (window);
}

void restart_game(char ***map_2d, char *map_sokoban, entity *player)
{
    free_2d_array(*map_2d);
    *map_2d = my_str_to_word_array(map_sokoban);
    *player = get_position_player(*map_2d);
}