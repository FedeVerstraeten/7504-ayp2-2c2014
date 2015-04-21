#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   = -g -Wall  -pedantic 
OBJS	 = main.o  cmdline.o options.o complex.o
PROGRAM_NAME = main.exe

all: main.exe
#	@/bin/true

main.exe: $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM_NAME)

main.o:main.cc common.hpp cmdline.h options.hpp
	$(CC) main.cc -c -o main.o $(CFLAGS)

cmdline.o: cmdline.cc cmdline.h 
	$(CC)  cmdline.cc -c -o cmdline.o $(CFLAGS)

options.o: options.cpp options.hpp
	$(CC)  options.cpp -c -o options.o $(CFLAGS)

complex.o: complex.cc complex.h
	$(CC)  complex.cc -c -o complex.o $(CFLAGS)

#test: test1
#	@set -e; for t in test?; do              \
#	  echo testing: $$t.;                    \
#	  ./$$t <$$t.in >$$t.t;                  \
#	  diff -b $$t.ref $$t.t >/dev/null 2>&1; \
#	done
#	@echo test ok.

#test-valgrind: test1
#	@set -e; for t in test?; do                                  \
#	  echo testing: $$t.;                                        \
#	  valgrind --tool=memcheck ./$$t <$$t.in >$$t.t 2>/dev/null; \
#	  diff -b $$t.ref $$t.t >/dev/null 2>&1;                     \
#	done
#	@echo test ok.

clean:
	rm *.o
#	rm -f *.o *.t core test?
