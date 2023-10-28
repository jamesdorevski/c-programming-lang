/*

Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.

get ranges from standard headers for the data types
print the range of values they can hold

then compute them yourself? 

bitwise shift them 

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

void ranges(const char* name, size_t size);
void print_signed_range(int bits);
void print_unsigned_range(int bits);

int main()
{
    ranges("char", sizeof(char));
    ranges("short", sizeof(short));
    ranges("int", sizeof(int));
    ranges("long", sizeof(long));

    return 0;
}

void ranges(const char* name, size_t size)
{
    int bits = size * 8;

    printf("signed %s range: ", name);
    print_signed_range(bits);

    printf("unsigned %s range: ", name);
    print_unsigned_range(bits);
}

void print_signed_range(int bits)
{
    int min = pow(2, bits-1) - 1;
    int max = pow(2, bits-1) * -1;

    printf(" [%d, %d]\n", min, max);
}

void print_unsigned_range(int bits)
{
    int min = 0;
    int max = pow(2, bits) - 1;

    printf(" [%u, %u]\n", min, max);
}