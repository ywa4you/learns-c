#include <stdio.h>

/* verify that value of "getchar() != EOF" is either "1" or "0" use
use appropriate input*/
main()
{
    printf("%d\n", getchar() != EOF);
}
