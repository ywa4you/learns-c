#include <stdio.h>

/* copy input to output and replace each tab by \t, each backspace by \b, and each backslash by \\ */
main()
{
    int c, p;
    
    while ((c = getchar()) != EOF)
    {
        p = 0;

        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
            p = 1;
        }
        if (c == '\b')
        {
            putchar('\\');
            putchar('b');
            p = 1;
        }
        if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
            p = 1;
        }
        if (p == 0)
        {
            putchar(c);
        }
    }
}
