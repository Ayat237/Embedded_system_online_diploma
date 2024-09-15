/*
 * Student_Linked_List.c
 *
 * Created on: Mar 9, 2024
 * Author: Ayat Mohamed
 */
#include "Student_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* define head node to point the first student */
struct Student_St *HEAD = NULL;

void Fill_Student_Data(struct Student_St *New_Student)
{
	printf("Enter The Student ID : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&(New_Student->Student.ID));
	printf("Enter The Student FullName : ");
	fflush(stdin);
	fflush(stdout);
	gets(New_Student->Student.Name);
	printf("Enter The Student Height : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&(New_Student->Student.Height));
}

Student_Status_et Add_Student(void)
{
	/* create new student node*/
	struct Student_St *New_Student;
	struct Student_St *Last_Student;
	if(HEAD == NULL)
	{
		/* create new record */
		New_Student =(struct Student_St*)malloc(sizeof(struct Student_St));
		if(New_Student == NULL)
		{
			printf("ERROR!");
			return NULL_ERROR;
		}
		else
		{
			HEAD = New_Student;
		}
	}
	else /* if we have a record */
	{
		/*assign head to last student to pass through all elements */
		Last_Student = HEAD;
		while(Last_Student->Next_Student)
		{
			Last_Student = Last_Student->Next_Student;
		}
		New_Student =(struct Student_St*)malloc(sizeof(struct Student_St));
		if(New_Student == NULL)
		{
			printf("ERROR!");
			return NULL_ERROR;
		}
		else
		{
			Last_Student->Next_Student = New_Student;		}

	}
	/* Add student data at the end of linked list */
	Fill_Student_Data(New_Student);
	/* Assign null to the new student*/
	New_Student->Next_Student = NULL;
	return NO_ERROR;
}

Student_Status_et Delete_Student(void)
{
	struct Student_St *Selected_Student;
	struct Student_St *Previous_Student;

	/* Define a specific id you want to delete it */
	int Selected_ID;
	printf("Enter the ID you want delete it :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&Selected_ID);

	/*if list of students have records */
	if(HEAD != NULL)
	{
		Selected_Student=HEAD;
		Previous_Student=NULL;
		/* loop on all students in record to delete a specific id*/
		while(Selected_Student != NULL)
		{
			/*if the selected id matched to any id of the list */
			if(Selected_Student->Student.ID == Selected_ID)
			{
				/* if selected_id not first id*/
				if(Previous_Student != NULL)
				{
					Previous_Student->Next_Student=Selected_Student->Next_Student;
				}
				else /* if previous equal null -> selected_id is the first student */
				{
					HEAD = Selected_Student->Next_Student;
				}
				free(Selected_Student); /* delete the selected id*/
				/* return no error if we find it */
				return NO_ERROR;
			}
			/* to loop to all elements in */
			Previous_Student = Selected_Student;
			Selected_Student = Selected_Student->Next_Student;
		}
	}
	/*the selected id is not exist */
	printf("[ERROR!!]The ID not exist in this list");
	return NULL_ERROR;
}

Student_Status_et View_All_Students(void)
{
	struct Student_St *Current_Student = HEAD;
	int count = 0 ;
	if(HEAD == NULL)
	{
		return NULL_ERROR;
	}
	else
	{
		while(Current_Student != NULL)
		{
			printf("Student No %d : \n",count+1);
			printf("ID : %d\n",Current_Student->Student.ID);
			printf("NAME : %s\n",Current_Student->Student.Name);
			printf("HEIGHT : %.2f\n",Current_Student->Student.Height);
			printf("-----------------------------------\n");
			Current_Student = Current_Student->Next_Student;
			count++;
		}
		return NO_ERROR;
	}
}
Student_Status_et Delete_All_Students(void)
{
	struct Student_St *Current_Student = HEAD;
	if(HEAD == NULL)
	{
		return NULL_ERROR;
	}
	else
	{
		while(Current_Student != NULL)
		{
			/*define a temp node to store the student we want delete it and assign it to the current student ,
			 *and current student points to the first student */
			struct Student_St *Temp_Student = Current_Student;
			/* make a current student points to the next of current student ,then delete the temp */
			Current_Student = Current_Student->Next_Student;
			free(Temp_Student);
		}
		/* when head = NULL ,this mean that all list is empty */
		HEAD = NULL;
		return NO_ERROR;
	}
}
Student_Status_et Get_Nth_Student(void)
{
	unsigned int Student_Number;
	int count=1;
	printf("Enter the student no you want get it :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&Student_Number);

	struct Student_St *Current_Student = HEAD;
	if(HEAD == NULL)
	{
		printf("[ERROR!!] LIST IS EMPTY\n");
		return NULL_ERROR;
	}
	else
	{
		/* loop on student list until Current_Student equal null*/
		while(Current_Student)
		{
			if(Student_Number == count)
			{
				printf("ID : %d\n",Current_Student->Student.ID);
				printf("NAME : %s\n",Current_Student->Student.Name);
				printf("HEIGHT : %.2f\n",Current_Student->Student.Height);
			}
			/* make a current student points tO the next of current student */
			Current_Student = Current_Student->Next_Student;
			count++;
		}
	}
	return NO_ERROR;
}
Student_Status_et Get_Nth_Student_From_End(void)
{
	unsigned int Student_Number;
	int count=0;
	printf("Enter the student no you want get it :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&Student_Number);
	struct Student_St *Current_Student = HEAD;
	if(HEAD == NULL)
	{
		printf("[ERROR!!] LIST IS EMPTY\n");
		return NULL_ERROR;
	}
	else
	{
		/* loop on student list until Current_Student equal null*/
		while(Current_Student)
		{
			if(count ==(Student_Linked_List_length()-Student_Number))
			{
				printf("ID : %d\n",Current_Student->Student.ID);
				printf("NAME : %s\n",Current_Student->Student.Name);
				printf("HEIGHT : %.2f\n",Current_Student->Student.Height);
			}
			/* make a current student points tO the next of current student */
			count++;
			Current_Student = Current_Student->Next_Student;
		}
	}

	return NO_ERROR;
}
Student_Status_et Student_Linked_List_length(void)
{
	int count=0;
	struct Student_St *Current_Student = HEAD;
	if(HEAD == NULL)
	{
		printf("[ERROR!!] LIST IS EMPTY\n");
		return NULL_ERROR;
	}
	else
	{
		/* loop on student list until Current_Student equal null*/
		while(Current_Student)
		{
			Current_Student = Current_Student->Next_Student;
			count++;
		}
		//printf("Number of students = %d\n",count);

	}
	return count;
}
Student_Status_et Get_Middle_Student(void)
{
	struct Student_St *Slow_Ptr = HEAD;
	struct Student_St *Fast_Ptr= HEAD;
	int flag = 0;
	if(HEAD == NULL)
	{
		printf("[ERROR!!] LIST IS EMPTY\n");

		return NULL_ERROR;
	}
	while(Fast_Ptr)
	{
		Fast_Ptr=Fast_Ptr->Next_Student;
		if(Fast_Ptr == NULL)
		{
			flag = 1; /* list is odd */
			break;
		}
		Fast_Ptr=Fast_Ptr->Next_Student;
		Slow_Ptr=Slow_Ptr->Next_Student;
	}
	if(flag == 0)/* list is even */
	{
		printf("the list is even , the second middle element :\n");
	}
	printf("ID : %d\n",Slow_Ptr->Student.ID);
	printf("NAME : %s\n",Slow_Ptr->Student.Name);
	printf("HEIGHT : %.2f\n",Slow_Ptr->Student.Height);
	return NO_ERROR;
}
Student_Status_et Reverse_All_Students(void)
{
	struct Student_St *Current_Student = HEAD->Next_Student;
	struct Student_St *Previous_Student = HEAD;
	struct Student_St *NEXT_Student = HEAD;
	if(HEAD == NULL)
	{
		printf("[ERROR!!] LIST IS EMPTY\n");
		return NULL_ERROR;
	}
	while(Current_Student != NULL)
	{
			NEXT_Student = Current_Student->Next_Student;
			Current_Student->Next_Student = Previous_Student;
			Previous_Student = Current_Student;
			Current_Student = NEXT_Student;
	}
	HEAD = Previous_Student;
	View_All_Students();
	return NO_ERROR;
}



