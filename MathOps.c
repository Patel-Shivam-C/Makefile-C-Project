// loadComplex function
// push function
// add function
// subtract function
// divide function
// multiply function
// moveComplex function ( Copy function )
// complecConjugate function

#include <assert.h>
#include "MathOps.h"

// DO NOT CHANGE THIS FUNCTION
extern Complex loadComplex(){
   Complex cTemp; char sign; char i;
    printf("\tEnter complex number as 'a + Bi' (e.g. 3.4 - 27.1i) : ");
    scanf("%lf %c %lf%c", &cTemp.real, &sign, &cTemp.imag, &i);
    if (sign=='-') cTemp.imag = -cTemp.imag;
    fflush(stdin);
    return cTemp;
}

extern Complex push(Complex value){
   if (top == STACK_SIZE - 1){
      // stack[top].real = 0;
      // stack[top].imag = 0;
      top = EMPTY;
      for (int i = 0; i < STACK_SIZE; i++){
         stack[i].real = stack[i+1].real;
         stack[i].imag = stack[i+1].imag;
         top++;
      }
      stack[top].real = value.real;
      stack[top].imag = value.imag;
   }

   top++;
   stack[top].real = value.real;
   stack[top].imag = value.imag;
   return stack[top];
}


extern Complex add(Complex *c) {
   (*(c+((top-1)%STACK_SIZE))).real = (*(c+(top%STACK_SIZE))).real + (*(c+((top-1)%STACK_SIZE))).real;
   (*(c+((top-1)%STACK_SIZE))).imag = (*(c+(top%STACK_SIZE))).imag + (*(c+((top-1)%STACK_SIZE))).imag;
   (*(c+(top%STACK_SIZE))).imag = 0;
   (*(c+(top%STACK_SIZE))).real = 0;
   top--;
   return *(c+((top-1)%STACK_SIZE));
}

extern Complex subtract(Complex *c) {
   (*(c+((top-1)%STACK_SIZE))).real = (*(c+(top%STACK_SIZE))).real - (*(c+((top-1)%STACK_SIZE))).real;
   (*(c+((top-1)%STACK_SIZE))).imag = (*(c+(top%STACK_SIZE))).imag - (*(c+((top-1)%STACK_SIZE))).imag;
   (*(c+(top%STACK_SIZE))).imag = 0;
   (*(c+(top%STACK_SIZE))).real = 0;
   top--;
   return *(c+((top-1)%STACK_SIZE));
}

extern Complex divide(Complex *c) {
   double denominator = ((*(c+(top%STACK_SIZE))).real * (*(c+(top%STACK_SIZE))).real) + ((*(c+(top%STACK_SIZE))).imag * (*(c+(top%STACK_SIZE))).imag);
   assert(denominator != 0 && "Denominator should not be zero");
   (*(c+((top-1)%STACK_SIZE))).real = (((*(c+(top%STACK_SIZE))).real * (*(c+((top-1)%STACK_SIZE))).real) + ((*(c+(top%STACK_SIZE))).imag * (*(c+((top-1)%STACK_SIZE))).imag))/denominator;
   (*(c+((top-1)%STACK_SIZE))).imag = (double) (((*(c+((top-1)%STACK_SIZE))).real * (*(c+(top%STACK_SIZE))).imag) - ((*(c+(top%STACK_SIZE))).real * (*(c+((top-1)%STACK_SIZE))).imag))/denominator;
   (*(c+(top%STACK_SIZE))).imag = 0;
   (*(c+(top%STACK_SIZE))).real = 0;
   top--;
   return *(c+((top-1)%STACK_SIZE));
}

extern Complex multiply(Complex *c) {
   (*(c+((top-1)%STACK_SIZE))).real = ((*(c+(top%STACK_SIZE))).real*(*(c+((top-1)%STACK_SIZE))).real) - ((*(c+(top%STACK_SIZE))).imag*(*(c+((top-1)%STACK_SIZE))).imag);
   (*(c+((top-1)%STACK_SIZE))).imag = ((*(c+(top%STACK_SIZE))).real*(*(c+((top-1)%STACK_SIZE))).imag) + ((*(c+((top-1)%STACK_SIZE))).real*(*(c+(top%STACK_SIZE))).imag);
   (*(c+(top%STACK_SIZE))).imag = 0;
   (*(c+(top%STACK_SIZE))).real = 0;
   top--;
   return *(c+((top-1)%STACK_SIZE));
}

extern Complex moveComplex(Complex *c){
   Complex result;
   result.real = (*(c+((top)%STACK_SIZE))).real;
   result.imag = (*(c+((top)%STACK_SIZE))).imag;
   push(result);
   return result;
}

extern Complex complexConjugate(Complex *c){
   Complex result;
   (*(c+(top%STACK_SIZE))).real = (*(c+(top%STACK_SIZE))).real;
   (*(c+(top%STACK_SIZE))).imag = -1 * (*(c+(top%STACK_SIZE))).imag;
   return result;
}