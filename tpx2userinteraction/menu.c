#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void menuHomeDisplay(){

        system("cls");

        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        //textcolor(BRIGHT, RED, BLACK);

        printf ("########################################\n");
        printf ("###### Welcome on my greatest app ######\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# Press number to enter under parts    #\n");
        printf ("# 1 : test user input to have numbers  #\n");
        printf( "# 2 : test user input to have ascii    #\n");
        printf ("# 3 : print geometrical form to user   #\n");
        printf ("# 4 : quit                             #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        //textcolor(RESET, WHITE, BLACK);
}

void menuHomeUse(int choise){
    int userChoise = 0;
    switch(choise){
        case 1:
            calculatorHomeDisplay();
            userChoise = userInputInt(3);
            calculatorHomeUse(userChoise);
        break;
        case 2:
            asciiHomeDisplay();
            userChoise = userInputInt(3);
            asciiHomeUse(userChoise);
        break;
        case 3:
            geoHomeDisplay();
            userChoise = userInputInt(3);
            geoHomeUse(userChoise);
        break;
        case 4:
            exit(0);
        break;
        default:
        break;
    }
}
