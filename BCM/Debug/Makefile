################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../bmschip.c \
../can.c \
../DigIO.c \
../isocontrol.c \
../ivtcontrol.c \
../moduleelectronic.c \
../SPI.c \
../statemachine.c \
../timer.c \
../uc_v3_base_sw.c \
../usart.c \
../user_tasks.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
bmschip.o \
can.o \
DigIO.o \
isocontrol.o \
ivtcontrol.o \
moduleelectronic.o \
SPI.o \
statemachine.o \
timer.o \
uc_v3_base_sw.o \
usart.o \
user_tasks.o

OBJS_AS_ARGS +=  \
bmschip.o \
can.o \
DigIO.o \
isocontrol.o \
ivtcontrol.o \
moduleelectronic.o \
SPI.o \
statemachine.o \
timer.o \
uc_v3_base_sw.o \
usart.o \
user_tasks.o

C_DEPS +=  \
bmschip.d \
can.d \
DigIO.d \
isocontrol.d \
ivtcontrol.d \
moduleelectronic.d \
SPI.d \
statemachine.d \
timer.d \
uc_v3_base_sw.d \
usart.d \
user_tasks.d

C_DEPS_AS_ARGS +=  \
bmschip.d \
can.d \
DigIO.d \
isocontrol.d \
ivtcontrol.d \
moduleelectronic.d \
SPI.d \
statemachine.d \
timer.d \
uc_v3_base_sw.d \
usart.d \
user_tasks.d

OUTPUT_FILE_PATH +=BMS_Master_Welzmiller_6_2(1).elf

OUTPUT_FILE_PATH_AS_ARGS +=BMS_Master_Welzmiller_6_2(1).elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler

























./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Atmel\7.0\Packs\atmel\ATmega_DFP\1.0.98\include"  -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega64m1 -B "D:\Atmel\7.0\Packs\atmel\ATmega_DFP\1.0.98\gcc\dev\atmega64m1" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="BMS_Master_Welzmiller_6_2(1).map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega64m1 -B "D:\Atmel\7.0\Packs\atmel\ATmega_DFP\1.0.98\gcc\dev\atmega64m1"  
	@echo Finished building target: $@
	"D:\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "BMS_Master_Welzmiller_6_2(1).elf" "BMS_Master_Welzmiller_6_2(1).hex"
	"D:\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "BMS_Master_Welzmiller_6_2(1).elf" "BMS_Master_Welzmiller_6_2(1).eep" || exit 0
	"D:\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "BMS_Master_Welzmiller_6_2(1).elf" > "BMS_Master_Welzmiller_6_2(1).lss"
	"D:\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "BMS_Master_Welzmiller_6_2(1).elf" "BMS_Master_Welzmiller_6_2(1).srec"
	"D:\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "BMS_Master_Welzmiller_6_2(1).elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "BMS_Master_Welzmiller_6_2(1).elf" "BMS_Master_Welzmiller_6_2(1).a" "BMS_Master_Welzmiller_6_2(1).hex" "BMS_Master_Welzmiller_6_2(1).lss" "BMS_Master_Welzmiller_6_2(1).eep" "BMS_Master_Welzmiller_6_2(1).map" "BMS_Master_Welzmiller_6_2(1).srec" "BMS_Master_Welzmiller_6_2(1).usersignatures"
	