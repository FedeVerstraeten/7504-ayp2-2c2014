#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   = -g -Wall  -pedantic 
OBJS	 = main.o TableHash.o



muestras.exe:$(OBJS)
	$(CC)  $(OBJS) -o main.exe 

main.o:main.cpp TableHash.hpp NodeTable.hpp TypeElement.hpp
	$(CC) main.cpp -c -o main.o $(CFLAGS)
  
TableHash.o:TableHash.hpp TableHash.cpp common.hpp NodeTable.hpp TypeElement.hpp
	$(CC) TableHash.cpp -c -o TableHash.o $(CFLAGS)

clean:
	rm *.o	
