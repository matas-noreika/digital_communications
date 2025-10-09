#C Compiler
CC= gcc
#C Compiler Flags
CCFLAGS= -I./include $(LIBINCS)
#Linker Dependency Flags
LDFLAGS= $(LDLIBS) $(LIBS)

#Local Directories
LOCALBIN=./bin
LOCALOBJ=./obj
LOCALDEP=./dep
LOCALSRC=./src
LOCALLIB=./lib

#retrieve all libs
LIBDIRS:=$(wildcard $(LOCALLIB)/*)
#retrieve all include Directories from libs
LIBINCS:=$(LIBDIRS:%=-I%/include)
#retrieve all obj Directories from libs
LDLIBS:=$(LIBDIRS:%=-L%/obj)
#retrieve all static libraries from libs
LIBS:=$(LIBDIRS:$(LOCALLIB)/%=-l%)

#Build target files
SRCS=$(wildcard $(LOCALSRC)/*.c)
OBJS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALOBJ)/%.o)
DEPS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALDEP)/%.d)
EXES=$(SRCS:$(LOCALSRC)/%.c=$(LOCALBIN)/%.exe)

.PHONY: clean

#general make all rule
all: BUILDLIBS $(EXES)

#general clean rule
clean:
	-@rm -f $(LOCALBIN)/*.exe 2> /dev/null
	-@rm -f $(LOCALOBJ)/*.o 2> /dev/null
	-@rm -f $(LOCALDEP)/*.d 2> /dev/null
	-@rm -f *.divu 2> /dev/null
	-@rm -f $(LOCALBIN)/*.divu 2> /dev/null

#include the Dependency chain for each source file
-include $(DEPS)

BUILDLIBS: $(LIBDIRS)
	$(MAKE) -C $<

#static pattern rule to generate .o files from .c files
$(LOCALOBJ)/%.o: $(LOCALSRC)/%.c
	$(CC) $(CCFLAGS) -c -MMD $< -o $@
	mv $(LOCALOBJ)/$(*F).d $(LOCALDEP)/$(*F).d

#static pattern rule to generate .exe files from .o files
$(LOCALBIN)/%.exe: $(LOCALOBJ)/%.o
	$(CC) $(CCFLAGS) $(LDFLAGS) $< -o $@
