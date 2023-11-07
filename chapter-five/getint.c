/* 

Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input. 

Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does
getfloat return as its function value? 

*/

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 5

int getch(void);
void ungetch(int);
int getint(int *ip);
int getfloat(float *fp);

int bufp = 0;
char buf[BUFSIZE];

int main()
{
    // int n, array[SIZE];

    // for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
    //     ;
    // }

    // for (int i = 0; i < SIZE; i++) {
    //     printf("%d ", array[i]);
    // }

    int n;
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++) {
        ;
    }

    for (n = 0; n < SIZE; n++) {
        printf("%f ", array[n]);
    }


    return 0;
}

/* getch: gets next char from shared buffer. If empty, reads from getchar */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: places char onto buffer so it can potentially be read again. */
void ungetch(int c)
{
    if (bufp < BUFSIZE) {
        buf[bufp++] = c;
    } else {
        printf("error: char buffer full\n");
    }
}


/* getint: get next integer from input into *pn */
int getint(int *ip)
{
    int c, sign;

    while (isspace(c = getch())) {
        ;
    }

    // Return 0 if NaN
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();

        if (!isdigit(c)) {
            ungetch(c);
            return 0; 
        }
    }

    for (*ip = 0; isdigit(c); c = getch()) {
        *ip = 10 * *ip + (c - '0');
    }

    *ip *= sign;
    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int getfloat(float *fp)
{
    int c;
    int sign;
    int deciplace = 1;
    int decifnd = 0;

    while (isspace(c = getch())) {
        ;
    }

    // Return 0 if NaN
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();

        if (!isdigit(c)) {
            ungetch(c);
            return 0; 
        }
    }

    for (*fp = 0.0; isdigit(c) || c == '.'; c = getch()) {
        if (c == '.') {
            decifnd = 1;
            continue;
        }

        if (decifnd) {
            deciplace *= 10;
        }

        *fp = 10.0 * *fp + (c - '0');
    }

    *fp *= sign;
    *fp /= deciplace;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}