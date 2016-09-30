#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{


    //App1();
    //App2();
    App3();

    return 0;
}

void App3(){

    //Variable
    char garbadge[1];
    char name[20];
    int userResult, i;


        //Name selection
        system("cls");
        printf("What is your name?\n");
        scanf("%20[a-zA-Z ]s",name);
        fflush(stdin); //=> Only run on windows

    while(1){
        //Menu
        do{
            system("cls");

            printf("What to do %s?\n",name);
            printf("1) Print name with space\n");
            printf("2) Print reversed name\n");
            printf("3) Print alternate name\n");

            scanf("%d",&userResult);
            fflush(stdin); //=> Only run on windows
        }while(userResult < 1 || userResult > 3);

        //Action
        switch(userResult){
            case 1:
                for(i = 0; i < 20; i++){
                        if(name[i] != '\0'){
                            printf("%c ",name[i]);
                        }else{
                            break;
                        }
                }
                printf("\n");
                break;
            case 2:
                for(i = 19; i >= 0; i--){
                    if(name[i] != '\0'){
                            printf("%c",name[i]);
                        }else{
                            break;
                        }
                }
                break;
            case 3:
                for(i = 0; i < 20; i++){
                            if(name[i] == '\0'){
                                break;
                            }else if (i%2==0){
                                printf("%c",name[i]);
                            }
                }
                break;
        }

        scanf("%s",garbadge);
        fflush(stdin);
    }
}
/*
void App2(){
    double i, j;
    int flag1 = 1;
    int a = 0;
    int b = 2;
    int c = 0;
    if(a == 1){
        printf("%d",a);
    }else if(b == 2){
        printf("%d",b);
    }else{
        printf("%d, %d",a,b);
    }
    for(i = 0; i < 4; i++){
        a += i;
        switch(a){
            case 0:
                printf("cas 0\n");
                break;
            case 1:
                printf("mon premier cas\n");
                break;
            case 2:
                printf("mon autre cas\n");
                break;
            default:
                printf("je ne sais pas\n");
        }
        printf("boucle %d\n",i);
    }

    for(j = 0; j <= 10; j++){
        printf("Table de %f\n",j);
        for(i = 0; i <= 10; i++){
            printf("  %f * %f = %f\n",j,i,pow(j,i));
        }
    }

    while(flag1){
        c = rand();
        printf("valeur de c %d\n",c);
        if(c%2 == 0){
            printf("nombre paire atteint\n");
            flag1 = 0;

        }
    }

    int userResult;
    do{
        printf("Please give me an int between ]0-100]\n");
        scanf("%d",&userResult);
        fflush(stdin); //=> Only run on windows
    }while(userResult <= 0 || userResult > 100);

    userResult = -1;
    while(userResult <= 0 || userResult > 100){
        printf("Please give me an int between ]0-100] 2\n");
        scanf("%d",&userResult);
        fflush(stdin); //=> Only run on windows
    }
}

void App1(){
//Variables
    int id = 0;
    char name[20] = {0};
    char surname[20] = {0};
    char uuid[10] = {0};
    char address[200] = {0};
    char login[20] = {0};
    char password[8] = {0};

    //Core code
    printf("Creating a new profil\n");
    printf("Enter your ID\n");
    scanf("%d",&id);
    fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    if(id < 0){
        printf("Insertion failed try again\n");
        scanf("%d",&id);
        fflush(stdin); //=> Only run on windows
        //fpurge(stdin); //=> Seems work on BSD
    }

    printf("Enter your name\n");
    scanf("%20s[a-zA-Z-]",name);
    fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    if(strlen(name)<4){
        printf("blablabla (en) not cool because name must be longer than four character\n");
        scanf("%20s[a-zA-Z-]",name);
        fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    }
    printf("Enter your surname\n");
    scanf("%20s[a-zA-Z]",surname);
    fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    printf("surname %s\n", surname);

    printf("Enter your UUID\n");
    scanf("%10s[a-zA-Z0-9-]",uuid);
    fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    if(strlen(uuid) != 10){
        printf("Try again\n");
        scanf("%10s[a-zA-Z0-9-]",uuid);
        fflush(stdin); //=> Only run on windows
        //fpurge(stdin); //=> Seems work on BSD
    }

    printf("Enter your address\n");
    scanf("%200s[a-zA-Z0-9- ]",address);
    fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    printf("Enter your login\n");
    scanf("%20s[a-zA-Z0-9]",login);
    fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    printf("Enter your password\n");
    scanf("%8s[a-zA-Z0-9!]",password);
    fflush(stdin); //=> Only run on windows
    //fpurge(stdin); //=> Seems work on BSD
    if(strlen(password) != 8 || strstr(password,"!") == NULL){
        printf("Try again\n");
        scanf("%8s[a-zA-Z0-9!]",password);
        fflush(stdin); //=> Only run on windows
        //fpurge(stdin); //=> Seems work on BSD
    }

    printf("So you are number %d, %s"
           ,id,name);
    printf(" - %s with uuid %s at %s with identifier %s and secret %s\n",surname,uuid,address,login,password);
}
*/
