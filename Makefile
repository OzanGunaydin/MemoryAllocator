GCC=gcc
SRC=src
CFLAGS = -c -Wall -DNDEBUG
OBJECTS = MemTest.o MemAllocator.o
RM = rm -rf

all: default clean

default: $(OBJECTS)
	$(GCC) $(OBJECTS) -o MemTest

%.o: $(SRC)/%.c
	$(GCC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o
