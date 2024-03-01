#@copyright : Ayat
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
AsOBJ=$(AS:.s=.o)
Project_name=cortex_M4

All: $(Project_name).bin
	@echo "****DONE****"
$(AsOBJ): $(AS)
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -MAP=Map_file.map
	cp $(Project_name).elf $(Project_name).axf


$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
clean_all:	
	rm *.o *.bin *.elf

clean:
	rm *.bin *.elf
	