#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80
#define MAX_LEN_POSSIBLE (int)(65535 / sizeof(int))

char inputChar(){
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
