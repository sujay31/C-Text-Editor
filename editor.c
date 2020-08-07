/* header file contains input/output related functions. */
#include <stdio.h>

/* header file contains dynamic memory functions and exit function among others. */
#include <stdlib.h>

/* header file contains string related functions. */
#include <string.h>

/* header file contains character related functions. */
#include <ctype.h>

/*var to store user input. */
char *str=NULL;

/*var to store size of str. */
int size=100*sizeof(char);

/*prototypes of all the functions used. */
int acceptChoice();
void writeAndSave(FILE *fp);
void acceptInput();
char* correctInput();
void makeFile(FILE *fp);
void moveOffsetVertical(FILE *fp,int i);
void makeHorizontalLine(FILE *fp);
void moveOffsetHorizontal(FILE *fp,int i, char ch);
void beginLine(FILE *fp);
void endLine(FILE *fp);
void makeVerticalLine(FILE *fp);
void addLine(FILE *fp, int line);
void displayFile(FILE *fp, char name[100]);
void saveFile(char orig[100]);
char* getName();
int checkName(char name[100]);
void editByRewrite(FILE *fp);
void saveChanges(FILE *fp, char name[100]);
void editByAdd(FILE *fp);
void readFromFile(FILE *fp, char name[100]);
void saveAs(FILE *fp);;
void findWordOrPattern(FILE *fp);
int makeSearchResult(FILE *fp, char name[100], char word_to_search[25] );
void displaySearchResult(FILE *fp, char name[100], int occ);
void compareFiles(FILE *fp);
char* getData(FILE *fp);
void deleteFile(FILE *fp);

/* displays home page as landing page. */
int main() 
{
    system("clear");
    system("cat home.txt");
    FILE *fp;
    int task=acceptChoice();     
    if(task==1)
        writeAndSave(fp);
    else if(task==2)
        editByRewrite(fp);       
    else if(task==3)
        editByAdd(fp);
    else if(task==4)
        saveAs(fp);
    else if(task==5)
        findWordOrPattern(fp);  
    else if(task==6)
        compareFiles(fp);
    else if(task==7)
        deleteFile(fp);
    else
        printf("\033[1;31m OPTION UNAVAILABLE. \033[0m \n");    
    exit(0); 
    return 0;
}

/* accepts user's choice of task and sends the corresponding value to main. */
int acceptChoice()
{
    char choice;
    int val;
    printf("\033[1;33m ENTER W FOR WRITING, E FOR EDITING, S FOR RESAVING AN EXISTING FILE, F TO FIND A WORD, C TO COMPARE TWO FILES AND D TO DELETE A FILE. \033[0m \n");
    scanf("%c", &choice);
    
    /* comparison done is case insensitive so that there are lass chances of rejecting user's choice of task. */
    if(choice=='W' || choice=='w')
        return 1;
    else if(choice=='E' || choice=='e')
    {
        printf("\033[1;33m ENTER 1 TO REWRITE FILE OR 2 TO ADD MORE TEXT. \033[0m \n");
        scanf("%d", &val);
        if(val==1)
            return 2;
        else if(val==2)
            return 3;
        else
        {
            printf("\033[1;31m CHOICE UNAVAILABLE. PROGRAM HAS BEEN TERMINATED. \033[0m \n");
            exit(1);
        }
    }
    else if(choice=='S' || choice=='s')
        return 4;
    else if(choice=='F' || choice=='f')
        return 5;
    else if(choice=='C' || choice=='c')
        return 6;
    else if(choice=='D' || choice=='d')
        return 7;
    else
    {
        printf("\033[1;31m CHOICE UNAVAILABLE. PROGRAM HAS BEEN TERMINATED. \033[0m \n");
        exit(1);
    }
}

/* calls suitable functions to accept text entered by user and save it. */
void writeAndSave(FILE *fp)
{
    /* text is displayed on interface.txt along with a rectangular border. */
    fp=fopen("interface.txt","w");
    
    if(fp==NULL)
    {
        printf("\033[1;31m UNABLE TO PERFORM TASK. \033[0m \n");
        exit(1);
    }
    str=malloc(size);
    str[0]='\0';
    printf("%s \n", str);

    /* str is initialized by .. so that the first character starts after leaving a blank line. */
    for(int i=0; i<2; i++)
        str[i]='.';

    acceptInput();                      
    str=correctInput();
    system("clear");                 
    makeFile(fp);                       
    displayFile(fp, "interface.txt");   
    fp=fopen("interface.txt", "w");
    if(fp==NULL)
    {
        printf("\033[1;31m UNABLE TO PERFORM TASK. \033[0m \n");
        exit(1);
    }
    fputs(str, fp);
    fclose(fp);
    saveFile("interface.txt");         
    str=NULL;
    free(str);
}

/* accepts text input from the user in the desired format/ */
void acceptInput()
{
    int buf_size=100;
    char buf[100]="", inp[100]="";
    int i=0;

    /* loop is executd till user types NO on a fresh line. */
    while(strncmp(buf,"NO",2)!=0)
    {
        fgets(buf, buf_size, stdin);
        while(buf[i]!='\0')
        {
            inp[i]=buf[i];
            i++;
        }
        inp[i]='\0';

        /*size is increased to accomodate any length of user input. */
        if((strlen(str)+strlen(inp))>=size)
        {
            size+=buf_size;
            str=realloc(str,size);
        }

        if (strncmp(buf,"NO",2)!=0)
            strcat(str,inp);
        i=0;

        /* Since input taken is stored in a buffer of fixed size(here it is 100 characters), the enter key cannot be used to change para. */
        printf("\033[1;33m Enter text to be written. Only first 99 characters are read. Type .. to change para. Type NO on a fresh line to stop. \033[0m \n");
    }
}

/* replaces all occurrences of '\n' and .. by space and new line respectively. */
char* correctInput()
{
    char ch;
    char *new_str=NULL;
    new_str=malloc(strlen(str));
    new_str[0]='\0';
    int ind=0;
    for(int i=0;i<strlen(str);i++)
    {
        ch=str[i];

        /*ch now stores space if it had '\n'. */
        if(ch=='\n')
            ch=' ';

        /*ch now stores new line if it had ".." .
        here first dot is replaced by newline. */
        if(ch=='.' && str[i+1]=='.')
            ch='\n';
        /*here second dot is replaced by space it the next character is not '\n'. */
        if(ch=='.' && str[i-1]=='.')
        {
            if(str[i+1]!='\n')
                ch=' ';
            else
                continue;  
        }

        /* corrected character is added to new_str. */
        new_str[ind]=ch;
        ind++;
    }
    new_str[ind]='\0';
    return new_str;
}

/* calls suitable functions to write text and make a border around it. */
void makeFile(FILE *fp)
{
    moveOffsetVertical(fp, 5);      
    makeHorizontalLine(fp);         
    makeVerticalLine(fp);           
    makeHorizontalLine(fp);         
    moveOffsetVertical(fp, 5);      
}

/* moves the file pointer vertically down by given(i) lines. */
void moveOffsetVertical(FILE *fp, int i)
{
    for(int j=0; j<i; j++)
        fputc('\n', fp);
}

/* makes a complete line of '*' border. */
void makeHorizontalLine(FILE *fp)
{
    beginLine(fp);                          
    moveOffsetHorizontal(fp, 101, '*');     
    endLine(fp);                            
}

/* moves the file pointer horizontally by putting a given character(ch) a fixed no.(i) of times. */
void moveOffsetHorizontal(FILE *fp,int i, char ch)
{
    for(int j=0; j<i; j++)
        fputc(ch,fp);
}

/* moves the file pointer horizontally by 28 spaces and puts a '*'. */
void beginLine(FILE *fp)
{
    moveOffsetHorizontal(fp, 28, ' ');      
    fputc('*', fp);
}

/* puts a '*' and sends the file pointer to the next line. */
void endLine(FILE *fp)
{
    fputc('*', fp);
    fputc('\n', fp);
}

/* writes 101 characters inside both the sides of border. */
void makeVerticalLine(FILE *fp)
{
    char ch;
    int i, ind=0, j;
    while(ind<strlen(str))
    {
        beginLine(fp);              
        for(i=0; i<101; i++)
        {
            ch=str[ind];
            ind++;

            /* character is added in file. */
            if(ch!='\n' && ch!='\0')
                fputc(ch, fp);
            else
            {
                /* if new line is encountered, blank spaces are added to complete the line. */
                for(j=i;j<101;j++)
                    fputc(' ', fp);
                break;
            }
        }
        endLine(fp);               
    }
    addLine(fp, 2);                 
}

/* adds blank lines after text is written. */
void addLine(FILE *fp, int line)
{
    for(int i=0; i<line; i++)
    {
        beginLine(fp);                          
        moveOffsetHorizontal(fp, 101, ' ');     
        endLine(fp);                            
    }
}

/* displays name file on screen. */
void displayFile(FILE *fp, char name[100])
{
    int val;
    char buf[200];
    sprintf(buf, "cat %s", name);
    fclose(fp);
    printf("\033[1;33m Do You want to see what has been written? Type 1 for yes and 2 for no. \033[0m \n");
    scanf("%d", &val);
    if (val==1)
        system(buf);
}

/* saves orig as .txt file of user preferred name. */
void saveFile(char orig[100])
{
    char *name=NULL;
    name=malloc(100*sizeof(char));
    name[0]='\0';
    name=getName();
    rename(orig, name);
    printf("\033[1;32m FILE HAS BEEN SAVED. \033[0m \n");
}

/* accepts name of file(extension is .txt) . */
char* getName()
{
    char *name=NULL;
    name=malloc(100*sizeof(char));
    name[0]='\0';
    int check_val=0;

    /* file name can have only letters or digits. No extension or special character is allowed. */
    printf("\033[1;33m ENTER NAME OF FILE. EXTENSION USED IS .txt \033[0m \n");
    scanf("%s", name);
    while(check_val==0)
    {
        check_val=checkName(name);          
        if(check_val==0)
        {
            /* Re-promts the user to enter name in acceptable format. */
            printf("\033[1;33m ENTER NAME OF FILE. \033[0m \n");
            scanf("%s", name);
        }
    }
    strcat(name, ".txt"); /* .txt extension is added. */
    return name;
}

/* checks name does not have any special character or extension. */
int checkName(char name[100])
{
    char ch;
    for(int i=0; i<strlen(name); i++)
    {
        ch=name[i];

        /* checks validity of name provided. */
        if(isalnum(ch)==0 && isspace(ch)==0)
        {
            printf("\033[1;31m INVALID NAME. \033[0m \n");
            printf("\033[1;31m NAME CAN CONTAIN ONLY ALPHABETS OR DIGITS. \033[0m \n");
            return 0;
        }

    }
    return 1;
}

/* rewrites the contents of an existing file by calling suitable functions. */
void editByRewrite(FILE *fp)
{
    int val;
    char*name=NULL;
    name=malloc(100*sizeof(char));
    name[0]='\0';
    name=getName();                 
    fp=fopen(name, "r");
    if(fp==NULL)
    {
        printf("\033[1;31m FILE CANNOT BE OPENED IN READ MODE. MAYBE THE FILE DOESN'T EXIST. \033[0m \n");
        exit(1);
    }
    fclose(fp);
    str=malloc(size);
    str[0]='\0';
    for(int i=0; i<2; i++)
        str[i]='.';
    acceptInput();                  
    str=correctInput();             
    saveChanges(fp, name);          
    name=NULL;
    free(name);
}

/* saves the user input with a name of his choice. */
void saveChanges(FILE *fp, char name[100])
{
    int val;
    system("clear");
    printf("\033[1;33m DO YOU WANT TO SAVE CHANGES? TYPE 1 FOR YES AND 2 FOR NO. \033[0m \n");
    scanf("%d", &val);
    if (val==1)
    {
        fp=fopen(name, "w");
        FILE *hp;
        hp=fopen("interface.txt", "w");
        if(fp==NULL)
        {
            printf("\033[1;31m UNABLE TO PERFORM TASK. \033[0m \n");
            exit(1);
        }
        makeFile(hp);
        displayFile(hp, "interface.txt");
        fputs(str, fp);
        fclose(fp);
        printf("\033[1;32m CHANGES HAVE BEEN SAVED. \033[0m \n");
    }
    else
        printf("\033[1;31m CHANGES HAVE BEEN DISCARDED. FILE IS UNCHANGED. \033[0m \n");
    str=NULL;
    free(str);
    name=NULL;
    free(name);
}

/* edit an existing file by adding text at the end of file by calling suitable functions. */
void editByAdd(FILE *fp)
{
    int val;
    char*name=NULL;
    name=malloc(100*sizeof(char));
    name[0]='\0';
    name=getName();                     
    readFromFile(fp, name);             
    acceptInput();                      
    str=correctInput();                 
    saveChanges(fp, name);              
    name=NULL;
    free(name);
}

/* reads text from a given file(new line is replaced by ..)*/
void readFromFile(FILE *fp, char name[100])
{
    char ch;
    fp=fopen(name, "r");
    if(fp==NULL)
    {
        printf("\033[1;31m FILE CANNOT BE OPENED IN READ MODE. MAYBE THE FILE DOESN'T EXIST. \033[0m \n");
        exit(1);
    }
    str=malloc(size);
    str[0]='\0';
    ch=fgetc(fp);
    for(int i=0; i<2; i++)
        str[i]='.';
    for(int i=2; ch!=EOF && ch!='\0'; i++)
    {
        str[i]=ch;
        
        /* replaces new line with .. */
        if(ch=='\n')
        {
            if(str[i-1]=='.')
                str[i]='.';
            else
            {
                str[i]='.';
                i++;
                str[i]='.';
            }    
        }

        /* size is increased to accomodate any length of user input. */
        if(size-strlen(str)==1)
        {
            size+=100;
            str=realloc(str,size);
        }

        ch=fgetc(fp);
    }
    fclose(fp);
}

/* creates a duplicate of an existing files and saves it with a new name. */
void saveAs(FILE *fp)
{
    int val;
    char buf1[200], buf2[200];
    char *name=NULL;
    name=malloc(100*sizeof(char));
    name[0]='\0';
    name=getName();                         
    fp=fopen(name, "r");
    if(fp==NULL)
    {
        printf("\033[1;31m FILE CANNOT BE OPENED IN READ MODE. MAYBE THE FILE DOESN'T EXIST. \033[0m \n");
        exit(1);
    }
    readFromFile(fp, name);
    str=correctInput();
    FILE *hp;
    hp = fopen("interface.txt", "w");
    if(hp==NULL)
    {
        printf("\033[1;31m UNABLE TO PERFORM TASK. \033[0m \n");
        exit(1);
    }
    system("clear");
    makeFile(hp);
    displayFile(hp, "interface.txt");
    fclose(fp);
    sprintf(buf2, "cp %s %s", name, "duplicate.txt");
    system(buf2);
    saveFile("duplicate.txt");                      
}

void findWordOrPattern(FILE *fp)
{
    /* only a word/pattern of length upto 25 characters can be searched. */
    char word_to_search[25];

    int occurence;

    printf("\033[1;33m WORD/PATTERN TO SEARCH FOR. \033[0m \n");
    scanf("%s", word_to_search);
    char*name=NULL;
    name=malloc(100*sizeof(char));
    name[0]='\0';
    name=getName();                                 
    readFromFile(fp, name);                         
    str=correctInput();                             
    occurence = makeSearchResult(fp,name, word_to_search);      
    displaySearchResult(fp, "search.txt", occurence);          
}

/* stores search results in search.txt */
int makeSearchResult(FILE *fp, char name[100], char word_to_search[25] )
{
    int i, j, word, flag=0, count=0;

    /* ***file searched should not contain more than 1000 words.***
      ***max length of a word is taken to be 30 characters.*** */
    char new_str[1000][30];
    printf("%s \n", new_str[0]);
    fp=fopen("search.txt", "w");
    if(fp==NULL)
    {
        printf("\033[1;31m UNABLE TO PERFORM TASK. \033[0m \n");
        exit(1);
    }
    j=0; word=0;
    for(i=0;i<=(strlen(str));i++)
    {
        if(str[i]==' '||str[i]=='\0')
        {
            new_str[word][j]='\0';
            if(strstr(new_str[word],word_to_search))
            {
                fputs("\033[1;32m ", fp);
                count++;
                
                /* flag helps in adding color if word formed matches searched word. */
                flag=1;
            }
            fputs(new_str[word], fp);
            fputc(' ', fp);
            if(flag==1)
            {
                flag=0;
                fputs(" \033[0m", fp);
            }
            word++;
            j=0;
        }
        else
        {
            new_str[word][j]=str[i];
            j++;
        }
    }
    str=NULL;
    free(str);
    fclose(fp);
    return count;
}

/* displays and saves search results as per the user's wish. */
void displaySearchResult(FILE *fp, char name[100], int occ)
{
    int val;
    if(occ > 0)
    {
        printf("\033[1;33m %d occurrences found. \033[0m \n", occ);
        printf("\033[1;33m Search results are stored in search.txt \033[0m \n");
        printf("\033[1;33m To see the results, use \033[1;32m cat search.txt \033[0m \n");
    }
    else
    {
        printf("\033[1;31m No occurrence found. \033[0m \n");
        val=remove("search.txt");
        if(val==1)
            exit(1);
    }
    printf("\n\033[1;33m TASK DONE. \033[0m \n"); 
}

/* compares the contents of two files. */
void compareFiles(FILE *fp)
{
    char *data_of_file1=NULL, *data_of_file2=NULL;
    data_of_file1=malloc(size);
    data_of_file1[0]='\0';
    data_of_file1=getData(fp);                      
    data_of_file2=malloc(size);
    data_of_file2[0]='\0';
    data_of_file2=getData(fp);                      
    system("clear");
    if(strcmp(data_of_file1, data_of_file2)==0)
        printf("\033[1;32m THE TWO FILES ARE EXACTLY SAME. \033[0m \n");
    else
        printf("\033[1;31m THE TWO FILES ARE NOT EXACTLY SAME. \033[0m \n");
    data_of_file1=NULL;
    free(data_of_file1);
    data_of_file2=NULL;
    free(data_of_file2);
}

/* gets the data stored in a given file. */
char* getData(FILE *fp)
{
    char *name=NULL, *data_of_file=NULL;
    data_of_file=malloc(size);
    data_of_file[0]='\0';
    name=malloc(100*sizeof(char));
    name[0]='\0';
    name=getName();
    readFromFile(fp, name); 
    str=correctInput();     
    data_of_file=malloc(size);
    strcpy(data_of_file, str);
    str=NULL;
    free(str);
    name=NULL;
    free(name);
    return data_of_file;
}

/* deletes an existing file. */
void deleteFile(FILE *fp)
{
    int val;
    int conf;
    char *name=NULL;
    name=malloc(100*sizeof(char));
    name[0]='\0';
    name=getName();                                
    fp=fopen(name, "r");
    if(fp==NULL)
    {
        printf("\033[1;31m FILE CANNOT BE OPENED IN READ MODE. MAYBE THE FILE DOESN'T EXIST. \033[0m \n");
        exit(1);
    }
    fclose(fp);
    printf("\033[1;33m ARE YOU SURE? 1 FOR YES AND 2 FOR NO. \033[0m \n");
    scanf("%d", &conf);
    system("clear");
    if(conf==1)
    {
        val=remove(name);
        if(val==0)
            printf("\033[1;32m FILE HAS BEEN DELETED. \033[0m \n");
        else
        {
            printf("\033[1;31m FILE CANNOT BE DELETED. \033[0m \n");
            exit(1);
        }
    }
    else if(conf==2)
        printf("\033[1;33m TASK TERMINATED. \033[0m \n");
    else
    {
        printf("\033[1;31m INVALID CHOICE. \033[0m \n");
        exit(1);
    }
}

/* ******THANK YOU. ****** */