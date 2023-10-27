#include <stdio.h>

/*
    Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
    number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
    When either a tab or a single blank would suffice to reach a tab stop, which should be given
    preference?

    - replace tabs in input with the proper number of 
    blanks to space in the next tab stop. 
    - when a tab or single blank would suffice to reach a tab stop,
    which should be given preference? 


    while (line is not EOF)
*/

#define TAB_STOPS 4
#define SPACES_IN_TAB 3
#define MAX_LINE 1000
#define TABS 0
#define SPACES 1

int getline_entab(char line[], int maxline);
int readspaces();
void calcspacing(int loc, int res[], int c);
int addchar(char line[], int i, char c, int occurrences);

int main() 
{
    char entab[MAX_LINE];

    printf("Enter line to entab. (press enter to confirm):\n");

    int len = getline_entab(entab, MAX_LINE);

    printf("En-tabbed line includes %d characters.\n", len);
    printf("%s", entab);

    return 0;
}

int getline_entab(char line[], int maxline)
{
    int c, i; 
    int spacecnt;
    int res[2];

    i = 0;

    while (i < maxline-1 && (c = getchar()) != EOF && c!='\n') {
        if (c == ' ') {
            spacecnt = readspaces();
            calcspacing(i, res, spacecnt);

            if (res[TABS] > 0) {
                i = addchar(line, i, '\t', res[TABS]);
            }
            if (res[SPACES] > 0) {
                i = addchar(line, i, ' ', res[SPACES]);
            }
        }
        else {
            line[i++] = c;
        }
    }

    if (c == '\n') {
        line[i] = c;
    }

    line[++i] = '\0';
    return i;
}

/* readspaces: reads spaces from a buffers and returns the count */
int readspaces() 
{
    int c;
    // Count initial space that triggered this function
    int cnt = 1;

    while ((c = getchar()) == ' ') {
        cnt++;
    }

    ungetc(c, stdin);

    printf("Spaces counted: %d", cnt);

    return cnt;
}

/* calcspacing: places minimum amount of tabs and spaces to add in res[] given blank string */
void calcspacing(int loc, int res[], int spacecnt)
{
    int tabs = 0;
    int spaces = 0;
    int targetLoc = loc + spacecnt;

    while (loc < targetLoc) {
        if ((loc+1) % TAB_STOPS == 0 
            && (targetLoc - loc) >= TAB_STOPS) {
            tabs++;
            loc++;
        } else {
            spaces++;
            loc++;
        }
    }

    // Reset loc for the next passthrough
    loc -= spacecnt;

    // check if spaces can be optimised with a tab
    while (spaces >= TAB_STOPS && (loc % TAB_STOPS == 0)) {
        tabs++;
        spaces -= TAB_STOPS;
        loc += TAB_STOPS;
    }

    res[TABS] = tabs;
    res[SPACES] = spaces;

    printf("tabs to add: %d, spaces to add: %d\n", res[TABS], res[SPACES]);
}

int addchar(char line[], int loc, char c, int occurrences)
{
    for (int i = 0; i < occurrences ; i++) {
        line[loc++] = c;
    }

    return loc;
}