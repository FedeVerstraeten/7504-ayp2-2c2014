# ------------------------------------------------------------------------- #
# Facultad de Ingeniería de la Universidad de Buenos Aires
# Algoritmos y Programación II
# 1° Cuatrimestre de 2015
# Trabajo Práctico 0: Programación en C++
# Demodulación de señal FM
# 
# makefile
# ------------------------------------------------------------------------- #

CC      = g++
CCFLAGS  = -g -Wall -pedantic
LDFLAGS  =
OBJS = main.o complex.o cmdline.o arguments.o utilities.o
PROGRAM_NAME = tp0

all: tp0
# Esto está comentado porq no tengo claro para que sirve, alguien sabe?
#	@/bin/true

tp0: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROGRAM_NAME)

main.o: main.cc main.h complex.h cmdline.h types.h
	$(CC) $(CCFLAGS) -c main.cc

complex.o: complex.cc complex.h types.h
	$(CC) $(CCFLAGS) -c complex.cc
	
cmdline.o: cmdline.cc cmdline.h
	$(CC) $(CCFLAGS) -c cmdline.cc
	
arguments.o: arguments.cc arguments.h types.h
	$(CC) $(CCFLAGS) -c arguments.cc
	
utilities.o: utilities.cc utilities.h
	$(CC) $(CCFLAGS) -c utilities.cc

clean:
	rm *.o
