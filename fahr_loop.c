#include <stdio.h>

// Formula for conversion to celsius = (5/9) * (F - 32)
int main() 
{
    printf("Fahrenheit\tCelsius\n");
    
    float fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%10.0f\t%7.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
}