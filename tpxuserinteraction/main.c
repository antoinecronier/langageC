#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_LEN 80
#define MAX_LEN_POSSIBLE (int)(65535 / sizeof(int))

//Textcolor function
#define RESET		0
#define BRIGHT 		1
#define DIM		    2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		    1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

//Windows
//Color use for console with #include <windows.h> and SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
/*Attribute	                Meaning
FOREGROUND_BLUE	            Text color contains blue.
FOREGROUND_GREEN	        Text color contains green.
FOREGROUND_RED	            Text color contains red.
FOREGROUND_INTENSITY	    Text color is intensified.
BACKGROUND_BLUE	            Background color contains blue.
BACKGROUND_GREEN	        Background color contains green.
BACKGROUND_RED	            Background color contains red.
BACKGROUND_INTENSITY	    Background color is intensified.
COMMON_LVB_LEADING_BYTE	    Leading byte.
COMMON_LVB_TRAILING_BYTE	Trailing byte.
COMMON_LVB_GRID_HORIZONTAL	Top horizontal.
COMMON_LVB_GRID_LVERTICAL	Left vertical.
COMMON_LVB_GRID_RVERTICAL	Right vertical.
COMMON_LVB_REVERSE_VIDEO	Reverse foreground and background attributes.
COMMON_LVB_UNDERSCORE	    Underscore.*/

//Background color to use with system("COLOR FC");
/*0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White*/

void setConsoleColor(WORD input){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, input);
}

/*void textcolor(int attr, int fg, int bg)
{	char command[13];

	// Command is the control command to the terminal
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}*/

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
        printf ("# 4 : speak with user                  #\n");
        printf ("########################################\n");
        printf ("\n");
        fflush(stdout);

        /* Restore original attributes */
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        //textcolor(RESET, WHITE, BLACK);
}

int userInputInt(int menuItems){

    int i = 0;
    int userChoise = 1;
    char userNumber[MAX_LEN];

    while(userChoise){
        printf ("Select an item ('q' to leave): ");
        scanf ("%s", userNumber);

        if(*userNumber == 'q'){
            exit(0);
        }else{
            userChoise = atoi(userNumber);
            printf ("Sitem print: %d ",userChoise);
            if(userChoise != 0){
                for(i = 0; i <= menuItems; i++){
                    if(userChoise == i){
                        return userChoise;
                    }
                }
                printf ("Please use a numbers link to current menu ");

            }else{
                userChoise = 1;
                printf ("Please use just numbers ");
            }
        }
    }

    return 0;
}

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

char mathInputChar(){
    int userChoise = 1;
    char userNumber[1];

    while(userChoise){
        scanf ("%s", userNumber);

            userChoise = atoi(userNumber);
            if(userChoise == 0){
                    if(*userNumber == '+' || *userNumber == '-' || *userNumber == '/' || *userNumber == 'x' || *userNumber == 'q'){
                        return *userNumber;
                    }
            }else{
                userChoise = 1;
            }
            printf ("Please use just alpha +, -, /, x ");
    }

    return 0;
}

int mathInputInt(){
    int userChoise = 1;
    char userNumber[MAX_LEN_POSSIBLE];

    while(userChoise){
        scanf ("%s", userNumber);

            userChoise = atoi(userNumber);
            if(userChoise != 0 || *userNumber == 'q'){
                return userChoise;
            }else{
                userChoise = 1;
                printf ("Please use just numbers ");
            }
    }

    return 0;
}

float mathInputFloat(){
    float userChoise = 1;
    char userNumber[MAX_LEN_POSSIBLE];

    while(userChoise){
        scanf ("%s", userNumber);

            userChoise = atof(userNumber);
            if(userChoise != 0 || *userNumber == 'q'){
                return userChoise;
            }else{
                userChoise = 1;
                printf ("Please use just numbers ");
            }
    }

    return 0;
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

void basicEntierCalc()
{
    int userChoise = 0;
    int flag = 1;
    int result = 0;
    int tempResult = 0;
    char operatorCalc = 'a';

    system("cls");

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        //textcolor(BRIGHT, RED, BLACK);

        printf ("########################################\n");
        printf ("#### Welcome on calculator for int  ####\n");
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

    result = mathInputInt();

    while(flag){

        tempResult = result;
        operatorCalc = mathInputChar();
        result = mathInputInt();

        //Print calc to see steps
        printf("=> %d / %d = ", tempResult, result);

            if(operatorCalc == '+'){
                result = tempResult + result;
            }else if(operatorCalc == '-'){
                result = tempResult - result;
            }else if(operatorCalc == 'x'){
                result = tempResult * result;
            }else if(operatorCalc == '/'){
                result = tempResult / result;
            }else if(operatorCalc == 'q'){
                calculatorHomeDisplay();
                userChoise = userInputInt(3);
                calculatorHomeUse(userChoise);
            }
        printf("%d\n", result);
    }
}

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
        printf("=> %f / %f = ", tempResult, result);

            if(operatorCalc == '+'){
                result = tempResult + result;
            }else if(operatorCalc == '-'){
                result = tempResult - result;
            }else if(operatorCalc == 'x'){
                result = tempResult * result;
            }else if(operatorCalc == '/'){
                result = tempResult / result;
            }else if(operatorCalc == 'q'){
                calculatorHomeDisplay();
                userChoise = userInputInt(3);
                calculatorHomeUse(userChoise);
            }
        printf("%f\n", result);
    }
}

char needToExit(){
    int userChoise = 1;
    char userNumber[1];

    while(userChoise){
        scanf ("%s", userNumber);

            userChoise = atoi(userNumber);
            if(userChoise == 0){
                return *userNumber;
            }else{
                userChoise = 1;
            }
            printf ("Please use just alpha");
    }

    return 0;
}

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

void chartoascii(){
}

void asciitochar(){
}

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

void drawCircle(int width){
    int i = 0;
    int j = 0;

    if(width % 2 == 0){
        for(i = 0; i < width / 2; i++){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i) || j == ((width / 2) - i))){
                    printf ("*");
                }else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(i = width / 2; i > 0; i--){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i) || j == ((width / 2) - i))){
                    printf ("*");
                }else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(j = 0; j <= width; j++){
            if(j == ((width / 2) + i)){
                printf ("*");
            }else{
                printf (" ");
            }
        }
        printf ("\n");
    }else{
        for(i = 0; i < width / 2; i++){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i + 1) || j == ((width / 2) - i))){
                    printf ("*");
                }
                else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(i = width / 2; i > 0; i--){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i + 1) || j == ((width / 2) - i))){
                    printf ("*");
                }
                else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(j = 0; j <= width; j++){
            if((j == ((width / 2) + i) || j == ((width / 2) - i + 1))){
                printf ("*");
            }else{
                printf (" ");
            }
        }
        printf ("\n");
    }
}

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
        break;
        default:
        break;
    }
}

int main()
{
    int userChoise = 0;

    menuHomeDisplay();
    userChoise = userInputInt(4);
    menuHomeUse(userChoise);

    return 0;
}
