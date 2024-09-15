/*
 * main.c
 * Created on: Mar 16, 2024
 * Author: Ayat Mohamed
 */

#include "SMS.h"
#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	INIT();
	int option;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("Choose from of the one following options\n");
		printf("Choose(1) : to add student details manually\n");
		printf("Choose(2) : to add student details from text file \n");
		printf("Choose(3) : to find student details using Id\n");
		printf("Choose(4) : to find student details using first name\n");
		printf("Choose(5) : to to find student details using course Id\n");
		printf("Choose(6) : to Find the total number of students \n");
		printf("Choose(7) : to Update student using Id\n");
		printf("Choose(8) : to delete student using Id\n");
		printf("Choose(9) : to view_all_students\n");
		printf("Choose(10) : to Exit\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("Enter your option : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			Add_Student_Manually();
			break;
		case 2:
			Add_Student_From_File();
			break;
		case 3:
			Find_Student_By_ID();
			break;
		case 4:
			Find_Student_By_First_Name();
			break;
		case 5:
			Find_Student_By_course_ID();
			break;
		case 6:
			Total_Students();
			break;
		case 7:
			Update_Student_Details();
			break;
		case 8:
			Delete_Student();
			break;
		case 9:
			Show_All_Students();
			break;
		case 10:
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
