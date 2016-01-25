#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 80

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
                printf ("Please use a numbers between 1 et %d ", userChoise - 1);

            }else{
                userChoise = 1;
                printf ("Please use just numbers ");
            }
        }
    }

    return 0;
}

void game1(){
    int test = 0;
    int value = 0;
    int flag = 1;

    value = rand() % (100 - 1) + 1;

    printf ("Game 1 : Computer have choose a number it will say you if it is more or less find it \n");
    while(flag){
        printf ("Please enter a numbers \n");
        test = userInputInt(100);

        if(test == value){
            printf ("Well played number to find was %d \n", value);
            flag = 0;
        }else if(test > value){
            printf ("It is less than %d \n", test);
        }else{
            printf ("It is more than %d \n", test);
        }
    }
}

void game2(){
    int value = 0;

    int testNb = 0;
    int nbUser[10];
    int i = 0;
    int flag1 = 1;
    int flag2 = 1;
    int flag3 = 1;
    int flag4 = 1;
    int flag5 = 1;
    int flag6 = 1;
    int flag7 = 1;
    int flag8 = 1;
    int flag9 = 1;
    int flag10 = 1;

    printf ("Game 2 : Chose 10 numbers between 1 and 1000 computer will run since it found them \n");

    for(i = 0; i < 10; i++){
        printf("Current item is : %d \n", i + 1);
        nbUser[i] = userInputInt(1000);
    }

    while(flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8 || flag9 || flag10){
        value = rand() % (1000 - 1) + 1;
        //printf("Computer say : %d \n", value);
        if(value == nbUser[0]){
            flag1 = 0;
            testNb++;
        }
        if(value == nbUser[1]){
            flag2 = 0;
            testNb++;
        }
        if(value == nbUser[2]){
            flag3 = 0;
            testNb++;
        }
        if(value == nbUser[3]){
            flag4 = 0;
            testNb++;
        }
        if(value == nbUser[4]){
            flag5 = 0;
            testNb++;
        }
        if(value == nbUser[5]){
            flag6 = 0;
            testNb++;
        }
        if(value == nbUser[6]){
            flag7 = 0;
            testNb++;
        }
        if(value == nbUser[7]){
            flag8 = 0;
            testNb++;
        }
        if(value == nbUser[8]){
            flag9 = 0;
            testNb++;
        }
        if(value == nbUser[9]){
            flag10 = 0;
            testNb++;
        }

        for(i = 0; i < 10; i++){
            if(value != nbUser[i]){
                testNb++;
            }
        }
    }

    printf("Result found after %d tests\n", testNb);
}

void game3(){
    int value = 0;

    int testNb = 0;
    int nbUser[10];
    int i = 0;
    int flag1 = 1;
    int flag2 = 1;
    int flag3 = 1;
    int flag4 = 1;
    int flag5 = 1;
    int flag6 = 1;
    int flag7 = 1;
    int flag8 = 1;
    int flag9 = 1;
    int flag10 = 1;

    printf ("Game 3 : Chose 10 different numbers between 1 and 1000 computer will run since it found them \n");

    for(i = 0; i < 10; i++){
        printf("Current item is : %d \n", i + 1);
        nbUser[i] = userInputInt(1000);
    }

    while(flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8 || flag9 || flag10){
        value = rand() % (1000 - 1) + 1;
        //printf("Computer say : %d \n", value);
        if(value == nbUser[0]){
            flag1 = 0;
            testNb++;
        }
        else if(value == nbUser[1]){
            flag2 = 0;
            testNb++;
        }
        else if(value == nbUser[2]){
            flag3 = 0;
            testNb++;
        }
        else if(value == nbUser[3]){
            flag4 = 0;
            testNb++;
        }
        else if(value == nbUser[4]){
            flag5 = 0;
            testNb++;
        }
        else if(value == nbUser[5]){
            flag6 = 0;
            testNb++;
        }
        else if(value == nbUser[6]){
            flag7 = 0;
            testNb++;
        }
        else if(value == nbUser[7]){
            flag8 = 0;
            testNb++;
        }
        else if(value == nbUser[8]){
            flag9 = 0;
            testNb++;
        }
        else if(value == nbUser[9]){
            flag10 = 0;
            testNb++;
        }else{
            testNb++;
        }
    }

    printf("Result found after %d tests\n", testNb);
}

int test(int indice){
    switch(indice){
        case 1 :
            return 1;
            break;
        case 2 :
            return 1;
            break;
        case 3 :
            return 0;
            break;
        case 4 :
            return 1;
            break;
    }
}

void game4(){
    int value = 1;
    while(value){
        value = userInputInt(4);
        if(test(value)){
            printf("hi \n");
        }
    }
}

int main()
{
    /*
    game1();
    game2();
    game3();
    */
    game4();

    return 0;
}
