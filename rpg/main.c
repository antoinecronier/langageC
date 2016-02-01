#include <stdio.h>
#include <stdlib.h>

#include "gamemap.h"

void playGame();

//For this program we use ascii value on game array
//This allow us to use int and char
int main()
{
    position* mypos = position_ctor(0,0);
    mob* mymob = mob_ctor("joueur1",49,100,1,10,mypos);
    player* myplayer = player_ctor(1,4,mymob);

    position* mob1pos = position_ctor(1,1);
    mob* mob1 = mob_ctor("mob1",50,1,0,10,mob1pos);

    position* mob2pos = position_ctor(3,1);
    mob* mob2 = mob_ctor("mob2",50,1,0,10,mob2pos);

    position* mob3pos = position_ctor(1,4);
    mob* mob3 = mob_ctor("mob3",50,1,0,10,mob3pos);

    position* mob4pos = position_ctor(4,4);
    mob* mob4 = mob_ctor("mob4",50,1,0,10,mob4pos);

    position* mob5pos = position_ctor(6,2);
    mob* mob5 = mob_ctor("mob5",50,1,0,10,mob5pos);

    //Battle use
    /*showMobStats(myplayer->playerMob);
    showMobStats(mob1);

    hitMob(myplayer->playerMob, mob1);
    defPlayer(mob1, myplayer);

    printf("\n");

    showMobLife(myplayer->playerMob);
    showMobLife(mob1);*/

    //Map management
    int height = 10;
    int width = 10;
    int arraygame[height][width];
    int mobcount = 6;
    mob* mobtab[mobcount];
    mobtab[0] = myplayer->playerMob;
    mobtab[1] = mob1;
    mobtab[2] = mob2;
    mobtab[3] = mob3;
    mobtab[4] = mob4;
    mobtab[5] = mob5;

    gamemap* mymap = gamemap_ctor(arraygame,height,width,mobtab,mobcount,myplayer);
    setMapEmpty(mymap);
    setMobsOnMap(mymap);
    showMap(mymap);

    playGame(myplayer, mymap);

    return 0;
}

void playGame(player* myplayer, gamemap* mymap){
    char move[2];
    int i;
    while(myplayer->isAlive){
        printf("Move to :");
        scanf("%s",move);
        //printf("%c",move);
        switch(move[0]){
            case '8' :
                moveUp(myplayer, mymap);
                break;
            case '5' :
                moveDown(myplayer, mymap);
                break;
            case '4' :
                moveLeft(myplayer, mymap);
                break;
            case '6' :
                moveRight(myplayer, mymap);
                break;
        }
    }
}

void moveLeft(player* myplayer, gamemap* mymap){
    if(myplayer->playerMob->pos->y - 1 >= 0){
        removeMobOnMap(mymap, myplayer->playerMob,'c');
        myplayer->playerMob->pos->y--;
        testIfHaveBattle(mymap, myplayer);
        setMobsOnMap(mymap);
    }
    showMap(mymap);
}

void moveRight(player* myplayer, gamemap* mymap){
    if(myplayer->playerMob->pos->y + 1 < mymap->mapHeight){
        removeMobOnMap(mymap, myplayer->playerMob,'c');
        myplayer->playerMob->pos->y++;
        testIfHaveBattle(mymap, myplayer);
        setMobsOnMap(mymap);
    }
    showMap(mymap);
}

void moveUp(player* myplayer, gamemap* mymap){
    if(myplayer->playerMob->pos->x - 1 >= 0){
        removeMobOnMap(mymap, myplayer->playerMob,'c');
        myplayer->playerMob->pos->x--;
        testIfHaveBattle(mymap, myplayer);
        setMobsOnMap(mymap);
    }
    showMap(mymap);
}

void moveDown(player* myplayer, gamemap* mymap){
    if(myplayer->playerMob->pos->x + 1 < mymap->mapWidth){
        removeMobOnMap(mymap, myplayer->playerMob,'c');
        myplayer->playerMob->pos->x++;
        testIfHaveBattle(mymap, myplayer);
        setMobsOnMap(mymap);
    }
    showMap(mymap);
}
