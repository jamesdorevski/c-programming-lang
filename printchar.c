#include <stdio.h>

// get character until end of file is reached
// print char

int main() 
{
    int not_eof = getchar() != EOF;
    printf("Value of getchar() != EOF: %d\n", not_eof);

    printf("Integer value of EOF: %d\n", EOF);

    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}