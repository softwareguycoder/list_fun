################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: list_fun

dependents:
	-cd /home/bhart/git/list_core/list_core/Debug && $(MAKE) all

# Tool invocations
list_fun: $(OBJS) $(USER_OBJS) /home/bhart/git/list_core/list_core/Debug/liblist_core.so
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L"/home/bhart/git/list_core/list_core/Debug" -o "list_fun" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) list_fun
	-@echo ' '

.PHONY: all clean dependents
/home/bhart/git/list_core/list_core/Debug/liblist_core.so:

-include ../makefile.targets
