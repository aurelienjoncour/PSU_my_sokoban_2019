/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_player
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "my_sokoban.h"
#include "my.h"

static void move_right(char **map_2d, entity *player)
{
    if (map_2d[player->y][player->x + 1] == 'X' &&
        map_2d[player->y][player->x + 2] != '#' &&
        map_2d[player->y][player->x + 2] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y][player->x + 1] = 'P';
        map_2d[player->y][player->x + 2] = 'X';
        player->x += 1;
    }
    else if (map_2d[player->y][player->x + 1] != '#' &&
            map_2d[player->y][player->x + 1] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y][player->x + 1] = 'P';
        player->x += 1;
    }
}

static void move_left(char **map_2d, entity *player)
{
    if (map_2d[player->y][player->x - 1] == 'X' &&
        map_2d[player->y][player->x - 2] != '#' &&
        map_2d[player->y][player->x - 2] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y][player->x - 1] = 'P';
        map_2d[player->y][player->x - 2] = 'X';
        player->x -= 1;
    }
    else if (map_2d[player->y][player->x - 1] != '#' &&
            map_2d[player->y][player->x - 1] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y][player->x - 1] = 'P';
        player->x -= 1;
    }
}

static void move_top(char **map_2d, entity *player)
{
    if (map_2d[player->y - 1][player->x] == 'X' &&
        map_2d[player->y - 2][player->x] != '#' &&
        map_2d[player->y - 2][player->x] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y - 1][player->x] = 'P';
        map_2d[player->y - 2][player->x] = 'X';
        player->y -= 1;
    }
    else if (map_2d[player->y - 1][player->x] != '#' &&
            map_2d[player->y - 1][player->x] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y - 1][player->x] = 'P';
        player->y -= 1;
    }
}

static void move_bottom(char **map_2d, entity *player)
{
    if (map_2d[player->y + 1][player->x] == 'X' &&
        map_2d[player->y + 2][player->x] != '#' &&
        map_2d[player->y + 2][player->x] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y + 1][player->x] = 'P';
        map_2d[player->y + 2][player->x] = 'X';
        player->y += 1;
    }
    else if (map_2d[player->y + 1][player->x] != '#' &&
        map_2d[player->y + 1][player->x] != 'X') {
        map_2d[player->y][player->x] = ' ';
        map_2d[player->y + 1][player->x] = 'P';
        player->y += 1;
    }
}

void move_player(char **map_2d, entity *player, sfEvent event)
{
    if (event.key.code == sfKeyUp)
        move_top(map_2d, player);
    if (event.key.code == sfKeyDown)
        move_bottom(map_2d, player);
    if (event.key.code == sfKeyRight)
        move_right(map_2d, player);
    if (event.key.code == sfKeyLeft)
        move_left(map_2d, player);
}