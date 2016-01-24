#include <stdio.h>
#include <stdlib.h>

//argc is an integer value, argv is a pointer to a char tab
int main(int argc, char *argv[])
{
    //Init a new variable named i with value 0
    int i = 0;

    //Display a string to console with %d to add numeric value from argc variable
    printf("Il y a %d parametre \n", argc);

    //Use to display printf because of stack list buffering
    fflush(stdout);

    //Decremental loop starting to argc value and decrementing i each loop by 1 to reach 0 value
    for(i = argc; i > 0; i--){
        printf("Le %d element passe en parametre est %s\n", argc - (i-1) ,argv[(argc - i)]);
    }

    return 0;
}
