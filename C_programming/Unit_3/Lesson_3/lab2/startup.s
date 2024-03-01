/* 
startup_cortexM3.s
Author : Ayat Mohamed
*/

/* SRAM = 0X20000000 
 0X20001000 
*/

.section .vectors         /* vectors sections */
.word 0X20001000          /* 7ot el 32 bit bel rakam dah el howa -> sp */
.word _reset              /* ba3d el 0X20001000  b 4 byte hy3mel jump 3ala el reset section w el word hyt7at feha el symbol dah (_reset)*/
.word _vector_handler     /* NMI*/
.word _vector_handler     /* fault handler*/
.word _vector_handler     /* usage fault*/
.word _vector_handler     /* reserved */
.word _vector_handler     /* reserved */
.word _vector_handler     /* reserved */
.word _vector_handler     /* reserved */
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler
.word _vector_handler

.section .text
_reset:
	bl main
	b .                 //34an yfdal fel main()
	
.thumb_func
_vector_handler:
	b _reset