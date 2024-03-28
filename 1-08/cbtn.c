#include <stdio.h>

/* count blanks, tabs and lines in input */
main()
{
    int c, nb, nt, nl;

    nb = nt = nl = 0;
    while ((c =getchar()) != EOF)
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    printf("number of blanks: %d\n", nb);
    printf("number of tabs: %d\n", nt);
    printf("number of lines: %d\n", nl);

}
