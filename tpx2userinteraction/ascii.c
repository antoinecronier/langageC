#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void asciiHomeDisplay(){

    system("cls");

    setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        //textcolor(BRIGHT, RED, BLACK);

        printf ("########################################\n");
        printf ("######      Welcome on ascii       ######\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# Press char and get it to ascii       #\n");
        printf ("# 1 : char to ascii                    #\n");
        printf( "# 2 : ascii to char                    #\n");
        printf ("# 3 : back to previous menu            #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        //textcolor(RESET, WHITE, BLACK);
}

void asciiHomeUse(int choise){
    int userChoise = 0;
    switch(choise){
        case 1:
            chartoascii();
        break;
        case 2:
            asciitochar();
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
