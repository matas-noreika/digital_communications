#C Compiler
CC= gcc
#C Compiler Flags
CCFLAGS= -I./include/
#Linker Dependency Flags
LDFLAGS= 

#target file of makefile
TARGET=$(LOCALOBJ)/libdivu.a

#Local project directories
LOCALBIN=./bin
LOCALDEP=./dep
LOCALOBJ=./obj
LOCALSRC=./src

#Retrieve all source files
SRCS=$(wildcard $(LOCALSRC)/*.c)
#Retrieve all object file targets from source's
OBJS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALOBJ)/%.o)
#Retrieve all .d files targets from source's
DEPS=$(SRCS:$(LOCALSRC)/%.c=$(LOCALDEP)/%.d)

.PHONY: clean

#Generate object files by default
all: $(TARGET)

#general clean rule to remove any build files
clean:
	-@rm -f $(LOCALBIN)/*.exe 2> /dev/null
	-@rm -f $(LOCALOBJ)/*.o 2> /dev/null
	-@rm -f $(LOCALDEP)/*.d 2> /dev/null
	-@rm -f $(LOCALOBJ)/*.a 2> /dev/null

-include $(DEPS)

#static pattern rule to generate object files from source files
$(LOCALOBJ)/%.o: $(LOCALSRC)/%.c
	$(CC) $(CCFLAGS) -c -MMD $< -o $@
	mv $(LOCALOBJ)/$(*F).d $(LOCALDEP)

#static pattern rule to generate static library .a file
$(LOCALOBJ)/%.a: $(OBJS)
	ar rcs $@ $^
