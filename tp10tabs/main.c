#include <stdio.h>
#include <stdlib.h>

#define ARRAY2_LEN 3
#define ARRAY3_LEN 50

void array1(){
    int i = 0;
    int tab[] = {1,2,3,4,5,6,7,8,9,10};
    for(i=0 ; i < 10; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void array2(){
    int i = 0;
    int j = 0;

    int tab[ARRAY2_LEN][ARRAY2_LEN] = {
        {{1,1,1},{1,1,1},{1,1,1}},
        {{1,1,1},{1,1,1},{1,1,1}}
    };
    for(i=0 ; i < ARRAY2_LEN; i++){
        for(j=0 ; j < ARRAY2_LEN; j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void array3(){
    int i = 0;
    int j = 0;
    int nb = ARRAY3_LEN;

    int tab[nb][nb];
    for(i=0 ; i < nb; i++){
        for(j=0 ; j < nb; j++){
            tab[i][j] = 2;
        }
    }

    for(i=0 ; i < nb; i++){
        for(j=0 ; j < nb; j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void sumArray(int tab1[], int sizeTab1, int tab2[], int sizeTab2){
    int i = 0;
    int j = 0;

    if(sizeTab1 > sizeTab2){
        int result[sizeTab1];
        for(i=0 ; i < sizeTab1; i++){
            if(i < sizeTab2){
                result[i] = tab1[i] + tab2[i];
            }else{
                result[i] = tab1[i];
            }
        }
        for(j=0 ; j < sizeTab1; j++){
            printf("%d ",result[j]);
        }
        printf("\n");
    }else{
        int result[sizeTab2];
        for(i=0 ; i < sizeTab2; i++){
            if(i < sizeTab1){
                result[i] = tab1[i] + tab2[i];
            }else{
                result[i] = tab2[i];
            }
        }
        for(j=0 ; j < sizeTab2; j++){
            printf("%d ",result[j]);
        }
        printf("\n");
    }
}

int main()
{
    int tab1[] = {1,2,3,4,5,6};
    int tab2[] = {1,2,3,4,5,6,7};

    array1();
    array2();
    array3();
    sumArray(tab1, 6, tab2, 7);

    return 0;
}
