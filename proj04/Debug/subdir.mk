################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application.cpp \
../Matrix.cpp \
../MatrixTester.cpp \
../VecTester.cpp \
../tester.cpp 

OBJS += \
./Application.o \
./Matrix.o \
./MatrixTester.o \
./VecTester.o \
./tester.o 

CPP_DEPS += \
./Application.d \
./Matrix.d \
./MatrixTester.d \
./VecTester.d \
./tester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


