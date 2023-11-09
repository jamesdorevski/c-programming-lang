/*

Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.

*/

#include <stdio.h>
#include <string.h>

#define MAX 64

char *mystrncpy(char *s, char *t, int n);

int main()
{
    char s[MAX] = "The quick brown fox jumped over the line.";
    char t[MAX] = "line.";

    char *res = strncpy(s, t, 8);
    printf("Original: %s\n", res);

    char s2[MAX] = "The quick brown fox jumped over the line.";

    res = mystrncpy(s2, t, 8);
    printf("Rewrite: %s\n", res);
    
    return 0;
}

/* Copy chars from to to s up to n. Pads '\0' if t is less than n. */
char *mystrncpy(char *s, char *t, int n)
{
    int i = 0;
    char *start = s;

    while (*s++ = *t++) {
        i++;
        if (i >= n) {
            return start;
        }
    }

    while (i < n) {
        *s++ = '\0';
        i++;
    }

    return start;
}