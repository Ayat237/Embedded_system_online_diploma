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
 * note : this wires added to destination -> CA_Module */
void US_Set_Distance(int distance);
void DC_Set_Speed(int speed);

#endif /* STATE_H_ */
