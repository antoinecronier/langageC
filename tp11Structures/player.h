#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "position.h"
#include "mob.h"

typedef struct mob{
    int attack;
    int defence;
    int lifePoint;
    position pos;
};

typedef struct player{
    int life;
    int isAlive;
    mob playerMob;
};

#endif // PLAYER_H_INCLUDED
