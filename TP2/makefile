#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   = -g -Wall  -pedantic 
OBJS	 = main.o  printers.o process.o dictionary.o  NetworkElementClass.o cmdline.o options.o 



muestras.exe:$(OBJS)
	$(CC)  $(OBJS) -o main.exe 

main.o:main.cpp dictionary.hpp printers.hpp process.hpp  common.hpp cmdline.h options.hpp NetworkElementClass.hpp
	$(CC) main.cpp -c -o main.o $(CFLAGS)
  
printers.o:printers.cpp printers.hpp common.hpp
	$(CC) printers.cpp -c -o printers.o $(CFLAGS)

dictionary.o:dictionary.cpp dictionary.hpp cmdline.h  options.hpp
	$(CC) dictionary.cpp -c -o dictionary.o $(CFLAGS)

process.o:process.cpp process.hpp dictionary.hpp common.hpp printers.hpp
	$(CC) process.cpp -c -o process.o $(CFLAGS)

NetworkElementClass.o:NetworkElementClass.cpp NetworkElementClass.hpp common.hpp 
	$(CC) NetworkElementClass.cpp -c -o NetworkElementClass.o $(CFLAGS)

cmdline.o: cmdline.cc cmdline.h 
	$(CC)  cmdline.cc -c -o cmdline.o $(CFLAGS)

options.: options.cpp options.hpp
	$(CC)  options.cpp -c -o options.o $(CFLAGS)




clean:
	rm *.o	
