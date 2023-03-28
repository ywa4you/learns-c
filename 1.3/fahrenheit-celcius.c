#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */
main()
{
    float fahr, celcius;
    int  lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Fahrenheit Celcius\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%10.2f %7.2f\n", fahr, celcius);
        fahr = fahr + step;
    }
}
