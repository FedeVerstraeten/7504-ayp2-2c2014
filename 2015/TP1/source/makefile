CC      = g++
CCFLAGS  = -g -Wall -pedantic
LDFLAGS  =
OBJS = main.o complex.o cmdline.o arguments.o dft_methods.o utilities.o
PROGRAM_NAME = tp1

all: tp1
#	@/bin/true

tp1: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROGRAM_NAME)

main.o: main.cc cmdline.h arguments.h complex.h vector.h dft_methods.h utilities.h types.h
	$(CC) $(CCFLAGS) -c main.cc

complex.o: complex.cc complex.h
	$(CC) $(CCFLAGS) -c complex.cc
	
cmdline.o: cmdline.cc cmdline.h
	$(CC) $(CCFLAGS) -c cmdline.cc
	
arguments.o: arguments.cc arguments.h cmdline.h types.h
	$(CC) $(CCFLAGS) -c arguments.cc
	
dft_methods.o: dft_methods.cc dft_methods.h complex.h vector.h utilities.h
	$(CC) $(CCFLAGS) -c dft_methods.cc

utilities.o: utilities.cc utilities.h complex.h vector.h
	$(CC) $(CCFLAGS) -c utilities.cc

clean:
	rm *.o
