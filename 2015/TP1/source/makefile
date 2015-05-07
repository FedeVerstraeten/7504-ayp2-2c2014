CC      = g++
CCFLAGS  = -g -Wall -pedantic
LDFLAGS  =
OBJS = main.o complex.o cmdline.o arguments.o calculation_methods_for_fourier_transform.o
PROGRAM_NAME = tp1

all: tp1
#	@/bin/true

tp1: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROGRAM_NAME)

main.o: main.cc main.h cmdline.h arguments.h calculation_methods_for_fourier_transform.h complex.h types.h
	$(CC) $(CCFLAGS) -c main.cc

complex.o: complex.cc complex.h
	$(CC) $(CCFLAGS) -c complex.cc
	
cmdline.o: cmdline.cc cmdline.h
	$(CC) $(CCFLAGS) -c cmdline.cc
	
arguments.o: arguments.cc arguments.h cmdline.h types.h
	$(CC) $(CCFLAGS) -c arguments.cc
	
calculation_methods_for_fourier_transform.o: calculation_methods_for_fourier_transform.cc calculation_methods_for_fourier_transform.h complex.h
	$(CC) $(CCFLAGS) -c calculation_methods_for_fourier_transform.cc
	
#utilities.o: utilities.cc utilities.h
#	$(CC) $(CCFLAGS) -c utilities.cc

clean:
	rm *.o