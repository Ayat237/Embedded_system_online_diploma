/*
 * Platform_types.h
 * Created on: Nov 5, 2023
 * Author: Ayat Moahmed
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/* unsigned typedef*/
typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
typedef unsigned long int       uint32_t;
typedef unsigned long long int  uint64_t;

typedef volatile unsigned char           vuint8_t;
typedef volatile unsigned short int      vuint16_t;
typedef volatile unsigned long int       vuint32_t;
typedef volatile unsigned long long int  vuint64_t;

/* signed typedef*/
typedef char           sint8_t;
typedef short int      sint16_t;
typedef long int       sint32_t;
typedef long long int  sint64_t;

typedef volatile char           vsint8_t;
typedef volatile short int      vsint16_t;
typedef volatile long int       vsint32_t;
typedef volatile long long int  vsint64_t;

/* real numbers typedef*/
typedef float   float32_t;
typedef double  float64_t;
#endif /* PLATFORM_TYPES_H_ */
