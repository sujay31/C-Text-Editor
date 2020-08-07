/* Additional code-1 
   Code for rectangular star border.*/

/* header file contains input/output related functions. */
#include <stdio.h>

/* header file contains system commands. */
#include <stdlib.h>

/* moves the file pointer horizontally by putting a given character(ch) a fixed no.(i) of times. */
void moveOffsetHorizontal(FILE *fp,int i, char ch)
{
    for(int j=0; j<i; j++)
        fputc(ch, fp);
}

/* moves the file pointer vertically down by given(i) lines. */
void moveOffsetVertical(FILE *fp,int i)
{
    for(int j=0; j<i; j++)
        fputc('\n', fp);
}

/* makes a complete line of '*' border. */
void makeHorizontalLine(FILE *fp)
{
    moveOffsetHorizontal(fp, 28, ' ');
    moveOffsetHorizontal(fp, 103, '*');
    fputc('\n', fp);
}

/* writes 101 characters(spaces) inside both the sides of border. */
int makeVerticalLine(FILE *fp, int i)
{
    if(i==29)
        return 1;
    else
    {
        moveOffsetHorizontal(fp, 28, ' ');
        fputc('*', fp);
        moveOffsetHorizontal(fp, 101, ' ');
        fputc('*', fp);
        fputc('\n', fp);
        makeVerticalLine(fp, ++i);
    }
    
}

/* calls suitable functions to write text and make a border around it. */
void makeBorder(FILE *fp)
{
    moveOffsetVertical(fp, 5);
    makeHorizontalLine(fp);
    makeVerticalLine(fp, 0);
    makeHorizontalLine(fp);
    moveOffsetVertical(fp, 5);
}

int main()
{
    system("clear");
    printf("\n");
    FILE *fp;
    fp=fopen("interface.txt","w");
    makeBorder(fp);
    fclose(fp);
    system("cat interface.txt");
    remove("interface.txt");        //file removed
}