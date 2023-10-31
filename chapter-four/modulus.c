/*

Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 0
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100 /* char buffer size for ungetting */

int getop(char c[]);
void push(double v);
double pop(void);
int getch(void);
void ungetch(int c);

int sp = 0; /* stack pointer */
double val[MAXVAL]; /* FIFO stack */

int bufp = 0; /* buffer pointer */
char buf[BUFSIZE]; /* buffer for ungetch */

/* reverse Polish calculator */
int main()
{
    int type; 
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                
                /* modulo operator only accepts integer numbers */
                int res = (int)pop() % (int)op2;
                
                if (op2 != 0.0) {
                    push(res);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop()
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");;
        return 0.0;
    }
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';

    /* not a number */
    if (!isdigit(c) && c != '.') {
        return c;
    }

    i = 0;
    /* collect integer part */
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    /* collect fraction part */
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
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