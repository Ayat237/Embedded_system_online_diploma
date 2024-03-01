/* 
 Author  : ayat mohamed 
*/

#define SYSCTL_RCGC2_R     (*((volatile unsigned int *)0x400FE108))
#define GPIO_PORTF_DIR_R   (*((volatile unsigned int *)0x40025400))
#define GPIO_PORTF_DEN_R   (*((volatile unsigned int *)0x4002551C))
#define GPIO_PORTF_DATA_R  (*((volatile unsigned int *)0x400253FC))


int main()
{
	SYSCTL_RCGC2_R = 0x20;
	volatile unsigned long delay;
	// delay to make sure GPIOF up and running 
	for(delay = 0 ; delay < 200 ; delay++);
	GPIO_PORTF_DIR_R |= (1<<3); // direction is output for pin3
  GPIO_PORTF_DEN_R |= (1<<3); 
	while(1)
	{
		GPIO_PORTF_DATA_R |= (1<<3);
		for(delay = 0 ; delay < 20000 ; delay++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay = 0 ; delay < 20000 ; delay++);
		
	}
	return 0;
}