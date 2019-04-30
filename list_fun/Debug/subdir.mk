################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../client_struct.c \
../list_fun.c \
../stdafx.c 

OBJS += \
./client_struct.o \
./list_fun.o \
./stdafx.o 

C_DEPS += \
./client_struct.d \
./list_fun.d \
./stdafx.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/bhart/git/list_core/list_core" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


