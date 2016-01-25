#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void chartoascii(){
    int userChoise = 0;
    char didExit = 'a';
    while(1){
        char c;

        system("cls");

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        printf ("########################################\n");
        printf ("######  Welcome on char to ascii  ######\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# Press char and get it to ascii       #\n");
        printf ("# 1 : take a char                      #\n");
        printf( "# 2 : validate                         #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        printf("Enter a character: ");
        c = inputChar();
        printf("ASCII value of %c = %d\n",c,c);

        printf ("Do you want to exit? (q) :");
        didExit = needToExit();
        if(didExit == 'q'){
            asciiHomeDisplay();
            userChoise = userInputInt(3);
            asciiHomeUse(userChoise);
        }
    }
}
