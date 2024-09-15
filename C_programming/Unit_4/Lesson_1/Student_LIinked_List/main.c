/*
 * main.c
 * Created on: Mar 9, 2024
 * Author: Ayat Mohamed
 */


#include "Student_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Student_St *student;
int main ()
{
	int option;
	int count =0;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("Choose from of the one following options\n");
		printf("Choose(1) : to add_student\n");
		printf("Choose(2) : to delete_student\n");
		printf("Choose(3) : to view_all_students\n");
		printf("Choose(4) : to Delete_all_students\n");
		printf("Choose(5) : to Get_Nth_Student_From_First \n");
		printf("Choose(6) : to Get_Nth_Student_From_End \n");
		printf("Choose(7) : to Get_Student_Linked_List_length \n");
		printf("Choose(8) : to Get_Middle_Student \n");
		printf("Choose(9) : to Exit\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("Enter your option : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_All_Students();
			break;
		case 4:
			Delete_All_Students();
			break;
		case 5:
			Get_Nth_Student();
			break;
		case 6:
			Get_Nth_Student_From_End();
			break;
		case 7:
			count = Student_Linked_List_length();
			printf("Number of students = %d\n",count);
			break;
		case 8:
			Get_Middle_Student();
			break;
		case 9:
			goto label;
			break;
		default :
			printf("Wrong option\n");
		}
	}
	label :
	printf("thanks\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	return 0;
}
