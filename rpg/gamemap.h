#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

#include "player.h"

typedef struct gamemap{
    int* arrayGame;
    int mapHeight;
    int mapWidth;
    mob** mobs;
    int countMobs;
    player* myPlayer;
}gamemap;

gamemap* gamemap_ctor(int arrayGame[0][0], int mapHeight, int mapWidth, mob* mobs[0], int countMobs, player* myPlayer);

#endif // GAMEMAP_H_INCLUDED
