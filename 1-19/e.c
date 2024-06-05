#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void reverse(char line[], int len);

main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */


    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line, len);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/*  reverse characters in string */
void reverse(char s[], int j)
{
    int i;
    char t;

    --j;                /* index of last char */
    i = 0;
    while (i < j) {     /* not in the middle */
        t = s[i];       /* switch chars */
        s[i] = s[j];
        s[j] = t;
        ++i;            /* next pair */
        --j;
    }

}
