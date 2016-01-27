#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED
#include "position.h"
#include "player.h"

typedef struct mob{
    int attack;
    int defence;
    int lifePoint;
    position pos;
}mob;

void hitMob(mob* mobAttack, mob* mobDef);
void defPlayer(mob* mobAttack, player* playerDef);

#endif // MOB_H_INCLUDED
