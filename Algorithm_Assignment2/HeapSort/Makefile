#
# makefile
#
CC = gcc
INC = -I${CURDIR}
CFLAGS = -g $(INC)

OBJS = heap_sort.o heap_sort_test.o 

SRCS = $(OBJS:.o=.c)

TARGET = HeapSort

.SUFFIXES : .c .o

.c.o:
	@echo "Compiling $< ..."
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

all : $(TARGET)

dep : 
	gccmaedep $(INC) $(SRCS)

clean :
	@echo "Cleaning $< ..."
	rm $(OBJS) $(TARGET) 

new :
	$(MAKE) clean
	$(MAKE)