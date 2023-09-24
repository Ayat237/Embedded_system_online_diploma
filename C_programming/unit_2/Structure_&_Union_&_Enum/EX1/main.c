/*
 * main.c
 * Created on: Sep 24, 2023
 * Author: Ayat mohamed
 * object : EX1
 */

#include <stdio.h>
#include <stdlib.h>
struct Sstudent
{
	char name[20];
	int roll;
	float marks;
}G_Students;

int main ()
{
    printf("Enter the information of students:\n");
    printf("Enter name: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%s",&G_Students.name);
    printf("Enter roll number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&G_Students.roll);
    printf("Enter marks: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f",&G_Students.marks);
    printf("\nDisplaying the information of students:\n");
    printf("name: %s\n",G_Students.name);
    printf("roll number : %d\n",G_Students.roll);
    printf("marks: %.1f\n",G_Students.marks);
	return 0;
}
