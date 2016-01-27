#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80
#define MAX_LEN_POSSIBLE (int)(65535 / sizeof(int))

void drawCircle(int width){
    int i = 0;
    int j = 0;

    if(width % 2 == 0){
        for(i = 0; i < width / 2; i++){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i) || j == ((width / 2) - i))){
                    printf ("*");
                }else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(i = width / 2; i > 0; i--){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i) || j == ((width / 2) - i))){
                    printf ("*");
                }else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(j = 0; j <= width; j++){
            if(j == ((width / 2) + i)){
                printf ("*");
            }else{
                printf (" ");
            }
        }
        printf ("\n");
    }else{
        for(i = 0; i < width / 2; i++){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i + 1) || j == ((width / 2) - i))){
                    printf ("*");
                }
                else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(i = width / 2; i > 0; i--){
            for(j = 0; j <= width; j++){
                if((j == ((width / 2) + i + 1) || j == ((width / 2) - i))){
                    printf ("*");
                }
                else{
                    printf (" ");
                }
            }
            printf ("\n");
        }
        for(j = 0; j <= width; j++){
            if((j == ((width / 2) + i) || j == ((width / 2) - i + 1))){
                printf ("*");
            }else{
                printf (" ");
            }
        }
        printf ("\n");
    }
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

int main()
{
    int value = 0;
    printf("What is the radius of your circle ? : ");
    value = mathInputInt();
    drawCircle(value);
    return 0;
}
