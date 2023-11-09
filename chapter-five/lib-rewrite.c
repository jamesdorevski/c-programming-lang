/*

Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.

*/

#include <stdio.h>
#include <string.h>

#define MAX 64
#define N 50

char *mystrncpy(char *s, char *t, int n);
char *mystrncat(char *dest, char *src, int n);

int main()
{
    char dest[MAX] = "Hello";
    char src[MAX] = ", World!";

    char *res = strncat(dest, src, N);
    printf("Original: %s\n", res);

    char dest2[MAX] = "Hello";

    res = mystrncat(dest2, src, N);
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

/* Concat at most n chars from src onto dest. */
char *mystrncat(char *dest, char *src, int n)
{
    int i;
    char *start = dest;

    while (*(++dest) != '\0')
        ;

    for (i = 0; i < n && (*dest++ = *src++) != '\0'; i++) 
        ;

    return start;
}