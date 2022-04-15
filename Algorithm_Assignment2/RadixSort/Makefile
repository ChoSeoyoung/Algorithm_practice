#
# makefile
#
CC = gcc
INC = -I${CURDIR}
CFLAGS = -g $(INC)

OBJS = radix_sort.o radix_sort_test.o 

SRCS = $(OBJS:.o=.c)

TARGET = RadixSort

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