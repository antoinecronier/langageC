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

int doRand(int startVal, int endVal){
    srand(time(0));
    return (rand() % (endVal - startVal -1) + startVal);
}

int setNavire(int x, int y, int size, int id, int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;

    //See text position
    printf("setNavire x=%d y=%d size=%d id=%d\n",x,y,size,id);
    for(i=0;i<size;i++){
        plateau[x+i][y] = id;
    }

    printf("\n");
}

//Return 0 if case have nothing
//Return item value if case have something
int testCase(int x, int y, int size, int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    //boucle  to see dimension
    int i = 0;
    int flagOk = 1;

    //Test boat enter in map with is width
    if((x - size >= 0) && (y - size >= 0) && (x + size < PLATEAU_WIDTH) && (y + size < PLATEAU_HEIGHT)){
        for(i=0;i<size-1;i++){
            if(plateau[x+i][y] != 0){
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

int setCorvette(int nbCorvette, int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;

    for(i=0;i<nbCorvette;i++){
        while(flag){
            y = doRand(0,PLATEAU_HEIGHT);
            x = doRand(0,PLATEAU_WIDTH);
            if(testCase(x,y,CORVETTE_WIDTH,plateau) == 0){
                setNavire(x,y,CORVETTE_WIDTH,CORVETTE_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setDestroyer(int nbDestroyer, int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;

    for(i=0;i<nbDestroyer;i++){
        while(flag){
            y = doRand(0,PLATEAU_HEIGHT);
            x = doRand(0,PLATEAU_WIDTH);
            if(testCase(x,y,DESTROYER_WIDTH,plateau) == 0){
                setNavire(x,y,DESTROYER_WIDTH,DESTROYER_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setCroiseur(int nbCroiseur, int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;

    for(i=0;i<nbCroiseur;i++){
        while(flag){
            y = doRand(0,PLATEAU_HEIGHT);
            x = doRand(0,PLATEAU_WIDTH);
            if(testCase(x,y,CROISEUR_WIDTH,plateau) == 0){
                setNavire(x,y,CROISEUR_WIDTH,CROISEUR_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setPorteAvion(int nbPorteAvion, int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;

    for(i=0;i<nbPorteAvion;i++){
        while(flag){
            y = doRand(0,PLATEAU_HEIGHT);
            x = doRand(0,PLATEAU_WIDTH);
            if(testCase(x,y,PORTE_AVION_WIDTH,plateau) == 0){
                setNavire(x,y,PORTE_AVION_WIDTH,PORTE_AVION_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setNavires(int nbPlayer, int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    for(i=0;i<nbPlayer;i++){
        printf("Joueur %d :\n",i+1);
        setPorteAvion(PORTE_AVION_NB,plateau);
        setCroiseur(CROISEUR_NB,plateau);
        setDestroyer(DESTROYER_NB,plateau);
        setCorvette(CORVETTE_NB,plateau);
    }
}

void purgeTableau(int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int j = 0;
    for(i=0;i<PLATEAU_HEIGHT;i++){
        for(j=0;j<PLATEAU_WIDTH;j++){
            plateau[i][j] = 0;
        }
    }
}

int printTableau(int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int j = 0;
    for(i=0;i<PLATEAU_HEIGHT;i++){
        for(j=0;j<PLATEAU_WIDTH;j++){
            printf("%d",plateau[i][j]);
        }
        printf("\n");
    }
}

void setPlateau(int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    purgeTableau(plateau);
    setNavires(NB_PLAYER,plateau);
    printTableau(plateau);
}

int main()
{
    int plateau[PLATEAU_HEIGHT][PLATEAU_WIDTH];

    setPlateau(plateau);

    return 0;
}
