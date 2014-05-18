#compilacion y ejecucion de los archivos
CC       =  g++
CFLAGS   = -g -Wall  -pedantic 
OBJS=main_test.o NetworkElementClass.o 


programa.exe:$(OBJS)
	$(CC)  $(OBJS) -o main_test.exe 

main_test.o:main_test.cpp common.hpp 
	$(CC) main_test.cpp -c -o main_test.o $(CFLAGS)
  
NetworkElementClass.o:NetworkElementClass.cpp NetworkElementClass.hpp common.hpp 
	$(CC) NetworkElementClass.cpp -c -o NetworkElementClass.o $(CFLAGS)


clean:
	rm *.o	
