#include <stdio.h>

#define LENGTH 10   /* maximum length of a word in input i.e. for 10,
                       words of length 1-10 */
#define IN      1   /* inside a word */
#define OUT     0   /* outside a word */

/* count the length of words and print a histogram of their length */
main()
{
    int c, i, j, sc, lword, state;
    int ln;
    int nword[LENGTH+1];

    state = IN;
    lword = ln = 0;
    for (i = 0; i < LENGTH+1; ++i)
        nword[i] = 0;

    while ((c = getchar()) != EOF)
    {
        /* Is c a split character? */
        sc = c == ' ' || c == '\n' || c == '\t';

        if (sc && state == IN)
        {
            if (lword <= LENGTH)
                ++nword[lword];
            lword = 0;
            state = OUT;
        }
        else if (!sc)
        {
            ++lword;
            state = IN;
        }
    }

    /* print a histogram with horizontal bars*/
    printf("lenght  amount\n");
    for (i = 1; i < LENGTH+1; ++i)
    {
        printf("%6d\t", i);
        for (j = 0; j < nword[i]; ++j)
            printf("#");
        printf("\n");
    }

    /* print a histogram with vertical bars*/
    printf("\n");

    /* find largest number in array*/
    for (i = 0; i < LENGTH+1; ++i)
    {
        if (nword[i] > ln)
            ln = nword[i];
    }
    
    for (i = ln; i > 0; --i)
    {
        for (j = 0; j < LENGTH+1; ++j)
        {
            if (nword[j] >= i)
                printf("##");
            else
                printf("  ");
        }
        printf("\n");
    }
    for (i = 0; i < LENGTH+1; ++i)
        printf("%2d", i);
    printf("\n");
}
