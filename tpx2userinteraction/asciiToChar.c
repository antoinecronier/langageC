#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void asciitochar(){
    int userChoise = 0;
    char didExit = 'a';
    while(1){
        int c;

        system("cls");

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        printf ("########################################\n");
        printf ("######  Welcome on ascii to char  ######\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# Press ascii and get it to char       #\n");
        printf ("# 1 : take a int ascii table 0 - 127   #\n");
        printf( "# 2 : validate                         #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        printf("Enter a int: ");
        c = mathInputInt();
        printf("Int value of %c = %d\n",c,c);

        printf ("Do you want to exit? (q) :");
        didExit = needToExit();
        if(didExit == 'q'){
            asciiHomeDisplay();
            userChoise = userInputInt(3);
            asciiHomeUse(userChoise);
        }
    }
}
