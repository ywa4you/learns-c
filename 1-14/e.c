#include <stdio.h>

#define LENGTH  128 /* size of the character set; this program assumes
                     * all characters are noted as an integer from 0
                     * to LENGTH-1 */
#define FROM    32  /* number of the character where the histogram
                     * starts (inclusive) */
#define TO      126 /* number of the character where the histogram
                     * ends (inclusive) */

/* print a histogram of the frequencies of different characters in
 * it's input */
main()
{
    int c, i, j;
    int cs[LENGTH];

    for (i = 0; i < LENGTH; ++i)
        cs[i] = 0;

    while ((c = getchar()) != EOF)
        ++cs[c];

    /* print a histogram with horizontal bars*/
    printf("char amount\n");
    for (i = FROM; i < TO+1; ++i)
    {
        putchar(i);
        printf("    ");
        for (j = 0; j < cs[i]; ++j)
            printf("#");
        printf("\n");
    }
}
