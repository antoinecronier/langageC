//Windows
//Color use for console with #include <windows.h> and SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
/*Attribute	                Meaning
FOREGROUND_BLUE	            Text color contains blue.
FOREGROUND_GREEN	        Text color contains green.
FOREGROUND_RED	            Text color contains red.
FOREGROUND_INTENSITY	    Text color is intensified.
BACKGROUND_BLUE	            Background color contains blue.
BACKGROUND_GREEN	        Background color contains green.
BACKGROUND_RED	            Background color contains red.
BACKGROUND_INTENSITY	    Background color is intensified.
COMMON_LVB_LEADING_BYTE	    Leading byte.
COMMON_LVB_TRAILING_BYTE	Trailing byte.
COMMON_LVB_GRID_HORIZONTAL	Top horizontal.
COMMON_LVB_GRID_LVERTICAL	Left vertical.
COMMON_LVB_GRID_RVERTICAL	Right vertical.
COMMON_LVB_REVERSE_VIDEO	Reverse foreground and background attributes.
COMMON_LVB_UNDERSCORE	    Underscore.*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void setConsoleColor(WORD input){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, input);
}
