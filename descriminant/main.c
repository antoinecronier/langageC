#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcRacine1(int a, int b, int delta){
    return ((-b + sqrt(delta)) /  (2 * a));
}

int calcRacine2(int a, int b, int delta){
    return ((-b - sqrt(delta)) /  (2 * a));
}

void test(int a, int b, int delta){
    if(delta > 0){
        printf("deux racines\n");
        printf("delta = %d\n", delta);
        printf("racine 1 = %d\n", calcRacine1(a, b, delta));
        printf("racine 2 = %d\n", calcRacine2(a, b, delta));
    }else if(delta == 0){
        printf("une racine\n");
        printf("delta = %d\n", delta);
        printf("racine = %d\n", calcRacine1(a, b, delta));
    }else{
        printf("zero racine\n");
        printf("delta = %d\n", delta);
    }
}

int descriminant(int a, int b, int c){
    return (b*b - (4 * a * c));
}

void polycalc(){
    int a = 0;
    int b = 0;
    int c = 0;
    int flag = 1;

    while(flag){
        printf("calcul de racine pour 'ax² + bx + c'\n");
        printf("a = ?\n");
        scanf("%d",&a);
        printf("b = ?\n");
        scanf("%d",&b);
        printf("c = ?\n");
        scanf("%d",&c);

        test(a,b,descriminant(a,b,c));

        printf("stop ? use 0\n");
        scanf("%d",&flag);
        fflush(stdin);
        system("cls");
    }
}

//////////////////////////////////////////////////////////

void calcRacine1Ref(int* a, int* b, int* delta, int* res){
    *res = ((-*b + sqrt(*delta)) /  (2 * *a));
}

void calcRacine2Ref(int* a, int* b, int* delta, int* res){
    *res = ((-*b - sqrt(*delta)) /  (2 * *a));
}

void testRef(int* a, int* b, int* delta){
    int res = 0;
    if(*delta > 0){
        printf("deux racines\n");
        printf("delta = %d\n", *delta);
        calcRacine1Ref(a, b, delta, &res);
        printf("racine 1 = %d\n", res);
        calcRacine2Ref(a, b, delta, &res);
        printf("racine 2 = %d\n", res);
    }else if(*delta == 0){
        printf("une racine\n");
        printf("delta = %d\n", *delta);
        calcRacine1Ref(a, b, delta, &res);
        printf("racine = %d\n", res);
    }else{
        printf("zero racine\n");
        printf("delta = %d\n", *delta);
    }
}

void descriminantRef(int* a, int* b, int* c, int* desc){
    *desc = (*b * *b - (4 * *a * *c));
}

void trace(int a, int b, int c){
    int i = 0;
    int j = -10;
    int values[20] = {0};

    for(i = 0; i < 20; i++){
        values[i] = a*(j*j) + b*j + c;
        j++;
        printf("indice %d value %d\n",i,values[i]);
    }

    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){

            if(i == 9 && j == 9){
                printf("+");
            }else{
                if(j == 9){
                    printf("|");
                }else{
                    if(values[i] == j - 10){
                        printf("x");
                    }else{
                        printf(" ");
                    }
                }
                if(i == 9){
                    printf("-");
                }else{
                    if(values[i] == j - 10){
                        printf("x");
                    }else{
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}

void polycalcRef(){
    int a = 0;
    int b = 0;
    int c = 0;
    int desc = 0;
    int flag = 1;

    while(flag){
        printf("calcul de racine pour 'ax² + bx + c'\n");
        printf("a = ?\n");
        scanf("%d",&a);
        printf("b = ?\n");
        scanf("%d",&b);
        printf("c = ?\n");
        scanf("%d",&c);

        descriminantRef(&a,&b,&c,&desc);
        testRef(&a,&b,&desc);

        trace(a,b,c);

        printf("stop ? use 0\n");
        scanf("%d",&flag);
        fflush(stdin);
        system("cls");
    }
}

int main()
{
    printf("Hello world!\n");
    //polycalc();

    polycalcRef();

    return 0;
}
