#include <stdio.h>

#define LOWER   0   /* lower limit of table */
#define UPPER   300 /* upper limit */
#define STEP    20  /* step size */

float celsius(int fahr);

/* print Fahrenheit-Celsius table using a function */

main ()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d%8.2f\n", fahr, celsius(fahr));
    return 0;
}

float celsius (int fahr)
{
    return (5.0/9.0) * (fahr-32);
}
