/*
 * main.c
 * Created on: Sep 24, 2023
 * Author: Ayat mohamed
 * object : EX1
 */

#include <stdio.h>
#include <stdlib.h>
struct Sdistance
{
     int feet;
     float inch;
}G_distance1,G_distance2,G_result;

int main ()
{
    printf("Enter the information for 1st distance:\n");
    printf("Enter feet: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&G_distance1.feet);
    printf("Enter inch: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f",&G_distance1.inch);
    printf("Enter the information for 2nd distance:\n");
    printf("Enter feet: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&G_distance2.feet);
    printf("Enter inch: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f",&G_distance2.inch);
    G_result.feet = G_distance1.feet + G_distance2.feet;
    G_result.inch = G_distance1.inch + G_distance2.inch;
    while( G_result.inch >= 12.0)
    {
    	  G_result.inch -= 12.0;
    	  G_result.feet++;
    }
    printf("sum of distances = %d\'-%.1f\"",G_result.feet,G_result.inch);
	return 0;
}
