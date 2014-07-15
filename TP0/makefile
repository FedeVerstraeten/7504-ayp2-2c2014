#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   =  -Wall  -pedantic 
OBJS=main_muestra_V2.o file_load.o printers.o process.o dictionary.o arguments.o 


muestras.exe:$(OBJS)
	$(CC)  $(OBJS) -o main_muestra_V2.exe 

main_muestra_V2.o:main_muestra_V2.cpp dictionary.hpp printers.hpp process.hpp file_load.hpp common.hpp 
	$(CC) main_muestra_V2.cpp -c -o main_muestra_V2.o $(CFLAGS)
  
file_load.o:file_load.cpp file_load.hpp common.hpp 
	$(CC) file_load.cpp -c -o file_load.o $(CFLAGS)

printers.o:printers.cpp printers.hpp common.hpp
	$(CC) printers.cpp -c -o printers.o $(CFLAGS)

process.o:process.cpp process.hpp common.hpp
	$(CC) process.cpp -c -o process.o $(CFLAGS)

arguments.o:arguments.cpp arguments.hpp common.hpp
	$(CC) arguments.cpp -c -o arguments.o $(CFLAGS)

	
dictionary.o:dictionary.cpp dictionary.hpp common.hpp

file_load.o:file_load.cpp file_load.hpp common.hpp 
	$(CC) file_load.cpp -c -o file_load.o $(CFLAGS)

clean:
	rm *.o	
