#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   = -g -Wall  -pedantic 
OBJS	 = main_TP1.o file_load.o printers.o process.o dictionary.o arguments.o NetworkElementClass.o 



muestras.exe:$(OBJS)
	$(CC)  $(OBJS) -o main_TP1.exe 

main_TP1.o:main_TP1.cpp dictionary.hpp printers.hpp process.hpp file_load.hpp common.hpp 
	$(CC) main_TP1.cpp -c -o main_TP1.o $(CFLAGS)
  
file_load.o:file_load.cpp file_load.hpp common.hpp 
	$(CC) file_load.cpp -c -o file_load.o $(CFLAGS)

printers.o:printers.cpp printers.hpp common.hpp
	$(CC) printers.cpp -c -o printers.o $(CFLAGS)

process.o:process.cpp process.hpp common.hpp printers.hpp
	$(CC) process.cpp -c -o process.o $(CFLAGS)

arguments.o:arguments.cpp arguments.hpp common.hpp
	$(CC) arguments.cpp -c -o arguments.o $(CFLAGS)

	
dictionary.o:dictionary.cpp dictionary.hpp 
	$(CC) dictionary.cpp -c -o dictionary.o $(CFLAGS)

NetworkElementClass.o:NetworkElementClass.cpp NetworkElementClass.hpp common.hpp 
	$(CC) NetworkElementClass.cpp -c -o NetworkElementClass.o $(CFLAGS)



clean:
	rm *.o	
