/*
 * State.h
 * Created on: Apr 14, 2024
 * Author: Ayat Mohamed
 */

#ifndef STATE_H_
#define STATE_H_

/* automatic state function generated */
#define STATE_Define(_StateFunc_) void ST_##_StateFunc_(void)

/* automatic state function generated as a symbol to pass to pointer to function */
#define STATE_Symbol(_StateFunc_) ST_##_StateFunc_

/* State connections
 * note : this wires added to destination ,at input signal */
void Set_Pressure_Sensor(int P_Value);
void High_Pressure_Dtected(void);
void Start_Alarm(void);
void Stop_Alarm(void);

#endif /* STATE_H_ */
