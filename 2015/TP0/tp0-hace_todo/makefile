CC      = g++
CCFLAGS  = -g -Wall -pedantic
LDFLAGS  =
OBJS = main.o complex.o cmdline.o
PROGRAM_NAME = tp0

all: tp0
#	@/bin/true

tp0: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROGRAM_NAME)

main.o: main.cc complex.h cmdline.h
	$(CC) $(CCFLAGS) -c main.cc

complex.o: complex.cc complex.h
	$(CC) $(CCFLAGS) -c complex.cc
	
cmdline.o: cmdline.cc cmdline.h
	$(CC) $(CCFLAGS) -c cmdline.cc


clean:
	rm *.o