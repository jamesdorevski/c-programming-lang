/*

Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.

*/

#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[]);

int i = 0;

int main()
{
    int x = -12345;
    char s[10];

    itoa(x, s);

    printf("%s\n", s);

    return 0;
}

// itoa: convert n to characters in s
void itoa(int n, char s[])
{
    if (n < 0) {
        s[i++] = '-';
        n = abs(n);
    }

    if (n / 10) {
        itoa(n / 10, s);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}