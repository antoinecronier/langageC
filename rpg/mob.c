#include <stdio.h>
#include <stdlib.h>
#include "player.h"

mob* mob_ctor(char name[15], int id, int attack, int defence, int lifePoint, position* pos) {
  mob* p = malloc(sizeof(mob));
  p->name = name;
  p->id = id;
  p->attack = attack;
  p->defence = defence;
  p->lifePoint = lifePoint;
  p->pos = pos;
  return p;
}

void showMobLife(mob* mobToPrint){
    printf("%s life: %d\n",mobToPrint->name, mobToPrint->lifePoint);
}

void showMobStats(mob* mobToPrint){
    printf("id: %d\n", mobToPrint->id);
    showMobLife(mobToPrint);
    printf("attack: %d\n", mobToPrint->attack);
    printf("defence: %d\n", mobToPrint->defence);
    printf("position: %d - %d\n", mobToPrint->pos->x, mobToPrint->pos->y);
}

void hitMob(mob* mobAttack, mob* mobDef){
    mobDef->lifePoint -= mobAttack->attack - mobDef->defence;
    showMobLife(mobDef);
}

void defPlayer(mob* mobAttack, player* playerDef){
    playerDef->playerMob->lifePoint -= mobAttack->attack - playerDef->playerMob->defence;
    showMobLife(playerDef->playerMob);
    if(playerDef->playerMob->lifePoint <= 0){
        playerDef->life --;
        if(playerDef->life <= 0){
            playerDef->isAlive = 0;
        }
    }
}
