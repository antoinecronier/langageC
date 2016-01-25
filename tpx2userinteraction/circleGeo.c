#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void circleGeo(){
    int userChoise = 0;
    int flag = 1;
    char didExit = 'a';

    while(flag){
        int width = 0;
        system("cls");

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        printf ("########################################\n");
        printf ("####        Welcome on circle        ###\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# To draw a circle                     #\n");
        printf ("# 1 : select radius                    #\n");
        printf ("# 3 : repeat                           #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        while(width < 3){
            printf ("Enter radius > 2 :");
            width = mathInputInt();
        }

        drawCircle(width);

        printf ("Do you want to exit? (q) :");
        didExit = needToExit();
        if(didExit == 'q'){
            geoHomeDisplay();
            userChoise = userInputInt(3);
            geoHomeUse(userChoise);
        }
    }
}
