/* CS261- Assignment 1 - Q.0*/
/* Name: Benjamin Tate
 * Date: 4/10/2016
 * Solution description: This program really just comes down to 
 *   proper use of the * and & operators
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr) {
  /*Print the value pointed to by iptr*/
  printf("\nThe value pointed to by iptr is %d.\n", *iptr);

  /*Print the address pointed to by iptr*/
  printf("\nThe address pointed to by iptr is %p.\n", iptr);
  
  /*Print the address of iptr itself*/
  printf("\nThe address of iptr is %p.\n", &iptr);
}

int main(){
  /*declare an integer x*/    
  int x = 17;

  /*print the address of x*/
  printf("\nThe memory address of x is %p.\n", &x);  

  /*Call fooA() with the address of x*/
  fooA(&x);
  
  /*print the value of x*/
  printf("\nThe value of x is %d.\n", x);

  return 0;
}
