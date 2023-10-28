/*

Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.

convert hexadecimal to decimal - multiply each hexadecimal digit by the appropriate 
power of 16

e.g. 0x7AF: 
- 7 * pow(16, 2) + 10 * 16 + 15 

algo:

    val = 0;
    len = strlen(s) - 3 // ignore 0x 

    while (string is not null)
        if (c >= '0' && c <= '9')
            d = getdigit(c)
        else if (c >= 'A' && c <= 'F')
            d = c - 55 // minus 55 gets the decimal equiv. for these hex digits (ASCII only)

        val = 

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int htoi(const char s[]);

int main() 
{
    int expected = 0x7af;
    char hex[] = "0x7af";
    
    int actual = htoi(hex);

    printf("Expected: %d\n", expected);
    printf("Actual: %d\n", actual);

    return 0;
}

/* htoi: convert hexadecimal string s into it's base 10 decimal equivalent. */
int htoi(const char s[])
{
    int exp = strlen(s) - 3;
    int val = 0;
    int curr;

    // skip the hexadecimal prefix 
    for (int i = 2; s[i] != '\0'; i++)
    {
        if (isdigit(s[i])) {
            curr = s[i] - '0';
        } else if (isupper(s[i])) {
            // get the decimal equiv. for hex digit (ASCII only)
            curr = s[i] - 55;
        } else if (islower(s[i])) {
            // same idea as above, just for lowercase 
            curr = s[i] - 87;
        } else {
            printf("Invalid hexadecimal digit (%c). Not computing...\n", s[i]);
            return -1;
        }

        val = val + curr * pow(16, exp);
        exp--;
    }

    return val;
}