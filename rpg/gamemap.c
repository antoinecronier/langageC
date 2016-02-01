#include <stdio.h>
#include <stdlib.h>
#include "gamemap.h"

gamemap* gamemap_ctor(int arrayGame[0][0], int mapHeight, int mapWidth, mob* mobs[0], int countMobs, player* myPlayer) {
  gamemap* p = malloc(sizeof(gamemap));
  p->arrayGame = arrayGame;
  p->countMobs = countMobs;
  p->mapHeight = mapHeight;
  p->mapWidth = mapWidth;
  p->mobs = mobs;
  p->myPlayer = myPlayer;
  return p;
}

void setMapEmpty(gamemap* gamemapToUse){
    int i,j;

    //#region conversion
    //Convert pointer on game tab to tab[][]
    typedef int myType[gamemapToUse->mapHeight][gamemapToUse->mapWidth];

    myType *pointer;
    pointer = gamemapToUse->arrayGame;
    //#endregion conversion

    for(i=0;i<gamemapToUse->mapHeight;i++){
        for(j=0;j<gamemapToUse->mapWidth;j++){
            (*pointer)[i][j] = 'c';
        }
    }
}

void setMobsOnMap(gamemap* gamemapToUse){
    int i;

    //#region conversion
    //Convert pointer on game tab to tab[][]
    typedef int myType[gamemapToUse->mapHeight][gamemapToUse->mapWidth];

    myType *pointer;
    pointer = gamemapToUse->arrayGame;
    //#endregion conversion

    //printf("Mob count : %d\n", gamemapToUse->countMobs - 1);

    for(i=0;i<gamemapToUse->countMobs;i++){
        mob* aMob = gamemapToUse->mobs[i];
        (*pointer)[aMob->pos->x][aMob->pos->y] = aMob->id;

    }
}

void removeMobOnMap(gamemap* gamemapToUse, mob* myMob, char itemToSwitchTo){

    //#region conversion
    //Convert pointer on game tab to tab[][]
    typedef int myType[gamemapToUse->mapHeight][gamemapToUse->mapWidth];

    myType *pointer;
    pointer = gamemapToUse->arrayGame;
    //#endregion conversion

    (*pointer)[myMob->pos->x][myMob->pos->y] = itemToSwitchTo;
}

void testIfHaveBattle(gamemap* gamemapToUse, player* myPlayer){
    int i;
    char str[2];

    for(i=0;i<gamemapToUse->countMobs;i++){
        mob* aMob = gamemapToUse->mobs[i];
        if(aMob->id != myPlayer->playerMob->id){
            if(aMob->pos->x == myPlayer->playerMob->pos->x && aMob->pos->y == myPlayer->playerMob->pos->y){
                hitMob(myPlayer->playerMob, aMob);
                if(aMob->lifePoint <= 0){
                    //Delete Mob if life <= 0
                    removeFromList(gamemapToUse, aMob);
                }else{
                    defPlayer(aMob, myPlayer);
                }

            printf("Last Turn Battle\n");
            scanf("%s",str);
            }
        }
    }
}

void removeFromList(gamemap* gamemapToUse, mob* mobToRemove){
    int i, flag = 0;
    mob* tempMob;

    for(i=0;i<gamemapToUse->countMobs;i++){
        mob* aMob = gamemapToUse->mobs[i];
        if(mobToRemove->id == aMob->id){
            gamemapToUse->countMobs --;
            if(i != gamemapToUse->countMobs - 1){
                tempMob = aMob;
                flag = 1;
            }else{

            }
        }else if(flag){
            gamemapToUse->mobs[i-1] = tempMob;
            tempMob = aMob;
        }
    }
}

void showMap(gamemap* gamemapToUse){
    int i,j;

    system("cls");

    //#region conversion
    //Convert pointer on game tab to tab[][]
    typedef int myType[gamemapToUse->mapHeight][gamemapToUse->mapWidth];

    myType *pointer;
    pointer = gamemapToUse->arrayGame;
    //#endregion conversion

    for(i=0;i<gamemapToUse->mapHeight;i++){
        for(j=0;j<gamemapToUse->mapWidth;j++){
            printf("%c",(*pointer)[i][j]);
        }
        printf("\n");
    }
}
