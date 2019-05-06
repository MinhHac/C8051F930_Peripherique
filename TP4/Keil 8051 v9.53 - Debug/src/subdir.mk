################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/InitDevice.c \
../src/LCD.c \
../src/TP4_main.c \
../src/clavier.c \
../src/variables_globales.c 

ASM_SRCS += \
../src/attente_10.asm 

OBJS += \
./src/InitDevice.OBJ \
./src/LCD.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/TP4_main.OBJ \
./src/attente_10.OBJ \
./src/clavier.OBJ \
./src/variables_globales.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h

src/LCD.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/time.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/LCD_port.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/LCD.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/TP4_main.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/InitDevice.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/LCD.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/LCD_port.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/variables_globales.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/pin_test.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/time.h C:/SiliconLabs/SimplicityStudio/v3/developer/toolchains/keil_8051/9.53/INC/STDIO.H //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/clavier.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h

src/%.OBJ: ../src/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/clavier.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/clavier_port.h //calebasse/21609785/Bureau/TP\ Micro\ S2/MCU8bits_RepEtudiants/HO_TASEVSKI/TP4/inc/clavier.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h

src/variables_globales.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/C8051F930/inc/SI_C8051F930_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/compiler_defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h


