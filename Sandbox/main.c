#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char var = 0;


    //S1
    var = 12;
    var = 9;
    var = 14;
    var = 8;

    //S2
    var += 12;
    var -= 3;
    var += 5;
    var -= 6;


    char char1 = 123;
    int int1 = 25630;
    float float1 = 12365.89;
    double double1 = 2000000000;

    printf("%d\n",char1);
    printf("%c\n",char1);
    printf("%d\n",int1);
    printf("%f\n",float1);
    printf("%f\n",double1);

    char toPrint = 'K';
    char* toPrint1 = "KO";
    printf("%c\n",toPrint);
    printf("%s\n",toPrint1);

    // Aladin Jasmine
    char a, j, r;
    a = 5;
    j = 7;
    r = a + j;

    printf("they have : %d apples\n", r);
    printf("Aladin has %d apples, Jasmine has %d apples so they have %d apples\n"
           ,a, j, r);

    // User interaction
    /*int userResult = 0;
    printf("%p\n", &userResult);

    printf("Please enter a number\n");
    scanf("%d", &userResult);
    printf("Your number is %d\n", userResult);


    char charList [10] =  {'a','b','c'};
    printf("%s\n", charList);
    printf("%c\n", charList);

    scanf("%10[abcdefghijklmnopqrstuvwxyz0123456789]", charList);
    printf("%s\n", charList);

    scanf("%s", charList);
    fflush(stdin);
    printf("%s\n", charList);

    scanf("%c", charList);
    fflush(stdin);
    printf("%s\n", charList);*/


    int nbP1 = 0;
    int nbP2 = 0;

    printf("Please enter a number\n");
    scanf("%d", &nbP1);
    fflush(stdin);

    printf("Please enter a number\n");
    scanf("%d", &nbP2);
    fflush(stdin);

    if(nbP1 > nbP2){
        printf("nbP1 win\n");
    }

    if(nbP1 < nbP2){
        printf("nbP2 win\n");
    }

    if(nbP1 == nbP2){

        printf("equality\n");
    }

    return 0;
}
