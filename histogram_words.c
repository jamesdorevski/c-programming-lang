#include <stdio.h>

/*
DS: 
    - array of ints
        - index corresponds to word
        - value corresponds to length 
    - length counter
    - index 

    create INT_MAX array 
    while (end of file is not reached)
        if word has ended 
            store length in current index
            reset state vars
        else
            length++

*/

#define MAX 256

int main()
{
    int wlength[MAX];
    int c, len, i; 

    c = len = i = 0;

    printf("Enter phrase (Ctrl+D to end input):\n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            wlength[i] = len;
            len = 0;
            i++;

            if (i == MAX)
            {
                printf("Reached max word count.\n");
                break;
            }
        }
        else 
        {
            len++;
        }
    }

    // Handle last word if there's no space/newline/tab before EOF
    if (len != 0)
    {
        wlength[i] = len;
        i++;
    }

    printf("\n");

    // Print horizontally
    int j;
    for (j = 0; j < i; j++)
    {
        for (int k = 1; k <= wlength[j]; k++)
        {
            printf("*");
        }

        printf("\n");
    }
}