#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   =  -Wall  -pedantic 
OBJS=main_muestra.o file_load.o


muestras.exe:$(OBJS)
	$(CC)  $(OBJS) -o main_muestra.exe 

main_muestra.o:main_muestra.cpp file_load.hpp common.hpp 
	$(CC) main_muestra.cpp -c -o main_muestra.o $(CFLAGS)
  
file_load.o:file_load.cpp file_load.hpp common.hpp 
	$(CC) file_load.cpp -c -o file_load.o $(CFLAGS)

clean:
	rm *.o	
