#C Complier
CC=gcc
#debug flag to enable/disable stdout prints
DEBUG=
#C Compiler flags
ifeq (DEBUG,)
CCFLAGS=-O2 -I./include
else	
CCFLAGS=-g -D DEBUG -O2 -I./include
endif
#linker dependency flags
LDFLAGS=

#local directories
LOCALSRC=./src
LOCALOBJ=./obj
LOCALDEP=./dep
LOCALBIN=./bin
LOCALDATA=./data

#Retrieve source files and build targets
SRCS=$(wildcard $(LOCALSRC)/*.c)
OBJS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALOBJ)/%.o)
DEPS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALOBJ)/%.d)
EXES=$(SRCS:$(LOCALSRC)/%.c=$(LOCALBIN)/%.exe)

#Library dependency configuration

.PHONY: all clean

#build all executables on default make call
all: $(EXES)

clean:
	-@rm -f $(LOCALOBJ)/*.o 2> /dev/null
	-@rm -f $(LOCALOBJ)/*.d 2> /dev/null
	-@rm -f $(LOCALBIN)/*.exe 2> /dev/null
	-@rm -f $(LOCALDATA)/raw/* 2> /dev/null
	-@rm -f $(LOCALDATA)/output/* 2> /dev/null

#static pattern rule for generating object files from source files
$(LOCALOBJ)/%.o: $(LOCALSRC)/%.c
	$(CC) $(CCFLAGS) -c -MMD $< -o $@
	mv $(LOCALOBJ)/$(*F).d $(LOCALDEP)

#static pattern rule to generate executables from object files
$(LOCALBIN)/%.exe: $(LOCALOBJ)/%.o
	$(CC) $(CCFLAGS) $< $(LDFLAGS) -o $@
