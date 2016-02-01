#include <stdio.h>
#include <stdlib.h>
#include "player.h"

player* player_ctor(int isAlive, int life, mob* playerMob) {
  player* p = malloc(sizeof(player));
  p->isAlive = isAlive;
  p->life = life;
  p->playerMob = playerMob;
  return p;
}
