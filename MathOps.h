#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 4
#define EMPTY  (-1)

typedef struct {
   double real; 
   double imag; 
} Complex;

extern int top;
Complex stack[STACK_SIZE];
extern Complex *head;

// static void executeMenuItem(int menuItem);
// static int  displayMenu();
// static char display();

extern Complex loadComplex();
extern Complex add(Complex*);
extern Complex push(Complex);
extern Complex subtract(Complex*);
extern Complex multiply(Complex*);
extern Complex divide(Complex*);
extern Complex complexConjugate(Complex*);
extern Complex moveComplex(Complex*);