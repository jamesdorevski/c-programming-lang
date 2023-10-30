/*

Exercise 4-2. Extend atof to handle scientific notation of the form

123.45e-6

where a floating-point number may be followed by e or E and an optionally signed exponent.

*/

#include <ctype.h>
#include <stdio.h>

double atof(const char s[]);
double power(double base, double exp);

int main()
{
    // char s[] = "123.45e6";
    // double res = atof(s);

    double res = power(12.0, 8.0);

    printf("%f\n", res);

    return 0;
}

// /* atof: convert string s to double */
// double atof(const char s[])
// {
//     double val, power, exp;
//     int i, sign;

//     // increment over spaces, if any
//     for (i = 0; isspace(s[i]); i++) {
//         ;
//     }

//     sign = (s[i] == '-') ? -1 : 1;
    
//     if (s[i] == '+' || s[i] == '-') {
//         i++;
//     }

//     for (val = 0.0; isdigit(s[i]); i++) {
//         val = 10.0 * val + (s[i] - '0');
//     }

//     if (s[i] == '.') {
//         i++;
//     }

//     for (power = 1.0; isdigit(s[i]); i++) {
//         val = 10.0 * val + (s[i] - '0');
//         power *= 10;
//     }

//     int res = sign * val / power;

//     if (s[i] != 'e' && s[i] != 'E') {
//         return res;
//     }

//     // read sign of exponent - if negative, divide. If positive, multiply
//     i++;

//     int leftshift = (s[i] == '-') ? 0 : 1;
  
//     if (s[i] == '+' || s[i] == '-') {
//         i++;
//     }

//     for (exp = 0.0; isdigit(s[i]); i++) {
//         exp = 10.0 * exp + (s[i] - '0');
//     }

//     if (leftshift) {
//         return 
//     }

// }

double power(double base, double exp)
{
    double res = 1.0;

    for (int i = 0; i < exp; i++) {
        res *= base; 
    }

    return res;
}

