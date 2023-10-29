/*

Exercise 4-2. Extend atof to handle scientific notation of the form

123.45e-6

where a floating-point number may be followed by e or E and an optionally signed exponent.

*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(const char s[]);

int main()
{
    char s[] = "123.45";
    double res = atof(s);
    printf("%f\n", res);

    return 0;
}

/* atof: convert string s to double */
double atof(const char s[])
{
    double val, power;
    int i, sign;

    // increment over spaces, if any
    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] != 'e' && s[i] != 'E') {
        return sign * val / power;
    }

    // TODO: handle sign
    sign = (s[++i] == '-') ? -1 : 1;

    int exp = s[++i] - '0';
    return (sign * val / power) * pow(10, exp);
}

