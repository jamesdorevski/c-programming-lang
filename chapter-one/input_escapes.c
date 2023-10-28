#include <stdio.h>

// curr and prev char

// while (end of character isn't reached)
    // if curr is equal to a blank
        // if prev is equal to a blank 
            // continue


main()
{
    int curr; 

    while ((curr = getchar()) != EOF)
    {
        switch (curr)
        {
            case '\n':
                printf("\\n");
                break;
            case '\t':
                printf("\\t");
                break;
            case '\\':
                printf("\\");
                break;
            default:
                putchar(curr);
        }
    }
}
