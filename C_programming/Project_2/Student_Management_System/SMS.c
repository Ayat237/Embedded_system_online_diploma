/*
 * SMS.c
 * Created on: Mar 16, 2024
 * Author: Ayat Mohamed
 */
#include "SMS.h"
#include "FIFO.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


FIFO_Buffer_t GStudent_Buff;
Student GStudent[WIDTH];



void INIT(void)
{
	Queue_Init(&GStudent_Buff,GStudent,WIDTH);
	printf("WELCOM TO STUDENT MANANGMENT SYSTEM\n");
}

DATA_TYPE* Search_ID(FIFO_Buffer_t *Student_Buff,int Local_ID)
{
	int i;
	/*define a new pointer to student struct */
	DATA_TYPE *Pstudent;
	Pstudent = Student_Buff->TAIL; /* Assign student to the first element in queue */
	/* loop on all element in queue */
	for(i = 0 ; i < Student_Buff->COUNT ; i++)
	{
		if(Pstudent->ID == Local_ID)
		{
			return Pstudent;
		}
		else
		{
			Pstudent ++; /* move to the next student */
		}

	}
	return NULL;
}
FIFO_Status_t Search_FName(FIFO_Buffer_t *Student_Buff,char *Fname)
{
	int i,j;
	int count = 0 ;
	/*define a new pointer to student struct */
	DATA_TYPE *Pstudent;
	Pstudent = Student_Buff->TAIL; /* Assign student to the first element in queue */
	/* loop on all element in queue */
	for(i = 0 ; i < Student_Buff->COUNT ; i++)
	{
		if(strcmp(Pstudent[i].F_Name,Fname) == 0)
		{
			printf("First Name : %s\n",Pstudent[i].F_Name);
			printf("Last Name : %s\n",Pstudent[i].L_Name);
			printf("ID : %d\n",Pstudent[i].ID);
			printf("GPA : %.2f\n",Pstudent[i].GPA);
			for(j = 0 ; j < Courses_NO ; j++)
			{
				printf("Course ID #%d : %d\n",j+1,Pstudent[i].Course_ID[j]);
			}
			printf(">>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n");
			count ++;
		}

	}
	if(count <= 0)
	{
		return NULL_QUEUE;
	}
	return NO_ERROR_QUEUE;
}

int Search_Course(FIFO_Buffer_t *Student_Buff,int Course_ID)
{
	int i,j;
	int count = 0 ;
	/*define a new pointer to student struct */
	DATA_TYPE *Pstudent;
	Pstudent = Student_Buff->TAIL; /* Assign student to the first element in queue */
	/* loop on all element in queue */
	for(i = 0 ; i < Student_Buff->COUNT ; i++)
	{
		for(j = 0 ; j < Courses_NO ; j++)
		{
			if(Course_ID == Pstudent[i].Course_ID[j])
			{
				printf("First Name : %s\n",Pstudent[i].F_Name);
				printf("Last Name : %s\n",Pstudent[i].L_Name);
				printf("ID : %d\n",Pstudent[i].ID);
				printf("GPA : %.2f\n",Pstudent[i].GPA);
				printf(">>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n");
				count ++;
			}
		}

	}
	return count;
}
FIFO_Status_t Add_Student_Manually(void)
{
	int i;
	/*define a new student struct */
	DATA_TYPE New_Student;
	DPRINTF("Enter the student id :");
	scanf("%d",&New_Student.ID);
	if((Search_ID(&GStudent_Buff ,New_Student.ID)== NULL))
	{
		DPRINTF("Enter The Student First Name :");
		gets(New_Student.F_Name);
		DPRINTF("Enter The Student Last Name :");
		gets(New_Student.L_Name);
		DPRINTF("Enter the student GPA :");
		scanf("%f",&New_Student.GPA);
		for(i = 0 ; i < Courses_NO ; i++)
		{
			DPRINTF("Enter Course ID #%d : ",i+1);
			scanf("%d",&New_Student.Course_ID[i]);
		}
		if(Queue_Add_Item(&GStudent_Buff ,New_Student) == NO_ERROR_QUEUE)
		{
			printf("The student Is Added Successfully:)\n");
		}
	}
	else
	{
		printf("[ERROR!!] This ID %d is already Exist \n",New_Student.ID);
		return NULL_QUEUE;
	}
	return NO_ERROR_QUEUE;
}
FILE_et Add_Student_From_File(void) {

	FILE *File;
	DATA_TYPE New_Student;
	const char *File_Name = "StudentsDetails.txt";

	// Open the file for reading
	File = fopen(File_Name, "r");
	if (File == NULL) {
		printf("[ERROR!!] Unable to open file %s\n", File_Name);
		return ERORR_FILE;
	}

	// Read student information from the file and add them to the queue
	while (fscanf(File, "%d %s %s %f %d %d %d %d %d", &New_Student.ID, New_Student.F_Name,
			New_Student.L_Name, &New_Student.GPA, &New_Student.Course_ID[0],
			&New_Student.Course_ID[1], &New_Student.Course_ID[2],
			&New_Student.Course_ID[3], &New_Student.Course_ID[4]) == 9) {

		// Add the student to the queue
		if ((Search_ID(&GStudent_Buff, New_Student.ID) == NO_ERROR_QUEUE))
		{

			if (Queue_Add_Item(&GStudent_Buff, New_Student) == NO_ERROR_QUEUE)
			{
				printf("Student with ID %d added successfully\n", New_Student.ID);
			}
			else
			{
				printf("[WARNING] Failed to add student with ID %d\n", New_Student.ID);
			}
		}
		else
		{
			printf("[ERROR!!] This ID %d already exists\n", New_Student.ID);
		}
	}

	// Close the file
	fclose(File);

	return NO_ERROR_FILE;
}
FIFO_Status_t Delete_Student(void)
{
	int ID ;
	DPRINTF("Enter the student id :");
	scanf("%d",&ID);
	DATA_TYPE *Old_Student = Search_ID(&GStudent_Buff ,ID);
	if(Old_Student == NULL)
	{
		printf("[ERROR!!] This ID %d is not exists\n", Old_Student->ID);
	}
	else
	{
		if(Queue_Delete_Item(&GStudent_Buff,Old_Student) == NO_ERROR_QUEUE)
		{
			printf("Student with ID %d deleted successfully\n",ID);
		}
	}
	return NO_ERROR_QUEUE;

}

FIFO_Status_t Find_Student_By_ID(void)
{
	int j = 0 ;
	int ID ;
	DPRINTF("Enter the student id :");
	scanf("%d",&ID);
	DATA_TYPE *New_Student = Search_ID(&GStudent_Buff ,ID);
	if(New_Student== NULL)
	{
		printf("[ERROR!!] This ID %d is not exists\n", ID);
		return NULL_QUEUE;
	}
	else
	{
		printf("First Name : %s\n",New_Student->F_Name);
		printf("Last Name : %s\n",New_Student->L_Name);
		printf("ID : %d\n",New_Student->ID);
		printf("GPA : %.2f\n",New_Student->GPA);
		for(j = 0 ; j < Courses_NO ; j++)
		{
			printf("Course ID #%d : %d\n",j+1,New_Student->Course_ID[j]);
		}
	}
	return NO_ERROR_QUEUE;
}
FIFO_Status_t Find_Student_By_First_Name(void)
{
	char Fname[20] ;
	DPRINTF("Enter the student first name :");
	gets(Fname);
	if(Search_FName(&GStudent_Buff ,Fname) == NO_ERROR_QUEUE)
	{
		printf("Students with Frist name %s  founded successfully\n",Fname);
	}
	else
	{
		printf("[ERROR!!] This student with first name %s is not exists\n",Fname);
		return NULL_QUEUE;
	}
	return NO_ERROR_QUEUE;

}
FIFO_Status_t Find_Student_By_course_ID(void)
{
	int Course_ID ;
	int count ;
	DPRINTF("Enter the course id :");
	scanf("%d",&Course_ID);
	count = Search_Course(&GStudent_Buff,Course_ID);
	if(count >= 0)
	{
		printf("[INFO] Total number of students enrolled : %d \n",count);
	}
	else
	{
		printf("[ERROR!!] The course id %d is invalid \n",Course_ID);
		return NULL_QUEUE;
	}
	return NO_ERROR_QUEUE;
}
FIFO_Status_t Find_Total_Students(FIFO_Buffer_t *Student_Buff)
{
	/*check if queue is valid */
	if ((Student_Buff->BASE ==NULL) || (Student_Buff->HEAD ==NULL) || (Student_Buff->TAIL==NULL))
	{
		return NULL_QUEUE;
	}
	else
	{
		printf("[INFO] Total number of students : %d \n",Student_Buff->COUNT);
		printf("[INFO] You can add up to %d students  \n",WIDTH);
		printf("[INFO] You can add %d more students \n",(WIDTH-Student_Buff->COUNT));
	}
	return NO_ERROR_QUEUE;
}
FIFO_Status_t Total_Students(void)
{
	if(Find_Total_Students(&GStudent_Buff)== NO_ERROR_QUEUE)
	{
		return NO_ERROR_QUEUE;
	}
	else
	{
		printf("[ERROR!!] The students buffer is invalid \n");
		return NULL_QUEUE;
	}
}
FIFO_Status_t Update_Student_Details(void)
{
	int i;
	int ID;
	int U_Choice;
	/*define a new student struct */
	DPRINTF("Enter the student id you to update :");
	scanf("%d",& ID);
	DATA_TYPE *Old_Student = Search_ID(&GStudent_Buff ,ID);
	if((Old_Student != NULL))
	{
		printf("1.First name\n");
		printf("2.Last name\n");
		printf("3.ID number\n");
		printf("4.GPA\n");
		printf("5.Courses\n");
		DPRINTF("Enter the number you to update :");
		scanf("%d",&U_Choice);
		switch(U_Choice)
		{
		case 1:
			DPRINTF("Enter The New First Name :");
			gets(Old_Student->F_Name);
			printf("[INFO] The first name is updated successfully\n");
			break;
		case 2:
			DPRINTF("Enter The New Last Name :");
			gets(Old_Student->L_Name);
			printf("[INFO] The last name is updated successfully\n");
			break;
		case 3:
			DPRINTF("Enter the New ID :");
			scanf("%d",&Old_Student->ID);
			printf("[INFO] The ID is updated successfully\n");
			break;
		case 4:
			DPRINTF("Enter the New GPA :");
			scanf("%f",&Old_Student->GPA);
			printf("[INFO] The GPA is updated successfully\n");
			break;
		case 5:
			for(i = 0 ; i < Courses_NO ; i++)
			{
				DPRINTF("Enter The New Course ID #%d : ",i+1);
				scanf("%d",&Old_Student->Course_ID[i]);
			}
			printf("[INFO] The courses is updated successfully\n");
			break;
		}
	}
	else
	{
		printf("[ERROR!!] This ID %d is not exist \n",ID);
		return NULL_QUEUE;
	}
	return NO_ERROR_QUEUE;
}

void Show_All_Students(void)
{
	Queue_Print_All(&GStudent_Buff);
}
