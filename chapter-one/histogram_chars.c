#include <stdio.h>

/*
DS: 
    - 256 length array to hold all ASCII chars
    - set all vals to zero 
    - while (end of file isn't reached)
        - increment element by 1 at the char location in the array
*/

#define MAX 256

int main()
{
    int c_count[MAX];
    int c, i;
    c = i = 0;

    for (i = 0; i < MAX; i++)
    {
        c_count[i] = 0; 
    }

    printf("Enter phrase (Ctrl+D to end input):\n");

    while ((c = getchar()) != EOF)
    {
        c_count[c]++;
    }

    printf("\n");

    // Print horizontally
    int j, k;
    for (j = 0; j < MAX; j++)
    {
        if (c_count[j] == 0)
        {
            continue;
        }

        printf("%c: ", j);
        for (k = 0; k < c_count[j]; k++)
        {
            printf("*");
        }

        printf("\n");
    }
}