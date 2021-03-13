#include <stdio.h>

#define PI 3.1415f

int main(void)
{
        float volume, radius;
        printf("Please enter the radius of the ball: ");
	scanf("%f", &radius);
        volume = ( 4.0f / 3.0f ) * PI * radius * radius * radius;
        printf("If radius equals %.2f meters, the volume of a ball will be %.2f cubic meters.\n", radius, volume);
        return 0;
}

