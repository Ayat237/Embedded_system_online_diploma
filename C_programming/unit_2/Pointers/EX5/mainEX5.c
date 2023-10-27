/*
 * mainEx1.c
 * Object : EX5(pointer)
 * Author: Ayat mohamed
 */


#include<stdio.h>
#include<string.h>

struct emplyee
{
	char name[10];
	int ID;
};

int main()
{
	struct emplyee Semp1={"Peter",1000},Semp2={"John",1004},Semp3={"Alex",1002};
	struct emplyee *(Semp[3])={&Semp1,&Semp2,&Semp3};
	struct emplyee (*(*SEmpArr)[3])=&Semp;
	printf("Employee1 :\n");
	printf("Employee Name : %s\n",(**(*(SEmpArr)+0)).name);
	printf("Employee ID : %d\n\n",(**(*(SEmpArr)+0)).ID);
	printf("Employee2 :\n");
	printf("Employee Name : %s\n",(**(*(SEmpArr)+1)).name);
	printf("Employee ID : %d\n\n",(**(*(SEmpArr)+1)).ID);
	printf("Employee3 :\n");
	printf("Employee Name : %s\n",(**(*(SEmpArr)+2)).name);
	printf("Employee ID : %d\n\n",(**(*(SEmpArr)+2)).ID);
	return 0;
}


