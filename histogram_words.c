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

int main()
{
    int wlength[256];
    int c, clen, i; 

    c = clen = i = 0;

    printf("Enter phrase (Ctrl+D to end input):\n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            wlength[i] = clen;
            clen = 0;
            i++;
        }
        else 
        {
            clen++;
        }
    }

    printf("\n");

    int j;
    for (j = 0; j < i; j++)
    {
        printf("%d: ", j);
        for (int k = 1; k <= wlength[j]; k++)
        {
            printf("*");
        }

        printf("\n");
    }
}