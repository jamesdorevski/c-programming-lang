/*

Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define VARIABLE '1'
#define SET_VARIABLE '2'
#define MAXVAL 100
#define BUFSIZE 100 /* char buffer size for ungetting */

int getop(char c[]);
void push(double v);
double pop(void);
int getch(void);
void ungetch(int c);
void peek(int n);
void duplicate(void);
void swap(void);
void clear(void);

void usevar(char c);
void setvar(double v, char c);

int sp = 0; /* stack pointer */
double val[MAXVAL]; /* FIFO stack */

int bufp = 0; /* buffer pointer */
char buf[BUFSIZE]; /* buffer for ungetch */

double variables[26]; /* hold values in variables */
double lastprinted = 0.0;




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
            case VARIABLE:
                usevar(s[0]);
                break;
            case SET_VARIABLE:
                setvar(pop(), s[1]);
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
                printf("\t%.8g\n", lastprinted = pop());
                break;
            case 'P':
                peek(2);
                break;
            case 'D':
                duplicate();
                break;
            case 'S':
                swap();
                break;
            case 'C':
                clear();
                break;
            case 'L':
                push(lastprinted);
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
    int i, c, next;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';

    /* if we're assigning a var */
    if (c == '=') {
        next = getch();
        if (!islower(next)) {
            return c;
        }
        ungetch(next);
 
        while (islower(s[++i] = c = getch())) {
            ;
        }
        s[i] = '\0';
        return SET_VARIABLE;
    }

    /* variable */
    if (islower(c)) {
        while (islower(s[++i] = c = getch())) {
            ;
        }
        s[i] = '\0';
        return VARIABLE;
    }

    /* not a number */
    if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
        return c;
    }

    /* handle sign */
    if (c == '+' || c == '-') {
        /* look ahead and determine if there's a num after sign */
        next = getch();
        if (!isdigit(next) && next != '.') {
            return c;
        }
        ungetch(next);
        c = next;
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

/* peek: print the first n items on the stack */
void peek(int n)
{
    if (sp < n) {
        printf("error: not enough elements to peek");
    }

    int bound = sp - n;

    for (int i = sp-1; i >= bound; i--) {
        printf("\t%.8g\n", val[i]);
    }
}

/* duplicate: duplicate the top element on the stack */
void duplicate(void)
{
    if (sp <= 0) {
        printf("error: stack empty");
        return;
    }

    if (sp < MAXVAL) {
        double top = val[sp-1];
        push(top);
    } else {
        printf("error: stack full");
    }
}

/* swap: swap the first two elements on the stack */
void swap(void)
{
    if (sp < 2) {
        printf("error: not enough elements to swap\n");
        return;
    }

    double first = pop();
    double second = pop();

    push(first);
    push(second);
}

/* clear: clears the stack */
void clear(void)
{
    sp = 0;
    printf("Stack cleared.\n");
}

/* setvar: store value in index c */
void setvar(double v, char c)
{
    if (c >= 'a' && c <= 'z') {
        variables[c - 'a'] = v;
    } else {
        printf("error: unknown variable\n");
    }
}

/* usevar: use the var stored in index c */
void usevar(char c)
{
    if (c >= 'a' && c <= 'z') {
        push(variables[c - 'a']);
    } else {
        printf("error: unknown variable\n");
    }
}