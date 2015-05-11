#!/bin/bash

# Script de tests automáticos para tp1.

echo Casos de prueba según la especifiación del TP
echo
echo Caso 1
echo "$ cat entrada.txt"
cat entrada.txt
echo "$ ./tp1 < entrada.txt"
./tp1 < entrada.txt
echo "$ ./tp1 -m fft < entrada.txt"
./tp1 -m fft < entrada.txt
echo "$ ./tp1 -m dft < entrada.txt"
./tp1 -m dft < entrada.txt
echo

echo Caso 2
echo "$ cat entrada2.txt"
cat entrada2.txt
echo "$ ./tp1 < entrada2.txt"
./tp1 < entrada2.txt
echo "$ ./tp1 -m fft < entrada2.txt"
./tp1 -m fft < entrada2.txt
echo "$ ./tp1 -m dft < entrada2.txt"
./tp1 -m dft < entrada2.txt
echo

echo Caso 4
echo "$ cat entrada4.txt"
cat entrada4.txt
echo "$ ./tp1 -m ifft < entrada4.txt"
./tp1 -m ifft < entrada4.txt
echo "$ ./tp1 -m idft -o salida4.txt < entrada4.txt"
./tp1 -m idft -o salida4.txt < entrada4.txt
echo "$ cat salida4.txt"
cat salida4.txt
echo
