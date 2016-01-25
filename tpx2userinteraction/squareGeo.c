#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void squareGeo(){
    int userChoise = 0;
    int i = 0;
    int j = 0;
    int flag = 1;
    char didExit = 'a';

    while(flag){
        int height = 0;
        int width = 0;
        system("cls");

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        printf ("########################################\n");
        printf ("####        Welcome on square        ###\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# To draw a square                     #\n");
        printf ("# 1 : select height                    #\n");
        printf( "# 2 : select width                     #\n");
        printf ("# 3 : repeat                           #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        while(height < 3){
            printf ("Enter height > 2 :");
            height = mathInputInt();
        }

        while(width < 3){
            printf ("Enter width > 2 :");
            width = mathInputInt();
        }

        for(i = 0; i < height; i++){
            for(j = 0; j< width; j++){
                printf ("#");
            }
            printf ("\n");
        }

        printf ("Do you want to exit? (q) :");
        didExit = needToExit();
        if(didExit == 'q'){
            geoHomeDisplay();
            userChoise = userInputInt(3);
            geoHomeUse(userChoise);
        }
    }
}
