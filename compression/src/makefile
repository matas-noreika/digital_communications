#C Compiler
CC= gcc
#C Compiler Flags
CCFLAGS= -I../include
#Linker Dependency Flags
LDFLAGS=

#Local Directories
LOCALBIN=../bin
LOCALOBJ=../obj
LOCALDEP=../dep

#Build target files
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=$(LOCALOBJ)/%.o)
DEPS=$(SRCS:%.c=$(LOCALDEP)/%.d)
EXES=$(SRCS:%.c=$(LOCALBIN)/%.exe)

.PHONY: all clean
.PRECIOUS: $(LOCALBIN)/%.exe $(LOCALOBJ)/%.o $(LOCALDEP)/%.d

#general make all rule
all: $(EXES)

#general clean rule
clean:
	-@rm -f $(LOCALBIN)/*.exe 2> /dev/null
	-@rm -f $(LOCALOBJ)/*.o 2> /dev/null
	-@rm -f $(LOCALDEP)/*.d 2> /dev/null

#include the Dependency chain for each source file
-include $(DEPS)

#static pattern rule to generate .o files from .c files
$(OBJS): $(LOCALOBJ)/%.o: %.c
	$(CC) $(CCFLAGS) -c -MMD $< -o $@
	mv $(LOCALOBJ)/$(*F).d $(LOCALDEP)/$(*F).d

#static pattern rule to generate .exe files from .o files
$(EXES): $(LOCALBIN)/%.exe: $(LOCALOBJ)/%.o
	$(CC) $(CCFLAGS) $< -o $@
