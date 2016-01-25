#include <stdio.h>
#include <stdlib.h>

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
