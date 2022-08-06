final.exe: Lab6.o MathOps.o
	gcc -o final.exe Lab6.o MathOps.o

Lab6.o: Lab6.c MathOps.h
	gcc -c Lab6.c 

MathOps.o: MathOps.c MathOps.h
	gcc -c MathOps.c 