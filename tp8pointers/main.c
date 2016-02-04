#include <stdio.h>
#include <stdlib.h>

#define aliasedInt int

void doStuff(int value){
    value = value * value;
    printf("In doStuff value = %d\n", value);
}

void doStuffP1(int* value){
    value = *value * *value;
    printf("In doStuffP1 value = %d\n", value);
}

void doStuffP2(int* value){
    *value = *value * *value;
    printf("In doStuffP2 value = %d\n", *value);
}

int main()
{
    int intval = 10;
    int* pintval = intval;

    char charval = 'a';
    char* pcharval = charval;

    printf("Asign value to pointers \n");
    printf("intval = %d, &intval = %x, pintval = %x, &pintval = %x \n", intval, &intval, pintval, &pintval);
    printf("charval = %c, &charval = %x, pcharval = %c, &pcharval = %x \n", charval, &charval, pcharval, &pcharval);

    printf("\n");

    doStuff(intval);
    printf("Outside doStuff value = %d\n", intval);
    doStuffP1(&intval);
    printf("Outside doStuffP1 value = %d\n", intval);
    doStuffP2(&intval);
    printf("Outside doStuffP2 value = %d\n", intval);

    printf("\n");

    printf("Asign value address to pointers \n");
    pintval = &intval;
    pcharval = &charval;
    printf("intval = %d, &intval = %x, pintval = %x, &pintval = %x, *pintval = %d \n", intval, &intval, pintval, &pintval, *pintval);
    printf("charval = %c, &charval = %x, pcharval = %x, &pcharval = %x, *pcharval = %c \n", charval, &charval, pcharval, &pcharval, *pcharval);

    printf("\n");

    doStuff(intval);
    printf("Outside doStuff value = %d\n", intval);
    doStuffP1(&intval);
    printf("Outside doStuffP1 value = %d\n", intval);
    doStuffP2(&intval);
    printf("Outside doStuffP2 value = %d\n", intval);

    /*int i = 0;
    int tab1[5] = {1,2,3,4,5};
    int* pTab = tab1;

    for(i = 0; i < 5; i++){
        printf("Array values at position %d = %d\n", i, *pTab);
        pTab++;
    }*/

    /*int i,j = 0;
    int tab1[5][5];
    int** pTab = tab1;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            tab1[i][j] = i + j;
            printf("Array values at position x : %d y : %d = %d\n", i, j, *pTab);
            pTab++;
        }
    }*/

    aliasedInt i,j,k = 0;
    aliasedInt tab1[5][5][5];
    int** pTab = tab1;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            for(k = 0; k < 5; k++){
                tab1[i][j][k] = i + j + k;
                printf("Array values at position x:%d y:%d z:%d = %d\n", i, j, k, *pTab);
                pTab++;
            }
        }
    }

    return 0;
}
