#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */
main()
{
    float fahr, celcius;
    int  lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 100;    /* upper limit */
    step = 5;      /* step size */

    printf("Celcius Fahrenheit\n");
    fahr = lower;
    while (celcius <= upper)
    {
        fahr = (9.0/5.0) * celcius + 32.0;
        printf("%7.2f %10.2f\n", celcius, fahr);
        celcius = celcius + step;
    }
}
