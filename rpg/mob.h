#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED

#include "position.h"

typedef struct mob{
    char* name;
    int id;
    int attack;
    int defence;
    int lifePoint;
    position* pos;
}mob;

mob* mob_ctor(char name[15], int id, int attack, int defence, int lifePoint, position* pos);

#endif // MOB_H_INCLUDED
