################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/multithreaded-validator.c \
../src/single-threaded-validator.c \
../src/sudoku-solution-validator.c 

OBJS += \
./src/multithreaded-validator.o \
./src/single-threaded-validator.o \
./src/sudoku-solution-validator.o 

C_DEPS += \
./src/multithreaded-validator.d \
./src/single-threaded-validator.d \
./src/sudoku-solution-validator.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


