/*

Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.

Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int i = 0;

int main()
{
    int x = -12345;
    char s[10];

    itoa(x, s);
    printf("%s\n", s);

    reverse(s);
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

/* reverse: reverse s in place recursively */
void reverse(char s[])
{
    static int i = 0;
    static int len;

    int j; 
    char c;

    if (i == 0) {
        len = strlen(s);
    } 

    j = len - (i + 1);

    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        reverse(s);
    } else {
        i = 0;
    }
}