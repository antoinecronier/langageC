#include <stdio.h>
#include <stdlib.h>


int main()
{
    int user = 10;
    while(user){
        system("cls");
        int i = 0;

        char myTab[20] = {0};

        printf("Choix menu :\n1:espace\n2:inverse\n3:demi\n0 pour arrêter\n");
        scanf("%d", &user);
        fflush(stdin);

        if(user == 1){
            printf("Votre nom?\n");
            scanf("%[a-zA-Z]", myTab);
            for(i=0; i<20; i++){
                if(myTab[i]!=0){
                    printf("%c ", myTab[i]);
                }
            }
            fflush(stdin);
            getchar();
        }else if(user == 2){
            printf("Votre nom?\n");
            scanf("%[a-zA-Z]", myTab);
            for(i=19; i>=0; i--){
                if(myTab[i]!=0){
                    printf("%c", myTab[i]);
                }
            }

            fflush(stdin);
            getchar();
        }else if(user == 3){
            printf("Votre nom?\n");
            scanf("%[a-zA-Z]", myTab);
            for(i=0; i<20; i++){
                if(i % 2 == 0 && myTab[i]!=0){
                    printf("%c", myTab[i]);
                }
            }
            fflush(stdin);
            getchar();
        }else{
        }
    }
}
