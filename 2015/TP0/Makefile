#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   = -g -Wall  -pedantic 
OBJS	 = main.o  cmdline.o options.o complex.o



muestras.exe:$(OBJS)
	$(CC)  $(OBJS) -o main.exe 

main.o:main.cc common.hpp cmdline.h options.hpp
	$(CC) main.cc -c -o main.o $(CFLAGS)

cmdline.o: cmdline.cc cmdline.h 
	$(CC)  cmdline.cc -c -o cmdline.o $(CFLAGS)

options.o: options.cpp options.hpp
	$(CC)  options.cpp -c -o options.o $(CFLAGS)

complex.o: complex.cpp complex.h
	$(CC)  complex.cpp -c -o complex.o $(CFLAGS)

clean:
	rm *.o
