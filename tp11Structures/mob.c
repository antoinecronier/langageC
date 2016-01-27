#include <stdio.h>
#include <stdlib.h>
#include "mob.h"

void hitMob(mob* mobAttack, mob* mobDef){
    *mobDef.lifePoint += *mobAttack.attack - *mobDef.defence;
}

void defPlayer(mob* mobAttack, player* playerDef){
    *playerDef.playerMob.lifePoint += *mobAttack.attack - *playerDef.playerMob.defence;
    if(*playerDef.playerMob.lifePoint <= 0){
        *playerDef.life --;
        if(*playerDef.life <= 0){
            *playerDef.isAlive = 0;
        }
    }
}
