#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_ex(char line[], int maxline);
void reverse(char s[], int len);
void copy(char to[], char from[]);

/*
    two pointers: one at beginning and one at end
    
    while (pointers do not equal each other)
        copy value from ptr 1 to ptr 2
        ptr1++
        prt2--
*/

int main()
{
    int len;
    char line[MAXLINE];

    printf("Enter line to reverse. (type \"done\" to cancel):\n");

    while ((len = getline_ex(line, MAXLINE)) > 0)
    {
        if (strcmp(line, "done\n") == 0) {
            break;
        }

        reverse(line, len);
        printf("Reversed line: %s\n", line);

        printf("Enter line to reverse. (type \"done\" to cancel):\n");
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

/* reverse: reverse the order of string s */
void reverse(char s[], int len)
{
    char og[MAXLINE];
    copy(og, s);

    int ptr1, ptr2;
    ptr1 = 0;
    // minus 2 to ignore the null and newline operators
    ptr2 = len-2;

    while (ptr2 >= 0) {
        s[ptr2] = og[ptr1];
        ptr1++;
        ptr2--;
    }
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