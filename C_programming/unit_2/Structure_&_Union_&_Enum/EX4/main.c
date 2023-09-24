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
	int marks;
}G_Students[10];

int main ()
{
	int loop;
	printf("Enter the information of students:\n");
	for(loop = 0 ; loop < 5; loop++)
	{
		printf("for roll number %d\n",loop+1);
		printf("Enter name: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%s",&G_Students[loop].name);
		printf("Enter marks: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&G_Students[loop].marks);
	}
	printf("\nDisplaying the information of students:\n");
	for(loop = 0 ; loop < 5; loop++)
	{
		printf("information for roll number %d\n",loop+1);
		printf("name: %s\n",G_Students[loop].name);
		printf("marks: %d\n",G_Students[loop].marks);
	}
	return 0;
}

