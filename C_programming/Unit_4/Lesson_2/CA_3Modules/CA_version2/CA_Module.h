/*
 * CA_Version1.h
 * Created on: Apr 14, 2024
 * Author: Ayat Mohamed
 */

#ifndef CA_MODULE_H_
#define CA_MODULE_H_
#include "State.h"


/* declare state function CA */
STATE_Define(CA_Waiting); /*void ST_CA_Wating */
STATE_Define(CA_Driving); /*void ST_CA_Driving */

/* declare a State as pointer to function return void and take nothing */
extern void (*CA_State)(void);

/*
 * description : Generate random numbers between Min_Number and Max_Number
 * inputs: Min_Number , Max_Number , Counter
 * output : All random numbers are generated*/
int US_Get_diatance_Random(int min_num , int max_num ,int count);

#endif /* CA_MODULE_H_ */
