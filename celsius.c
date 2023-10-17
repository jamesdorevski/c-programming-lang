#include <stdio.h>

// Formula F = 9/5 * C + 32
int main()
{
    float celsius, fahr;
    float lower, upper, step;

    lower = 0;
    upper = 200;
    step = 20;

    celsius = lower;

    printf("Celsius\tFahrenheit\n");

    while (celsius <= upper)
    {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%7.0f\t%10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}