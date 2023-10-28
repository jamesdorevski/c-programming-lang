/*

Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.

get ranges from standard headers for the data types
print the range of values they can hold

then compute them yourself? 

bitwise shift them 

not going to worry about representing floating points now as they'll be 
covered in the computer architecture book 

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

void ranges(const char* name, size_t size);
void print_signed_range(int bits);
void print_unsigned_range(int bits);

int main()
{
    ranges("char", sizeof(char));
    ranges("short", sizeof(short));
    ranges("int", sizeof(int));
    ranges("long", sizeof(long));

    printf("float range: [%f, %f]\n", FLT_MIN, FLT_MAX);
    printf("double range: [%f, %f]\n", DBL_MIN, DBL_MAX);

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
    long max = (1L << (bits - 1)) -1;
    long min  = ~max;

    printf(" [%ld, %ld]\n", min, max);
}

void print_unsigned_range(int bits)
{
    unsigned long min = 0;
    unsigned long max;

    if (bits < sizeof(unsigned long) * 8) {
        max = (1LU << bits) - 1;
    } else {
        max = ~min;
    }

    printf(" [%lu, %lu]\n", min, max);
}
