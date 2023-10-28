#include <stdio.h>

// while (end of character isn't reached)
    // if input is whitespace 
        // increment
    // if input is tab 
        // increment
    // if input is newline
        // increment

int main()
{
    int blanks, tabs, lines;
    int c; 

    blanks = 0;
    tabs = 0;
    lines = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++lines;
    }

    printf("Blanks: %d\nTabs: %d\nLines: %d\n", blanks, tabs, lines);
}