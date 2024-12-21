#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */
#define TABSTOP 4       /* tabstop */

int getline(char line[], int maxline);
void detab(char l[], int len, char cl[], int ts);

int main()
{

    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */
    char correctline[MAXLINE];  /* correct line */

    while ( (len = getline(line, MAXLINE)) > 0) {
        detab(line, len, correctline, TABSTOP);
        printf("%s", correctline);
    }
    return 0;
}


/*  detab: replace tabs in line by the proper amount of blanks until next tab
    stop */
void detab(char l[], int len, char cl[], int ts)
{
    int i, j, x;
    char c;

    for (j=i=0; i<len; ++i)
    {
        if ((c=l[i]) == '\t')
        {
            for (x=(j%ts);x<ts;++x)
            {
                cl[j] = ' ';
                ++j;
            }
        }
        else
        {
            cl[j] = c;
            ++j;
        }

    }
    cl[j] = '\0';
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
