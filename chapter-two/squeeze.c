/*

Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.

-- two nested for loops O(nm) complexity

result = ""

while (s1 has not ended)
    while (s2 has not ended)
        continue
    
    result = s1[i]

result[i] = '\0'
*/

#include <stdio.h>

void squeeze(char s1[], const char s2[]);

int main() 
{
    char s1[] = "Apples are delicious and nutritious";
    char s2[] = "nuts";
    
    printf("Original: %s\n", s1);
    printf("Comparison: %s\n", s2);

    squeeze(s1, s2);

    printf("Squeezed: %s\n", s1);

    return 0;
}

/* squeeze: deletes each character in s1 that matches any char in s2. */
void squeeze(char s1[], const char s2[])
{
    // k keep's track of the position of the replacement string
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        int found = 0;

        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            s1[k++] = s1[i];
        }
    }

    s1[k] = '\0';
}