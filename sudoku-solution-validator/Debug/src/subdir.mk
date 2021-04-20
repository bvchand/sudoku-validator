################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/multithreaded-validator.c \
../src/single-threaded-validotor.c \
../src/sudoku-solution-validator.c 

OBJS += \
./src/multithreaded-validator.o \
./src/single-threaded-validotor.o \
./src/sudoku-solution-validator.o 

C_DEPS += \
./src/multithreaded-validator.d \
./src/single-threaded-validotor.d \
./src/sudoku-solution-validator.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/sudoku-solution-validator/inc" -I"/Users/bharathi/cpp-workspace/sudoku-solution-validator/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


