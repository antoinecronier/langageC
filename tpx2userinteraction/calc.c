#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void calculatorHomeDisplay(){

    system("cls");

    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        //textcolor(BRIGHT, RED, BLACK);

        printf ("########################################\n");
        printf ("######    Welcome on calculator   ######\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# Press number to enter under parts    #\n");
        printf ("# 1 : use basic calculator for int     #\n");
        printf( "# 2 : use basic calculator for float   #\n");
        printf ("# 3 : back to previous menu            #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        //textcolor(RESET, WHITE, BLACK);
}

void calculatorHomeUse(int choise){
    int userChoise = 0;
    switch(choise){
        case 1:
            basicEntierCalc();
        break;
        case 2:
            basicRealCalc();
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
