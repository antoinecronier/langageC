#include <stdio.h>
#include <stdlib.h>

#define NB_PLAYER 2

#define PLATEAU_HEIGHT 18
#define PLATEAU_WIDTH 24

#define CORVETTE_ID 1
#define CORVETTE_WIDTH 1
#define CORVETTE_NB 1

#define DESTROYER_ID 2
#define DESTROYER_WIDTH 3
#define DESTROYER_NB 2

#define CROISEUR_ID 3
#define CROISEUR_WIDTH 4
#define CROISEUR_NB 2

#define PORTE_AVION_ID 4
#define PORTE_AVION_WIDTH 6
#define PORTE_AVION_NB 1

#define HIT 8
#define MISS 9

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1) + startVal));
    }
}

int setNavire(int player, int orientation, int x, int y, int size, int id, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;

    printf("setNavire x=%d y=%d size=%d id=%d ",x+1,y+1,size,id);
    if(orientation){
        printf("orientation vertical\n");

        for(i=0;i<size;i++){
            //printf("on tab player %d\n",player+1);
            //printf("local tab value %d\n",plateau[player][x+i][y]);
            plateau[player][x+i][y] = id;
            //printf("new value %d\n",plateau[player][x+i][y]);
        }
    }else{
        printf("orientation horizontal\n");

        for(i=0;i<size;i++){
            //printf("on tab player %d\n",player+1);
            //printf("local tab value %d\n",plateau[player][x][y+i]);
            plateau[player][x][y+i] = id;
            //printf("new value %d\n",plateau[player][x][y+i]);
        }
    }

    printf("\n");
}

//Return 0 if case have nothing
//Return item value if case have something
int testCase(int player, int orientation, int x, int y, int size, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    //boucle  to see dimension
    int i = 0;
    int flagOk = 1;

    if(orientation){
        //Test boat enter in map with is width
        if((x - size >= 0) && (y - size >= 0) && (x + size < PLATEAU_WIDTH) && (y + size < PLATEAU_HEIGHT)){
            for(i=0;i<size;i++){
                if(plateau[player][x+i][y] != 0){
                    flagOk = 0;
                }
            }
        }else{
            return -1;
        }
        if(flagOk == 0){
            return -1;
        }else{
            return 0;
        }
    }else{
        //Test boat enter in map with is width
        if((x - size >= 0) && (y - size >= 0) && (x + size < PLATEAU_WIDTH) && (y + size < PLATEAU_HEIGHT)){
            for(i=0;i<size;i++){
                if(plateau[player][x][y+i] != 0){
                    flagOk = 0;
                }
            }
        }else{
            return -1;
        }
        if(flagOk == 0){
            return -1;
        }else{
            return 0;
        }
    }
}

int setCorvette(int player, int nbCorvette, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbCorvette;i++){
        while(flag){
            y = doRand(0,PLATEAU_WIDTH);
            x = doRand(0,PLATEAU_HEIGHT);
            orientation = doRand(0,1);

            if(testCase(player,orientation,x,y,CORVETTE_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,CORVETTE_WIDTH,CORVETTE_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setDestroyer(int player, int nbDestroyer, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbDestroyer;i++){
        while(flag){
            y = doRand(0,PLATEAU_WIDTH);
            x = doRand(0,PLATEAU_HEIGHT);
            orientation = doRand(0,1);

            if(testCase(player,orientation,x,y,DESTROYER_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,DESTROYER_WIDTH,DESTROYER_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setCroiseur(int player, int nbCroiseur, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbCroiseur;i++){
        while(flag){
            y = doRand(0,PLATEAU_WIDTH);
            x = doRand(0,PLATEAU_HEIGHT);
            orientation = doRand(0,1);

            if(testCase(player,orientation,x,y,CROISEUR_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,CROISEUR_WIDTH,CROISEUR_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setPorteAvion(int player, int nbPorteAvion, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbPorteAvion;i++){
        while(flag){
            y = doRand(0,PLATEAU_WIDTH);
            x = doRand(0,PLATEAU_HEIGHT);
            orientation = doRand(0,1);

            if(testCase(player,orientation,x,y,PORTE_AVION_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,PORTE_AVION_WIDTH,PORTE_AVION_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setNavires(int nbPlayer, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    printf("Joueur %d :\n",nbPlayer+1);
    setPorteAvion(nbPlayer,PORTE_AVION_NB,plateau);
    setCroiseur(nbPlayer,CROISEUR_NB,plateau);
    setDestroyer(nbPlayer,DESTROYER_NB,plateau);
    setCorvette(nbPlayer,CORVETTE_NB,plateau);
}

void purgeTableau(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int j = 0;
    int k = 0;

    for(k=0;k<NB_PLAYER;k++){
        for(i=0;i<PLATEAU_HEIGHT;i++){
            for(j=0;j<PLATEAU_WIDTH;j++){
                plateau[k][i][j] = 0;
            }
        }
    }
}

void printTableau(int player,int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int j = 0;
    for(i=0;i<PLATEAU_HEIGHT;i++){
        for(j=0;j<PLATEAU_WIDTH;j++){
            if(i == 0 && j == 0){
                printf("y\\x");
            }else if(i == 0 && j > 0){
                if(j < 10){
                    printf("%d  ",j);
                }else if(j<100){
                    printf("%d ",j);
                }
            }else if(j == 0){
                if(i < 10){
                    printf("%d  ",i);
                }else if(i<100){
                    printf("%d ",i);
                }
            }else{
                printf("%d  ",plateau[player][i-1][j-1]);
            }
        }
        printf("\n");
    }
}

void setPlateau(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    purgeTableau(plateau);

    int i = 0;
    for(i=0;i<NB_PLAYER;i++){
        setNavires(i,plateau);
    }

    for(i=0;i<NB_PLAYER;i++){
        printTableau(i,plateau);
        printf("/////////////////////////////////////////////\n");
    }
}

void ia1(int playerToFire,int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int flag = 1;
    while(flag){
        int y = doRand(0,PLATEAU_WIDTH);
        int x = doRand(0,PLATEAU_HEIGHT);

        if(plateau[playerToFire][x][y] != HIT && plateau[playerToFire][x][y] != MISS){
            if(plateau[playerToFire][x][y] != 0){
                printf("hit %d %d\n",x,y);
                plateau[playerToFire][x][y] = HIT;
                flag = 0;
            }else if(plateau[playerToFire][x][y] == 0){
                printf("miss %d %d\n",x,y);
                plateau[playerToFire][x][y] = MISS;
                flag = 0;
            }
        }
    }
}

int notAlreadyDead(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i,j,k;
    //printf("before\n");
    int flags [NB_PLAYER] = {0};
    //printf("after\n");
    for(i=0;i<NB_PLAYER;i++){
        for(j=0;j<PLATEAU_HEIGHT;j++){
            for(k=0;k<PLATEAU_WIDTH;k++){
                if(plateau[i][j][k] == CORVETTE_ID || plateau[i][j][k] == DESTROYER_ID
                   || plateau[i][j][k] == CROISEUR_ID || plateau[i][j][k] == PORTE_AVION_ID ){
                    flags[i] = 1;
                }
            }
        }
    }

    //printf("tested\n");
    for(i=0;i<NB_PLAYER;i++){
        if(flags[i] == 0){
            printf("Le joueur %d a perdu\n",i+1);
            return 0;
        }
    }
    return 1;
}

void play(int nbPlayer, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 1;
    while(notAlreadyDead(plateau)){
        printf("turn %d\n",i);
        ia1(1,plateau);
        ia1(0,plateau);
        /*for(i=0;i<NB_PLAYER;i++){
            printTableau(i,plateau);
            printf("/////////////////////////////////////////////\n");
        }*/
        i++;
    }
}

int battleShip(){
    int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH];

    setPlateau(plateau);

    play(NB_PLAYER,plateau);

    int i;
    for(i=0;i<NB_PLAYER;i++){
        printTableau(i,plateau);
        printf("/////////////////////////////////////////////\n");
    }

    getchar();

    return 0;
}

int testRand(){
    #define numberOfRand 10000
    #define numberOfValues 100

    int tab[numberOfRand] = {0};
    for(int i = 0; i < numberOfRand; i++){
        tab[i] = doRand(0,numberOfValues);
    }

    int result[numberOfValues] = {0};
    for(int i = 0; i < numberOfValues; i++){
        for(int j = 0; j < numberOfRand; j++){
            if(tab[j] == i){
                result[i]++;
            }
        }
    }

    for(int i = 0; i < numberOfValues; i++){
        printf("Valeur %d occurence %d\n",i,result[i]);
    }
}

int playMode(){
    int selection = 10;
    while(selection){
        system("cls");
        printf("#############################\n");
        printf("#   Welcome to battleship   #\n");
        printf("#   Select your game mode   #\n");
        printf("#############################\n\n");
        printf("1 => ia vs ia\n");
        printf("2 => player vs ia\n");
        printf("3 => player vs player\n");
        printf("0 => leave\n");
        scanf("%d[0-9]",&selection);

        switch(selection){
            case 1 :
                break;
            case 2 :
                break;
            case 3 :
                break;
        }
    }

}

int main()
{
    battleShip();
}
