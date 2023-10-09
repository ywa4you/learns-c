include <stdio.h>

#define IN  0   /* inside a word */
#define OUT 1   /* outside a word */

/* count lines, words, and characters in input */
main()
{
    int c, sc, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        /* Is c a split character? */
        sc = c == ' ' || c == '\n' || c == '\t';

        if (sc && state == IN)
        {
            putchar('\n');
            state = OUT;
        }
        else if (!sc)
        {
            putchar(c);
            state = IN;
        }
    }
}
