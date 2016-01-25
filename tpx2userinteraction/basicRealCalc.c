#include <stdio.h>
#include <stdlib.h>
#include "consoleColor.h"

void basicRealCalc()
{
    int userChoise = 0;
    int flag = 1;
    float result = 0;
    float tempResult = 0;
    char operatorCalc = 'a';

    system("cls");

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        //textcolor(BRIGHT, RED, BLACK);

        printf ("########################################\n");
        printf ("#### Welcome on calculator for float ###\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        printf ("########################################\n");
        printf ("# Calc is done sequencialy             #\n");
        printf ("# 1 : enter your number                #\n");
        printf( "# 2 : enter your operator              #\n");
        printf ("# 3 : repeat                           #\n");
        printf ("# 4 : q to quit                        #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    result = mathInputFloat();

    while(flag){

        tempResult = result;
        operatorCalc = mathInputChar();
        result = mathInputFloat();

        //Print calc to see steps
            if(operatorCalc == '+'){
                printf("=> %d + %d = ", tempResult, result);
                result = tempResult + result;
            }else if(operatorCalc == '-'){
                printf("=> %d - %d = ", tempResult, result);
                result = tempResult - result;
            }else if(operatorCalc == 'x'){
                printf("=> %d x %d = ", tempResult, result);
                result = tempResult * result;
            }else if(operatorCalc == '/'){
                printf("=> %d / %d = ", tempResult, result);
                result = tempResult / result;
            }else if(operatorCalc == 'q'){
                calculatorHomeDisplay();
                userChoise = userInputInt(3);
                calculatorHomeUse(userChoise);
            }
        printf("%f\n", result);
    }
}
