#include <stdio.h>
#include <stdlib.h>

int functionRecursive(int index){
    printf("Hello world!\n");
    functionRecursive(index);
}

int main()
{
    int i = 1;

    /*for(i=0; i < 4; i++){
        printf("Hello world!\n");
        i--;
    }*/

    /*for(i=0; i != -4; i++){
        printf("Hello world!\n");
    }*/

    /*for(;;){
        printf("Hello world!\n");
    }*/

    /*for(i=0; i < 4; i--){
        printf("Hello world!\n");
    }*/

    /*do{
        printf("Hello world!\n");
    }while(1);*/

    /*while(i){
        printf("Hello world!\n");
    }*/

    /*while(i == i){
        printf("Hello world!\n");
    }*/

    /*while((i = 3) > 2){
        printf("Hello world!\n");
        i++;
    }*/

    /*labelgoto:
    printf("Hello world!\n");
    goto labelgoto;*/

    functionRecursive(10);

    return 0;
}
