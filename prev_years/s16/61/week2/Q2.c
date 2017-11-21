/* CS261- Assignment 1 - Q.2*/
/* Name: Benjamin Tate
 * Date: 4/10/2016
 * Solution description: As with Q0, this was a basically just a matter of using
 * the * and & operators appropriately. The value of z is not changed by foo(),
 * because it is passed to foo() directly, meaning that alterations to c are 
 * confined to inside the foo() function.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
  /*Set a to double its original value*/
  *a = *a * 2;
  
  /*Set b to half its original value*/
  *b = *b / 2;
  
  /*Assign a+b to c*/
  c = *a + *b;
  
  /*Return c*/
  return c;
}

int main(){
  /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
  int x = 5;
  int y = 6;
  int z = 7;
  
  /*Print the values of x, y and z*/
  printf("\nx = %d \n", x);
  printf("\ny = %d \n", y);
  printf("\nz = %d \n", z);
  
  /*Call foo() appropriately, passing x,y,z as parameters*/
  int ret = foo(&x, &y, z);
  
  /*Print the value returned by foo*/
  printf("\nfoo() returns the value %d.\n", ret);

  /*Print the values of x, y and z again*/
  printf("\nx = %d \n", x);
  printf("\ny = %d \n", y);
  printf("\nz = %d \n", z);


  /*Is the return value different than the value of z?  Why?*/
  /**
   * The return value is different from the final value of z, because z is passed
   * to foo() by value, rather than by reference, meaning that c, the value 
   * returned by foo(), is its own integer, rather than a pointer to z, like how
   * a and b are just pointers to x and y. This means that operations on a and b
   * actually affect x and y outside of foo(), while operations on c do not affect
   * z.
   **/

  return 0;
}
    
    
