#@copyright : Ayat Mohamed
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)    # wildcard take all files.c ,then compile it
OBJ=$(SRC:.c=.o)       #OBJ any thing .c replace it into .o
AS=$(wildcard *.s)     #wildcard take all files.s ,then compile it
AsOBJ=$(AS:.s=.o)      #OBJ any thing .s replace it into .o
Project_name=Pressure_Controller

# first line will be excute
All: $(Project_name).bin
	@echo "****COMPILATION IS DONE****"
$(AsOBJ): $(AS)
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -MAP=Map_file.Map $(LIBS) $(OBJ) $(AsOBJ) -o $@ 
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:	
	rm *.o *.bin *.elf

clean:
	rm *.bin *.elf
	