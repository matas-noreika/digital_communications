#C Compiler
CC= gcc
DEBUG=
#C Compiler Flags
ifeq ($(DEBUG),)
CCFLAGS= -I./include $(LIBINCS)
else
CCFLAGS= -g -D DEBUG -I./include $(LIBINCS)
DEBUGPASS=DEBUG=1
endif

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
	-@rm -f ./data/output/*.divu 2> /dev/null
	-@rm -f $(LOCALBIN)/*.divu 2> /dev/null
	for lib in $(LIBDIRS); do $(MAKE) -C $$lib clean; done
#include the Dependency chain for each source file
-include $(DEPS)

BUILDLIBS: $(LIBDIRS)
	$(MAKE) -C $< $(DEBUGPASS)

#static pattern rule to generate .o files from .c files
$(LOCALOBJ)/%.o: $(LOCALSRC)/%.c
	$(CC) $(CCFLAGS) -c -MMD $< -o $@
	mv $(LOCALOBJ)/$(*F).d $(LOCALDEP)/$(*F).d

#static pattern rule to generate .exe files from .o files
$(LOCALBIN)/%.exe: $(LOCALOBJ)/%.o
	$(CC) $(CCFLAGS) -o $@ $< $(LDFLAGS)
