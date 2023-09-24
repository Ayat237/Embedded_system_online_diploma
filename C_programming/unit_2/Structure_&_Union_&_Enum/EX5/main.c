/*
 * main.c
 * Created on: Sep 24, 2023
 * Author: Ayat mohamed
 * object : EX5
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main ()
{
	int radius;
	float Area;
    printf("Enter radius: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&radius);
    Area = PI * radius * radius;
    printf("Area = %.2f",Area);
	return 0;
}
