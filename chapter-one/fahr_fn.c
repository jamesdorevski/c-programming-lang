#include <stdio.h>

int fahr_to_celsius(int fahr);

// Formula for conversion to celsius = (5/9) * (F - 32)
int main() 
{
    // initial values 

    // run calulation in while loop

    // print result
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 200;
    step = 20;

    fahr = lower;

    printf("Fahrenheit\tCelsius\n");

    while (fahr <= upper)
    {
        celsius = fahr_to_celsius(fahr);
        printf("%10.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int fahr_to_celsius(int fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}
