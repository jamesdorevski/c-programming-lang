/*

Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.

*/

#include <stdio.h>
#include <string.h>

int strindex(const char s[], const char t[]);

int main() 
{
    char s[] = "yes yes, I am";
    char t[] = "yes";

    int loc = strindex(s, t);
    printf("%d\n", loc);

    return 0;
}

/* strindex: returns the position of the rightmost occurrence of t in s, or -1 if there is none. */
int strindex(const char s[], const char t[])
{
    int i, j, k;

    int s_len = strlen(s);
    int t_len = strlen(t);

    int t_first = t[0];

    // len-1 to skip the null char 
    for (i = s_len-1; i >= 0; i--) {
        for (j = i, k = t_len-1; k != 0 && s[j] == t[k]; j--, k--) {
            ;
        }
        if (k == 0 && t[k] == t_first) {
            return i;
        }
    }

    return -1;
}
