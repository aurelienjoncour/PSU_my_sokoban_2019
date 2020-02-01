/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** graphics
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "assets.h"
#include "my_sokoban.h"
#include "other.h"
#include "game.h"

static void draw_sprite(sfRenderWindow *window, assets_t image, int i, int j)
{
    sfSprite_setPosition(image.sprite, (sfVector2f){j * 64, i * 64});
    sfSprite_setTexture(image.sprite, image.texture, sfFalse);
    sfRenderWindow_drawSprite(window, image.sprite, NULL);
}

void draw_map(assets_t *image, char **map_2d, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, (sfColor){183, 145, 106, 255});
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map_2d[i][j] == '#')
                draw_sprite(window, image[0], i, j);
            if (map_2d[i][j] == 'P')
                draw_sprite(window, image[1], i, j);
            if (map_2d[i][j] == 'X')
                draw_sprite(window, image[3], i, j);
            if (map_2d[i][j] == 'O')
                draw_sprite(window, image[2], i, j);
        }
    }
    sfRenderWindow_display(window);
}

assets_t *load_sprite(void)
{
    assets_t *image = malloc(sizeof(assets_t) * 4);

    image[0].texture = sfTexture_createFromFile("assets/Wall_Brown.png", NULL);
    image[1].texture = sfTexture_createFromFile("assets/Character_Bot.png",
                        NULL);
    image[2].texture = sfTexture_createFromFile("assets/Objectif_Center.png",
                        NULL);
    image[3].texture = sfTexture_createFromFile("assets/Crate_Red.png",
                        NULL);
    for (int i = 0; i < 4; i++)  {
        image[i].sprite = sfSprite_create();
    }
    return image;
}

void destroy_ressource(assets_t *image, char **map_2d, char *sokoban)
{
    for (int  i = 0; i < 4; i++) {
        sfSprite_destroy(image[i].sprite);
        sfTexture_destroy(image[i].texture);
    }
    free(sokoban);
    free_2d_array(map_2d);
}