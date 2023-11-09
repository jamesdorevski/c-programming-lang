/*

Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise. 

*/

#include <stdio.h>
#include <string.h>

#define MAX 64

int strend(char *s, char *t);

int main()
{
    int res;
    char s[MAX] = "The quick brown fox jumped over the line.";
    char t[MAX] = " the line.";

    res = strend(s, t);

    printf("%d\n", res);

    return 0;
}

int strend(char *s, char *t)
{
    int tlen;
    
    tlen = strlen(t);

    while (*s++ != '\0') 
        ;

    // Move pointer back len of t
    // If t exists at the end of s, the next chars we see should match
    s -= tlen+1;

    while (*s++ == *t++) {
        if (*s == '\0' && *t == '\0') {
            return 1;
        }
    }

    return 0;
}
