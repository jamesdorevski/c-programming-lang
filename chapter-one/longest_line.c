#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_ex(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;

    printf("Enter lines for comparison. (type \"done\" to cancel):\n");

    while ((len = getline_ex(line, MAXLINE)) > 0)
    {
        if (len > max) {
            max = len;
            copy(longest, line);
        }

        if (strcmp(line, "done\n") == 0) {
            break;
        }
    }

    printf("\nThe longest line is:\n");

    if (max > 0) {
        printf("length: (%d) %s", max, longest);
    }
    
    return 0;
}

// getline: read a line into s, return length
int getline_ex(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
    }

    s[++i] = '\0';
    return i; 
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    for (int i = 0; (to[i] = from[i]) != '\0'; i++) {
        ;
    }
}