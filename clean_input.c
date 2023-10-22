#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_clean(char s[], int lim);

int main()
{
    int len;
    char line[MAXLINE];

    printf("Enter lines to clean (Type \"done\" to cancel):\n");

    while ((len = getline_clean(line, MAXLINE)) > 0) {
        if (strcmp(line, "done\n") == 0) {
            break;
        }

        printf("Cleaned line: %s", line);
    }
}

int getline_clean(char s[], int lim)
{
    int c, i;

    i = 0;

    while (i<lim-1 && (c=getchar()) != EOF && c!='\n') {
        if (c==' ' || c=='\t' || (i>0 && c=='\n'))
        {
            continue;
        }
        s[++i] = c;
    }

    if (c == '\n') {
        s[++i] = c;
    }

    s[++i] = '\0';
    return i;
}
