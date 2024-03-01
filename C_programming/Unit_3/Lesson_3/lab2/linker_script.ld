/* Author : Ayat mohamed
   Linker_script : cortex_M3
 */

MEMORY
{
	FLASH(RX) : ORIGIN = 0x08000000 , LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	}>FLASH
	.data :
	{
	    _S_DATA = .;
		*(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}>SRAM AT> FLASH
	.bss :
	{   
	    _S_bss = .;
		*(.bss)
		_E_bss = .;
		. = ALIGN(4);
		. = . + 0X1000;
		_stack_top = .;
	}>SRAM
}