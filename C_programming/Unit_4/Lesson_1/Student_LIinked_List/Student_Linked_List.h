/*
 * Student_Linked_List.h
 *
 * Created on: Mar 9, 2024
 * Author: Ayat Mohamed
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef STUDENT_LINKED_LIST_H_
#define STUDENT_LINKED_LIST_H_
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> User Configurations <<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*Define the data of each student */
typedef struct
{
	int ID;
	char Name[40];
	float Height;

}Data_St;

/* define student node */
struct Student_St
{
	Data_St Student;
	struct Student_St  *Next_Student;
};


/* student status */
typedef enum
{
	NO_ERROR,  /* if Queue has no error return 0 */
	NULL_ERROR,      /* if Queue is not exist return 3*/
}Student_Status_et;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Students linked List APIS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void Fill_Student_Data(struct Student_St *New_Student);
Student_Status_et Add_Student(void);
Student_Status_et Delete_Student(void);
Student_Status_et View_All_Students(void);
Student_Status_et Delete_All_Students(void);

Student_Status_et Get_Nth_Student(void);
Student_Status_et Get_Nth_Student_From_End(void);
Student_Status_et Student_Linked_List_length(void);
Student_Status_et Get_Middle_Student(void);
Student_Status_et Reverse_All_Students(void);
#endif /* STUDENT_LINKED_LIST_H_ */
