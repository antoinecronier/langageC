#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "mob.h"
#include "player.h"

typedef struct mapGame{
    int arrayGame[0][0];
    int mapHeight;
    int mapWidth;
    mob mobs[0];
    int countMobs;
    player myPlayer;
};

#endif // MAP_H_INCLUDED
