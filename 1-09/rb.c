#include <stdio.h>

/* copy input to output and remove unnecessary blanks */

main()
{
    int c, lc;

    lc = EOF;
    while ((c = getchar()) != EOF)
    {
        if (c != lc || c != ' ')
            putchar(c);
        lc = c;
    }
}
