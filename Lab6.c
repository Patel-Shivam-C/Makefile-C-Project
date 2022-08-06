/* Revision 1.1.  loadComplex() changed, to return Complex structure */

// main funcition
// displayMenu function
// executeMenuItem function
// display function

#include <stdbool.h>

#define Exit 0
#define Load 1
#define Display 2
#define Move 3
#define Conjugate 4
#define Add 5
#define Subtract 6
#define Multiply 7
#define Divide 8

#define STACK_EMPTY INT_MIN
#define PROMPT_USER_TO(menuItem) printf("%d. %s complex numbers\n", menuItem, #menuItem);


#include "MathOps.h"

int top = EMPTY;
Complex *head = stack;
void executeMenuItem(int menuItem);
int  displayMenu();
char display();

int main(void){   
   int choice = Exit;
   printf("Welcome to the complex number calculator\n\n");
   do{
      choice = displayMenu();
	   executeMenuItem(choice);
   } while (choice != Exit);

   printf("Program exited\n");
   exit(EXIT_SUCCESS);
}

// display menu options, prompt the user to enter a choice, and return the value selected
// DO NOT CHANGE THIS FUNCTION
int displayMenu(){  
    int input = Exit;
    printf("Select one of the following:\n\n");
    PROMPT_USER_TO(Load)
    PROMPT_USER_TO(Display)
    PROMPT_USER_TO(Move)
    PROMPT_USER_TO(Conjugate)
    PROMPT_USER_TO(Add)
    PROMPT_USER_TO(Subtract)
    PROMPT_USER_TO(Multiply)
    PROMPT_USER_TO(Divide)
    printf("%d. Exit Program\n", Exit);
    scanf("%d", &input);
    return input;
}

// DO NOT CHANGE THIS FUNCTION
void executeMenuItem(int menuItem){
   Complex c = {0,0};  
   static Complex c0 = {0,0}, c1 = {0,0}, cResult = {0,0};

   switch (menuItem) {

         case Exit: break; 

         case Load:
            // push(loadComplex());
            top++;
            // if (top > 4){
            //    for (int i = 0; i < STACK_SIZE; i++){
            //       stack[i].real = stack[i+1].real;
            //       stack[i].imag = stack[i+1].imag;
            //    }
            //    top = 4;
            //    *(head+(top%STACK_SIZE)) = loadComplex();
            // }
            *(head+(top%STACK_SIZE)) = loadComplex();
            // head++;
            // push(*head);
            // head = stack+((head-stack)%STACK_SIZE);
            break;

         case Display:
            // c = chooseComplexNumberTo("display")?c1:c0;
            display();
            break;  

         case Move:
            // c = chooseComplexNumberTo("Move")?(c1 = moveComplex(&cResult)):(c0 = moveComplex(&cResult));
            moveComplex(stack);
            break; 

         case Conjugate:
            // c = chooseComplexNumberTo("Conjugate")?(c1 = complexConjugate(&c1)):(c0 = complexConjugate(&c0));
            complexConjugate(stack);
            break;

         case Add:
            // cResult = add(&c1, &c0);
            add(stack);
            break;      

         case Subtract:
            // cResult = subtract(&c1, &c0);
            subtract(stack);
            break;

         case Multiply:
            // cResult = multiply(&c1, &c0);
            multiply(stack);
            break;

         case Divide:
            // cResult = divide(&c1, &c0); 
            divide(stack);
            break;        

         default:
            printf("Bad menu value entered; ");
      }
      printf("\n");
}

// TODO: add all additional funtions here, as specified above in the executeMenuItem() method.
char display(){
   
   // int index = top;
   for (int i = 0; i < STACK_SIZE; i++){
      if ((*(stack+(i%STACK_SIZE))).imag < 0){
         printf("Index = %i\t%lf - %lfi\n", i, (*(stack+(i%STACK_SIZE))).real, (-1 * (*(stack+(i%STACK_SIZE))).imag));
      }else{
         printf("Index = %i\t%lf + %lfi\n", i, (*(stack+(i%STACK_SIZE))).real, (*(stack+(i%STACK_SIZE))).imag);
      }
      // index++;
   }
}