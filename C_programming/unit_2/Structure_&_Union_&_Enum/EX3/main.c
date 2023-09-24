/*
 * main.c
 * Created on: Sep 24, 2023
 * Author: Ayat mohamed
 * object : EX1
 */

#include <stdio.h>
#include <stdlib.h>
struct ScomplexNumber
{
     float m_real;
     float m_imginary;
}G_complex1,G_complex2,G_result;

int main ()
{
    printf("Enter 1st complex number:\n");
    printf("Enter real and imaginary respectively:\n");
    fflush(stdin);
    fflush(stdout);
    scanf("%f%f",&G_complex1.m_real,&G_complex1.m_imginary);
    printf("\nEnter 2nd complex number:\n");
    printf("Enter real and imaginary respectively:\n");
    fflush(stdin);
    fflush(stdout);
    scanf("%f%f",&G_complex2.m_real,&G_complex2.m_imginary);
    G_result.m_real = G_complex1.m_real + G_complex2.m_real;
    G_result.m_imginary = G_complex1.m_imginary + G_complex2.m_imginary;
    printf("sum = %.1f+%.1fi",G_result.m_real,G_result.m_imginary);
	return 0;
}
