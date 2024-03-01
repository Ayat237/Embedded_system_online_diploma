/*
	Author : Ayat Mohamed 
	object : startup.c 
*/

#include <stdint.h>
void Reset_Handler();
extern int main(void);
extern uint32_t _stack_top;
void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;

// booking 1024 location in .bss through unitialized array of int 
static uint32_t Stack_top[256];


//g_p_func_vectors is array of constant pointer to function take nothing and return void
// this method is the same like of array
/*

uint32_t vectors[] __attribute__((section(".vectors")))={
	(uint32_t) (Stack_top+sizeof(Stack_top)),
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_Handler,
};
*/
void (*const g_p_func_vectors[])() __attribute__((section(".vectors"))) = 
{
	(void (*)()) (Stack_top+sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
};

extern uint32_t _E_text;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_bss;
extern uint32_t _E_bss;


void Reset_Handler()
{
	// copy data section from flash to SRAM
	uint32_t DATA_Size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char * P_src = (unsigned char *)&_E_text;
	unsigned char  * P_dst= (uint8_t*)&_S_DATA;
	for (int i = 0 ;  i < DATA_Size ; i ++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	//init .bss section in SRAM = 0;
	uint32_t BSS_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	unsigned char* bss_dst= (unsigned char*)&_S_bss;
	for (int i = 0 ;  i < BSS_Size ; i ++)
	{
		*((unsigned char*)bss_dst++) = (unsigned char)0x00;
	}
	//jump on main 
	main();
}
