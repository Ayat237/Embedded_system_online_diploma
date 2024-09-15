/*
 * SMS.h
 * Created on: Mar 16, 2024
 * Author: Ayat Mohamed
 */

#ifndef SMS_H_
#define SMS_H_
#include <stdint.h>
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> User Configurations <<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#define  Courses_NO  5
/* select the element type : uint8_t ,uint16_t ,uin32_t ,uint64_t ,.... */
#define DATA_TYPE Student

/* Buffer width */
#define WIDTH 55

#define DPRINTF(...) {printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> QUEUE BUFFER <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/* Queue data type*/
typedef struct
{
	int   ID;
	int   Course_ID[10];
	float GPA;
	char  F_Name[20];
	char  L_Name[20];
}Student;

typedef struct
{
	DATA_TYPE *BASE;
	DATA_TYPE *HEAD;
	DATA_TYPE *TAIL;
	uint32_t COUNT;
	uint32_t LENGTH;
}FIFO_Buffer_t;

/* queue status */
typedef enum
{
	NO_ERROR_QUEUE,  /* if Queue has no error return 0 */
	FULL_QUEUE,      /* if Queue is full return 1 */
	EMPTY_QUEUE,     /* if Queue is empty return 2 */
	NULL_QUEUE,      /* if Queue is not exist return 3*/
}FIFO_Status_t;

typedef enum
{
	NO_ERROR_FILE,
	ERORR_FILE,
	FORMAT_ERROR
}FILE_et;


void INIT(void);
DATA_TYPE* Search_ID(FIFO_Buffer_t *Student_Buff,int Local_ID);
FIFO_Status_t Search_FName(FIFO_Buffer_t *Student_Buff,char *Fname);
int Search_Course(FIFO_Buffer_t *Student_Buff,int Course_ID);
FIFO_Status_t Add_Student_Manually(void);
FILE_et Add_Student_From_File(void );
FIFO_Status_t Delete_Student(void);
FIFO_Status_t Student_Buffer_Is_Full(void);
FIFO_Status_t Student_Buffer_Is_Empty(void);
FIFO_Status_t Find_Student_By_ID(void);
FIFO_Status_t Find_Student_By_First_Name(void);
FIFO_Status_t Find_Student_By_course_ID(void);
FIFO_Status_t Find_Total_Students(FIFO_Buffer_t *Student_Buff);
FIFO_Status_t Total_Students(void);
FIFO_Status_t Update_Student_Details(void);
void Show_All_Students(void);
#endif /* SMS_H_ */
