#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "mob.h"

typedef struct player{
    int life;
    int isAlive;
    mob playerMob;
}player;

#endif // PLAYER_H_INCLUDED
