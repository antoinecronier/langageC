#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NB_PLAYER 2

#define PLATEAU_HEIGHT 9
#define PLATEAU_WIDTH 15

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

#define IA 0
#define PLAYER 1

#define X 0
#define Y 1

void setConsoleColor(WORD input){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, input);
}

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

void saver(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    char question = ' ';
    while(question != 'Y' && question != 'N'){
        printf("Voulez vous enregistrer la partie? (Y/N)\n");
        scanf("%c[YN]",&question);
        fflush(stdin);
    }

    if(question == 'Y'){
        savePlateau(plateau);
    }
}

void saveTo1(int tab[2],int tabSize,char* file){
    int i;
    FILE* ftp = fopen(file,"w+");
    for(i=0;i<tabSize;i++){
        fprintf(ftp,"%c",(char)tab[i]);
    }
    fclose(ftp);
}

void saveTo2(int tab[4][2],int tabSize1, int tabSize2,char* file){
    int i,j;
    FILE* ftp = fopen(file,"w+");
    for(i=0;i<tabSize1;i++){
        for(j=0;j<tabSize2;j++){
            fprintf(ftp,"%c",(char)tab[i][j]);
        }
    }
    fclose(ftp);
}

void savePlateau(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i,j,k;
    FILE* ftp = fopen("./battleship.save","w+");
    for(i=0;i<NB_PLAYER;i++){
        for(j=0;j<PLATEAU_HEIGHT;j++){
            for(k=0;k<PLATEAU_WIDTH;k++){
                fprintf(ftp,"%c",(char)plateau[i][j][k]);
            }
        }
    }
    fclose(ftp);
}

void loadFrom1(int tab[2],int tabSize,char* file){
    int i;
    char c;
    FILE* fptr;

    if(fptr = fopen(file,"r")){
        for(i = 0;i < tabSize; i++){
            c = fgetc(fptr);
            if( feof(fptr) )
            {
                break;
            }
            tab[i]=(int)c;
        }
    }

    fclose(fptr);
}

void loadFrom2(int tab[4][2],int tabSize1, int tabSize2,char* file){
    int i,j;
    char c;
    FILE* fptr;

    if(fptr = fopen(file,"r")){

        for(i = 0;i < tabSize1; i++){
            for(j=0;j<tabSize2;j++){
                c = fgetc(fptr);
                if( feof(fptr) )
                {
                    break;
                }
                tab[i][j]=(int)c;
            }
        }
    }

    fclose(fptr);
}

void loadPlateau(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i,j,k;
    char c;
    FILE* fptr = fopen("./battleship.save","r");

    for(i = 0;i < NB_PLAYER; i++){
        for(j = 0;j < PLATEAU_HEIGHT; j++){
            for(k = 0;k < PLATEAU_WIDTH; k++){
                c = fgetc(fptr);
                if( feof(fptr) )
                {
                    break;
                }
                plateau[i][j][k]=(int)c;
            }
        }
    }

    fclose(fptr);
    /*fflush(stdin);
    printAllPlateau(plateau);
    getchar();*/
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

    //printf("Debug TestCase :\nPlayer : %d\nOrientation : %d\nx : %d\ny : %d\nSize : %d\n",player,orientation,x,y,size);

    if(orientation){
        //Test boat enter in map with is width
        if(/*(x - size >= 0) && (y - size >= 0) && */(x + size <= PLATEAU_HEIGHT)/* && (y + size < PLATEAU_HEIGHT)*/){
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
        if(/*(x - size >= 0) && (y - size >= 0) && *//*(x + size < PLATEAU_WIDTH) &&*/ (y + size <= PLATEAU_WIDTH)){
            for(i=0;i<size;i++){
                if(plateau[player][x][y+i] != 0){
                    flagOk = 0;
                }else{
                    //printf("debug plateau x:%d y:%d = %d\n",x,y+i,plateau[player][x][y+i]);
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

int setCorvetteIA(int player, int nbCorvette, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbCorvette;i++){
        while(flag){
            y = doRand(0,PLATEAU_WIDTH-1);
            x = doRand(0,PLATEAU_HEIGHT-1);
            orientation = doRand(0,1);

            if(testCase(player,orientation,x,y,CORVETTE_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,CORVETTE_WIDTH,CORVETTE_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setDestroyerIA(int player, int nbDestroyer, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbDestroyer;i++){
        while(flag){
            y = doRand(0,PLATEAU_WIDTH-1);
            x = doRand(0,PLATEAU_HEIGHT-1);
            orientation = doRand(0,1);

            if(testCase(player,orientation,x,y,DESTROYER_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,DESTROYER_WIDTH,DESTROYER_ID,plateau);
                flag = 0;
            }
        }
        flag = 1;
    }
}

int setCroiseurIA(int player, int nbCroiseur, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
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

int setPorteAvionIA(int player, int nbPorteAvion, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
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

int checkSaisi(int min, int max, const char* text){
    int saisi = -1;
    while(saisi){
        if(text != NULL){
            printf(text);
        }
        printf("Saisir un entier entre %d et %d\n", min, max);
        scanf("%d[0-9]",&saisi);
        fflush(stdin);
        if(saisi >= min && saisi <= max){
            return saisi;
        }else{
            printf("Erreur respecter l'interval\n");
        }
    }
}

int setPorteAvionPlayer(int player, int nbPorteAvion, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbPorteAvion;i++){
        while(flag){
            printf("Porte avion numero : %d\n", i);
            y = checkSaisi(0,PLATEAU_WIDTH-1,"Coordonnee y pour porte avion\n");
            x = checkSaisi(0,PLATEAU_HEIGHT-1,"Coordonnee x pour porte avion\n");
            orientation = checkSaisi(0,1,"Choisir l'orientation du bateau 0 vertical 1 horizontal\n");

            if(testCase(player,orientation,x,y,PORTE_AVION_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,PORTE_AVION_WIDTH,PORTE_AVION_ID,plateau);
                flag = 0;
                printTableau(player,plateau);
            }else{
                printf("Le porte avion numero : %d ne peut etre place\n", i + 1);
            }
        }
        flag = 1;
    }
}

int setCroiseurPlayer(int player, int nbCroiseur, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbCroiseur;i++){
        while(flag){
            printf("Croiseur numero : %d\n", i);
            y = checkSaisi(0,PLATEAU_WIDTH-1,"Coordonnee y pour croiseur\n");
            x = checkSaisi(0,PLATEAU_HEIGHT-1,"Coordonnee x pour croiseur\n");
            orientation = checkSaisi(0,1,"Choisir l'orientation du bateau 0 vertical 1 horizontal\n");

            if(testCase(player,orientation,x,y,CROISEUR_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,CROISEUR_WIDTH,CROISEUR_ID,plateau);
                flag = 0;
                printTableau(player,plateau);
            }else{
                printf("Le croiseur numero : %d ne peut etre place\n", i + 1);
            }
        }
        flag = 1;
    }
}

int setDestroyerPlayer(int player, int nbDestroyer, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbDestroyer;i++){
        while(flag){
            printf("Destroyer numero : %d\n", i);
            y = checkSaisi(0,PLATEAU_WIDTH-1,"Coordonnee y pour destroyer\n");
            x = checkSaisi(0,PLATEAU_HEIGHT-1,"Coordonnee x pour destroyer\n");
            orientation = checkSaisi(0,1,"Choisir l'orientation du bateau 0 vertical 1 horizontal\n");

            if(testCase(player,orientation,x,y,DESTROYER_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,DESTROYER_WIDTH,DESTROYER_ID,plateau);
                flag = 0;
                printTableau(player,plateau);
            }else{
                printf("Le destroyer numero : %d ne peut etre place\n", i + 1);
            }
        }
        flag = 1;
    }
}

int setCorvettePlayer(int player, int nbCorvette, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int x = -1;
    int y = -1;
    int flag = 1;
    int orientation;

    for(i=0;i<nbCorvette;i++){
        while(flag){
            printf("Corvette numero : %d\n", i);
            y = checkSaisi(0,PLATEAU_WIDTH-1,"Coordonnee y pour corvette\n");
            x = checkSaisi(0,PLATEAU_HEIGHT-1,"Coordonnee x pour corvette\n");
            orientation = checkSaisi(0,1,"Choisir l'orientation du bateau 0 vertical 1 horizontal\n");

            if(testCase(player,orientation,x,y,CORVETTE_WIDTH,plateau) == 0){
                setNavire(player,orientation,x,y,CORVETTE_WIDTH,CORVETTE_ID,plateau);
                flag = 0;
                printTableau(player,plateau);
            }else{
                printf("La corvette numero : %d ne peut etre place\n", i + 1);
            }
        }
        flag = 1;
    }
}

int setNavires(int nbPlayer, int type, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    printf("Joueur %d :\n",nbPlayer+1);
    if(type == 0){
        setPorteAvionIA(nbPlayer,PORTE_AVION_NB,plateau);
        setCroiseurIA(nbPlayer,CROISEUR_NB,plateau);
        setDestroyerIA(nbPlayer,DESTROYER_NB,plateau);
        setCorvetteIA(nbPlayer,CORVETTE_NB,plateau);
    }else if(type == 1){
        setPorteAvionPlayer(nbPlayer,PORTE_AVION_NB,plateau);
        setCroiseurPlayer(nbPlayer,CROISEUR_NB,plateau);
        setDestroyerPlayer(nbPlayer,DESTROYER_NB,plateau);
        setCorvettePlayer(nbPlayer,CORVETTE_NB,plateau);
    }

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

void printTableau(int player, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int j = 0;
    printf("Tableau player : %d\n",player+1);
    for(i=-1;i<PLATEAU_HEIGHT;i++){
        for(j=-1;j<PLATEAU_WIDTH;j++){
            if(i == -1 && j == -1){
                printf("y\\x");
            }else if(i == -1 && j > -1){
                if(j < 10){
                    printf("%d  ",j);
                }else if(j<100){
                    printf("%d ",j);
                }
            }else if(j == -1){
                if(i < 10){
                    printf("%d  ",i);
                }else if(i<100){
                    printf("%d ",i);
                }
            }else{
                if(plateau[player][i][j]==0){
                    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                }else if(plateau[player][i][j]==CORVETTE_ID
                         ||plateau[player][i][j]==DESTROYER_ID
                         ||plateau[player][i][j]==PORTE_AVION_ID
                         ||plateau[player][i][j]==CROISEUR_ID){
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                }else if(plateau[player][i][j]==8){
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                }else if(plateau[player][i][j]==9){
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                }
                printf("%d  ",plateau[player][i][j]);
                setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
        }
        printf("\n");
    }
}

void printMyTableau(int player, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int j = 0;
    printf("Tableau player : %d\n",player+1);
    for(i=-1;i<PLATEAU_HEIGHT;i++){
        for(j=-1;j<PLATEAU_WIDTH;j++){
            if(i == -1 && j == -1){
                printf("y\\x");
            }else if(i == -1 && j > -1){
                if(j < 10){
                    printf("%d  ",j);
                }else if(j<100){
                    printf("%d ",j);
                }
            }else if(j == -1){
                if(i < 10){
                    printf("%d  ",i);
                }else if(i<100){
                    printf("%d ",i);
                }
            }else{
                setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                if(plateau[player][i][j]==0){
                    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                }else if(plateau[player][i][j]==CORVETTE_ID
                    ||plateau[player][i][j]==DESTROYER_ID
                    ||plateau[player][i][j]==PORTE_AVION_ID
                    ||plateau[player][i][j]==CROISEUR_ID){
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                }else if(plateau[player][i][j]==8){
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                }else if(plateau[player][i][j]==9){
                    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                }
                printf("%d  ",plateau[player][i][j]);
                setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
        }
        printf("\n");
    }
}

void printHiddenTableau(int player, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 0;
    int j = 0;
    printf("Tableau player : %d\n",player+1);
    for(i=-1;i<PLATEAU_HEIGHT;i++){
        for(j=-1;j<PLATEAU_WIDTH;j++){
            if(i == -1 && j == -1){
                printf("y\\x");
            }else if(i == -1 && j > -1){
                if(j < 10){
                    printf("%d  ",j);
                }else if(j<100){
                    printf("%d ",j);
                }
            }else if(j == -1){
                if(i < 10){
                    printf("%d  ",i);
                }else if(i<100){
                    printf("%d ",i);
                }
            }else{
                setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                switch(plateau[player][i][j]){
                    case CORVETTE_ID:
                        printf("0  ");
                        break;
                    case DESTROYER_ID:
                        printf("0  ");
                        break;
                    case PORTE_AVION_ID:
                        printf("0  ");
                        break;
                    case CROISEUR_ID:
                        printf("0  ");
                        break;
                    default:
                        if(plateau[player][i][j]==8){
                            setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                        }else if(plateau[player][i][j]==9){
                            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        }
                        printf("%d  ",plateau[player][i][j]);
                        setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                }
            }
        }
        printf("\n");
    }
}

void printAllPlateau(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i;
    for(i=0;i<NB_PLAYER;i++){
        printTableau(i,plateau);
        printf("/////////////////////////////////////////////\n");
    }
}

void setPlateau(int player, int type, int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){

    setNavires(player,type,plateau);
}

void ia1(int playerToFire,int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int flag = 1;
    while(flag){
        int y = doRand(0,PLATEAU_WIDTH+1);
        int x = doRand(0,PLATEAU_HEIGHT+1);

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

void ia2(int playerToFire,int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int flag = 1;
    int i,j;
    while(flag){
        int y;
        int x;

        for(i=0;i<PLATEAU_HEIGHT;i++){
            for(j=0;j<PLATEAU_WIDTH;j++){
                if(plateau[playerToFire][i][j] != HIT && plateau[playerToFire][i][j] != MISS
                   && plateau[playerToFire][i][j] != 0 && doRand(0,99) < 75){
                    x = i;
                    y = j;
                }
            }
        }

        if(doRand(0,99) < 95){
            y = doRand(0,PLATEAU_WIDTH+1);
            x = doRand(0,PLATEAU_HEIGHT+1);
        }

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

void ia3(int playerToFire,int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int flag = 1;
    int i,j;
    while(flag){
        int y;
        int x;

        for(i=0;i<PLATEAU_HEIGHT;i++){
            for(j=0;j<PLATEAU_WIDTH;j++){
                if(plateau[playerToFire][i][j] != HIT && plateau[playerToFire][i][j] != MISS
                   && plateau[playerToFire][i][j] != 0 && doRand(0,99) < 75){
                    x = i;
                    y = j;
                }
            }
        }

        if(doRand(0,99) < 75){
            y = doRand(0,PLATEAU_WIDTH+1);
            x = doRand(0,PLATEAU_HEIGHT+1);
        }

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

void ia4(int lastHit[2],char* fileHit,int playerToFire,int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int flag = 1;
    int i,j;
    int y,x;

    saveTo1(lastHit,2,fileHit);

    while(flag){

        loadFrom1(lastHit,2,fileHit);

        if(lastHit[X]<PLATEAU_HEIGHT && lastHit[X]>-1
           && lastHit[Y]<PLATEAU_WIDTH && lastHit[Y]>-1
           && plateau[playerToFire][lastHit[X]][lastHit[Y]] == 8){
            for(i=0;i<4;i++){
                if(i==0
                    && (lastHit[X]+1<PLATEAU_HEIGHT
                    && plateau[playerToFire][lastHit[X]+1][lastHit[Y]] != 8
                    && plateau[playerToFire][lastHit[X]+1][lastHit[Y]] != 9)){
                    y = lastHit[Y];
                    x = lastHit[X]+1;
                    break;
                }else if(i==1
                    && lastHit[X]-1>=0
                    && plateau[playerToFire][lastHit[X]-1][lastHit[Y]] != 8
                    && plateau[playerToFire][lastHit[X]-1][lastHit[Y]] != 9){
                    y = lastHit[Y];
                    x = lastHit[X]-1;
                    break;
                }else if(i==2
                    && lastHit[Y]+1<PLATEAU_WIDTH
                    && plateau[playerToFire][lastHit[X]][lastHit[Y]+1] != 8
                    && plateau[playerToFire][lastHit[X]][lastHit[Y]+1] != 9){
                    y = lastHit[Y]+1;
                    x = lastHit[X];
                    break;
                }else if(i==3
                    && lastHit[Y]-1>=0
                    && plateau[playerToFire][lastHit[X]][lastHit[Y]-1] != 8
                    && plateau[playerToFire][lastHit[X]][lastHit[Y]-1] != 9){
                    y = lastHit[Y]-1;
                    x = lastHit[X];
                    break;
                }
            }
            if(i == 4){
                for(j=0;j<2;j++){
                    lastHit[j]=-2;
                }
                saveTo1(lastHit,2,fileHit);
            }
        }else{
            y = doRand(0,PLATEAU_WIDTH+1);
            x = doRand(0,PLATEAU_HEIGHT+1);
        }

        if(plateau[playerToFire][x][y] != HIT && plateau[playerToFire][x][y] != MISS){
            if(plateau[playerToFire][x][y] != 0){
                printf("hit %d %d\n",x,y);
                plateau[playerToFire][x][y] = HIT;
                lastHit[X]=x;
                lastHit[Y]=y;
                saveTo1(lastHit,2,fileHit);
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

int selectIADifficulty(){
    int ia = -1;

    do{
        system("cls");
        printf("#############################\n");
        printf("#   Select ia level         #\n");
        printf("#############################\n\n");
        printf("1 => easy\n");
        printf("2 => medium\n");
        printf("3 => hard\n");
        printf("4 => human\n");
        scanf("%d",&ia);
        fflush(stdin);
    }while(ia<1||ia>4);
    return ia;
}

void playIAvsIA(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 1;
    int j;
    int iaJ1 = selectIADifficulty();
    int iaJ2 = selectIADifficulty();

    int lastHitIA1[2];
    int lastHitIA2[2];

    for(j=0;j<2;j++){
        lastHitIA1[j]=-2;
        lastHitIA2[j]=-2;
    }


    while(notAlreadyDead(plateau)){
        printf("turn %d\n",i);
        switch(iaJ1){
            case 1:
                ia1(1,plateau);
                break;
            case 2:
                ia2(1,plateau);
                break;
            case 3:
                ia3(1,plateau);
                break;
            case 4:
                ia4(lastHitIA1,"ia1Hit",1,plateau);
                break;
        }
        switch(iaJ2){
            case 1:
                ia1(0,plateau);
                break;
            case 2:
                ia2(0,plateau);
                break;
            case 3:
                ia3(0,plateau);
                break;
            case 4:
                ia4(lastHitIA2,"ia2Hit",0,plateau);
                break;
        }
        savePlateau(plateau);
        i++;
        printAllPlateau(plateau);
        getchar();
    }
}

void joueur(int currentPlayer, int playerToFire,int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int flag = 1;
    int x;
    int y;

    printMyTableau(currentPlayer,plateau);

    while(flag){
        printHiddenTableau(playerToFire,plateau);
        y = checkSaisi(0,PLATEAU_WIDTH-1,"Coordonnee y\n");
        x = checkSaisi(0,PLATEAU_HEIGHT-1,"Coordonnee x\n");

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
        }else{
            printf("Coordonnees invalide\n");
        }
    }
}

void playJoueurvsIA(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 1;
    int iaJ2 = selectIADifficulty();
    while(notAlreadyDead(plateau)){
        system("cls");
        printf("turn %d\n",i);
        joueur(0,1,plateau);
        system("cls");
        printf("turn %d\n",i);
        switch(iaJ2){
            case 1:
                ia1(0,plateau);
                break;
            case 2:
                ia2(0,plateau);
                break;
            case 3:
                ia3(0,plateau);
                break;
        }
        savePlateau(plateau);
        i++;
    }
}

void playJoueurvsJoueur(int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH]){
    int i = 1;
    while(notAlreadyDead(plateau)){
        system("cls");
        printf("turn %d\n",i);
        joueur(0,1,plateau);
        printf("Appuyer sur entre pour joueur2");
        getchar();
        system("cls");
        printf("turn %d\n",i);
        joueur(1,0,plateau);
        printf("Appuyer sur entre pour joueur1");
        getchar();
        savePlateau(plateau);
        i++;
    }
}

int battleShip(){
    playMode();

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
    int selection = -1;
    int isLoaded = 1;
    int plateau[NB_PLAYER][PLATEAU_HEIGHT][PLATEAU_WIDTH];


    while(selection){
        system("cls");
        selection = -1;

        if(isLoaded){
            purgeTableau(plateau);
        }

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("#############################\n");
        printf("#   Welcome to battleship   #\n");
        printf("#   Select your game mode   #\n");
        printf("#############################\n\n");
        printf("1 => ia vs ia\n");
        printf("2 => player vs ia\n");
        printf("3 => player vs player\n");
        printf("4 => load game\n");
        printf("0 => leave\n");
        scanf("%d[0-9]",&selection);
        setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        switch(selection){
            case 1 :
                if(isLoaded){
                    setPlateau(0,IA,plateau);
                    setPlateau(1,IA,plateau);
                }
                playIAvsIA(plateau);
                printAllPlateau(plateau);
                fflush(stdin);
                getchar();
                break;
            case 2 :
                if(isLoaded){
                    setPlateau(0,PLAYER,plateau);
                    setPlateau(1,IA,plateau);
                }
                playJoueurvsIA(plateau);
                printAllPlateau(plateau);
                fflush(stdin);
                getchar();
                break;
            case 3 :
                if(isLoaded){
                    setPlateau(0,PLAYER,plateau);
                    setPlateau(1,PLAYER,plateau);
                }
                playJoueurvsJoueur(plateau);
                printAllPlateau(plateau);
                fflush(stdin);
                getchar();
                break;
            case 4 :
                loadPlateau(plateau);
                isLoaded = 0;
                break;
        }
    }

}

int main()
{
    battleShip();
}
