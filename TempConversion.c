#include <stdio.h>

int main(void)
{
    printf("Please enter a temperature value in Farenheit: ");
    float temperatureF;
    scanf("%f", &temperatureF);
    float temperatureC = (temperatureF  - 32.0) * 5.0 / 9.0;
    printf("The corresponding temperature in Celsius is: %.2f°C\n", temperatureC);
    return 0;
}