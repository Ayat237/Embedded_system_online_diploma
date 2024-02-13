#include "UART.h"

unsigned char str_buffer[100] = "Learn_in_depth : Ayat mohamed";
unsigned char const str_buffer2[100] = "Learn_in_depth : Ayat mohamed";
void main ()
{
	Uart_Send_String(str_buffer);
}