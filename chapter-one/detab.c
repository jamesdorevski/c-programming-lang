#include <stdio.h>

#define TAB_STOPS 8
#define MAX_LINE 1000

int getline_detab(char line[], int maxline);

/* 
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?

    DS:
        - char array 
    
    while (end of file is not reached)
        if tab character is hit
            add ' ' * TAB_STOPS
            index + 4
        else
            add current char into character array 
    
    if last char in input is newline 
        add to char array
    
    add the null character to the end

*/

int main() 
{
    char detab[MAX_LINE];

    printf("Enter line to detab. (press enter to confirm):\n");
    int len = getline_detab(detab, MAX_LINE);

    printf("De-tabbed line includes %d characters.\n", len);
    printf("%s", detab);

    return 0;
}

/* getline: read a line into s, return length */
int getline_detab(char line[], int maxline)
{
    int c, i, j;

    i = 0;
    
    while (i < maxline-1 && (c = getchar()) != EOF && c!='\n') {
        if (c == '\t') {
            int spaces = TAB_STOPS - (i % TAB_STOPS);

            for (j = 0; j < spaces && i < maxline-1; j++) {
                line[i++] = ' ';
            }
        }
        else {
            line[i++] = c;
        }
    }

    if (c == '\n') {
        line[i] = c; 
    }

    line[++i] = '\0';
    return i;
}