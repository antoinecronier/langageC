#include <stdio.h>
#include <stdlib.h>

int main()
{
    int userChoise = 0;

    menuHomeDisplay();
    userChoise = userInputInt(4);
    menuHomeUse(userChoise);

    return 0;
}
