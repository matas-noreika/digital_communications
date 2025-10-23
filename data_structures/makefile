#C Complier
CC= gcc
#C Complier Flags
CCFLAGS=-I./include

#Local Directories
LOCALSRC=./src
LOCALBIN=./bin
LOCALOBJ=./obj
LOCALDEP=./dep

#Source and target files
SRCS=$(wildcard $(LOCALSRC)/*.c)
OBJS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALOBJ)/%.o)
DEPS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALOBJ)/%.d)
EXES=$(LOCALBIN)/application.exe

#rules that do not require prequisites to be updated
.PHONY:all clean build

#define intermeditate files as precious
.PRECIOUS:

all:
	@echo 'List of available commands:'
	@echo "build -> generates all executables includes tests, static libraries etc"
	@echo 'clean -> removes all generated files including any outputs from scripts provided'

build: $(EXES)

clean:
	-@rm -f $(LOCALBIN)/*.exe 2> /dev/null
	-@rm -f $(LOCALOBJ)/*.o 2> /dev/null
	-@rm -f $(LOCALDEP)/*.d 2> /dev/null

#include dep files to rule chain
-include $(DEPS)

#static pattern rule to generate object files from source files
$(LOCALOBJ)/%.o: $(LOCALSRC)/%.c
	$(CC) $(CCFLAGS) -c -MMD $< -o $@
	mv $(LOCALOBJ)/$(*F).d $(LOCALDEP)

#static pattern rule to generate executables from object files
$(LOCALBIN)/%.exe: $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $@
