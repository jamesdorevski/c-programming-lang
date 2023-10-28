/*

Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||

*/

#include <stdio.h>


int getline_ex(char s[], int lim);

int main()
{

}

int getline_ex(char s[], int lim)
{
    int c, i;

    // for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; i++) {
    //     s[i] = c;
    // }

    for (i = 0; i < lim-1; i++) {
        c = getchar();
        
        if (c == EOF) {
            break;
        }
        
        if (c == '\n') {
            break;
        }

        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
    }

    s[++i] = '\0';
    return i; 
}