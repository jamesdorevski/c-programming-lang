#include <stdio.h>

// while (input is not end of file)
    // if input is blank tab or newline
        // print new line
    // else 
        // putchar

int main()
{   
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
            putchar('\n');
        else 
            putchar(c);
    }
}