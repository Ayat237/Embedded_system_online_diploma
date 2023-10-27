/*
 * main.c
 * Created on: Sep 24, 2023
 * Author: Ayat mohamed
 * object : EX6
 */

#include <stdio.h>
#include <stdlib.h>

union job
{
	char name[32];
	float salary;
	int worker_no;
}u;
struct job1
{
	char name[32];
	float salary;
	int worker_no;
}s;

int main ()
{
    printf("size of union =%d byte\n",sizeof(u));
    printf("size of structure =%d byte",sizeof(s));
	return 0;
}


