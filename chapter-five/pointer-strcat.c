/* 

Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s. 

*/

#include <stdio.h>

#define MAX 64

void astrcat(char s[], char t[]);
void pstrcat(char *s, char *t);

int main()
{
    char s[MAX] = "Hello,";
    char t[MAX] = " World!";

    pstrcat(s, t);

    printf("%s\n", s);

    return 0;
}

void astrcat(char s[], char t[])
{
    int i = 0;
    int j = 0;

    // Get to the end of s
    while (s[i] != '\0') {
        i++;
    }

    // copy until we hit t's end
    while ((s[i++] = t[j++]) != '\0') {
        ;
    }
}   

void pstrcat(char *s, char *t)
{
    while (*(++s) != '\0')
        ;
    while ((*s++ = *t++) != '\0')
        ;
}