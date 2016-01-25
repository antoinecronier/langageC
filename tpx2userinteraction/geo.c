#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void geoHomeDisplay(){

    system("cls");

    setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        //textcolor(BRIGHT, RED, BLACK);

        printf ("########################################\n");
        printf ("######       Welcome on geo       ######\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# Press number to enter under parts    #\n");
        printf ("# 1 : square                           #\n");
        printf( "# 2 : circle                           #\n");
        printf ("# 3 : back to previous menu            #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        //textcolor(RESET, WHITE, BLACK);
}

void geoHomeUse(int choise){
    int userChoise = 0;
    switch(choise){
        case 1:
            squareGeo();
        break;
        case 2:
            circleGeo();
        break;
        case 3:
            menuHomeDisplay();
            userChoise = userInputInt(4);
            menuHomeUse(userChoise);
        break;
        default:
        break;
    }
}
