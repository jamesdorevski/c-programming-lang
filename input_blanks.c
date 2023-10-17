#include <stdio.h>

// curr and prev char

// while (end of character isn't reached)
    // if curr is equal to a blank
        // if prev is equal to a blank 
            // continue


main()
{
    int curr, prev; 


    while ((curr = getchar()) != EOF)
    {
        if (curr == ' ')
        {
            if (prev != ' ')
            {
                putchar(curr);
            }
            prev = curr;
            continue;
        }

        putchar(curr);
        prev = curr;
    }
}