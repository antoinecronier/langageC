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

    //Create the result variable to store data
    int result = 0;

    //Cast the char value to int for result storing
    result = atoi(argv[1]);

    //Take all elements one by one
    for(i = 1; i < argc; i++){

        //Test if symbol + is find
        if(*argv[i] == '+'){
            //Increment i to find value next to symbol
            i++;
            result = result + atoi(argv[i]);

        //Test if symbol - is find
        }else if(*argv[i] == '-'){
            //Increment i to find value next to symbol
            i++;
            result = result - atoi(argv[i]);

        //Test if symbol x is find
        }else if(*argv[i] == 'x'){
            //Increment i to find value next to symbol
            i++;
            result = result * atoi(argv[i]);

        //Test if symbol / is find
        }else if(*argv[i] == '/'){
            //Increment i to find value next to symbol
            i++;

            //Test if value is not 0
            if(atoi(argv[i]) != 0){
                result = result / atoi(argv[i]);
            }else{
                //If it is 0 stop and print issue
                result = 0;
                printf("Division par 0 impossible");
                return 0;
            }
        }

        //Print calc to see steps
        printf("=> %d / %d\n", result, atoi(argv[i]));
        fflush(stdout);
    }
    printf("Le resultat est %d", result);

    return 0;
}
