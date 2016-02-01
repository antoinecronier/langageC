#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "mob.h"

typedef struct player{
    int life;
    int isAlive;
    mob* playerMob;
}player;

player* player_ctor(int isAlive, int life, mob* playerMob);

#endif // PLAYER_H_INCLUDED
