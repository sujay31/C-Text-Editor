/* header file contains input/output related functions. */
#include <stdio.h>

/* header file contains dynamic memory functions and exit function among others. */
#include <stdlib.h>

/* header file contains string related functions. */
#include <string.h>

/* header file contains character related functions. */
#include <ctype.h>

/* displays home page as landing page. */
int main() 
{
    system("clear");
    system("cat home.txt");
    char choice;
    printf("\033[1;33m ENTER W FOR WRITING, E FOR EDITING, S FOR RESAVING AN EXISTING FILE, F TO FIND A WORD, C TO COMPARE TWO FILES AND D TO DELETE A FILE. \033[0m \n");
    scanf("%c", &choice);
    if(choice=='W' || choice=='w')
        system("cat interface.txt");
    else
    {
        printf("\033[1;31m CHOICE UNAVAILABLE. PROGRAM HAS BEEN TERMINATED. \033[0m \n");
        exit(1);
    }
    
}