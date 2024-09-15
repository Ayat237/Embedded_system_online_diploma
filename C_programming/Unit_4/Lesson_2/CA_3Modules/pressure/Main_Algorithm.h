/*
 * Main_Algorithm.h
 * Created on: Apr 19, 2024
 * Author: Ayat Mohamed
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_
#include "state.h"
/* define all states function */
STATE_Define(MA_Pressure_Detected);

/* declare a State as pointer to function return void and take nothing */
extern void (*MA_State)(void);


#endif /* MAIN_ALGORITHM_H_ */
