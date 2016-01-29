#include <stdio.h>
#include <stdlib.h>

int main()
{
    int user = 10;
    while(user){
        int i = 0;

        char myTab[20] = {""};

        printf("Choix menu :\n1:espace\n2:inverse\n3:demi\n");
        scanf("%d", &user);
        user = atoi(user);

        if(user == 1){
            scanf("%s", myTab);
            for(i=0; i<20; i++){
                printf("%c ", myTab[i]);
            }
            fflush(stdin);

            printf("\n");
        }else if(user == 2){
            for(i=19; i>=0; i--){
                printf("%c", myTab[i]);
            }

            fflush(stdin);

            printf("\n");
        }else if(user == 3){
            for(i=0; i<20; i++){
                if(i % 2 == 0){
                    printf("%c ", myTab[i]);
                }
            }

            fflush(stdin);

            printf("\n");
        }else{
        }
    }
}
