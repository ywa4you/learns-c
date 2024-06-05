#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
int fixline(char line[], int length);

main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        fixline(line, len);
        printf("%s", line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/*  fixline: remove all trailing blanks and tabs and delete enirely blank lines,
    return new length */
int fixline(char s[], int end)
{
    --end;                                      /* index of last char */
    --end;                                      /* back from \n */
    while (s[end] == ' ' || s[end] == '\t')     /* blank or tab */
        --end;
    ++end;
    s[end] = '\n';
    s[end+1] = '\0';

    if (end==0) {                         /* blank line */
        s[0] = '\0';
        end = 0;
    }
    return end+1;
}
