/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** map
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "my_sokoban.h"
#include "game.h"

static bool map_error(char *map, int *boxes)
{
    int nb_perso = 0;
    int nb_boxes = 0;
    int nb_storage_location = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != 'X' && map[i] != 'O' && map[i] != 'P' && map[i] != '#'
            && map[i] != '\n' && map[i] != ' ')
            return true;
        if (map[i] == 'P')
            nb_perso++;
        if (map[i] == 'X')
            nb_boxes++;
        if (map[i] == 'O')
            nb_storage_location++;
    }
    *boxes = nb_boxes;
    if (nb_perso > 1 || nb_boxes != nb_storage_location)
        return true;
    return false;
}

char *map(char const *filepath, int *nb_boxes)
{
    int fd;
    char *map_sokoban;
    struct stat statmap;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    stat(filepath, &statmap);
    if (statmap.st_size == 0)
        return NULL;
    map_sokoban = malloc(sizeof(char) * (statmap.st_size + 1));
    if (map_sokoban == NULL)
        return NULL;
    read(fd, map_sokoban, statmap.st_size);
    map_sokoban[statmap.st_size] = '\0';
    close(fd);
    if (map_error(map_sokoban, nb_boxes))
        return NULL;
    return map_sokoban;
}

void case_vide(char **map_2d, entity tab[], int nb_boxes)
{
    for (int i = 0; i < nb_boxes; i++)
        if (map_2d[tab[i].y][tab[i].x] == ' ')
            map_2d[tab[i].y][tab[i].x] = 'O';
}

void print_map(char **map_2d, entity *nb, int nb_boxes, char *sokoban_map)
{
    case_vide(map_2d, nb, nb_boxes);
    for (int i = 0; map_2d[i] != NULL; i++) {
        printw(map_2d[i]);
        printw("\n");
    }
    refresh();
    if (win(map_2d, nb, nb_boxes) || loose(map_2d, nb_boxes)) {
        endwin();
        exit (game_status(map_2d, nb, nb_boxes, sokoban_map));
    }
}
