/* CS261- Assignment 2 - Stack implementation (stackapp.c)*/
/* Name: Benjamin Tate
 * Date: 4/17/2016
 * Description: Program checks whether a string's parentheses,
 *   square brackets, and curly braces are balanced.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s) {
  /*Declare new DynArr struct and initialize with an array size of 1*/
  DynArr* stack;
  stack = newDynArr(1);

  /*Declare int to contain 0 when unbalanced or 1 if balanced*/
  int balanced;

  /*Declare char using nextChar()*/
  char c = nextChar(s); 

  /*Loop until end of string is reached*/
  while(c != '\0') {
    /*If the current char is an opener, add it to the stack*/
    if(c == '(' || c == '[' || c == '{') {
      pushDynArr(stack, c);
    }
    /*If the current char is a closer...*/
    else if(c == ')' || c == ']' || c == '}') {
      /*If stack is empty, set balanced to 0 and break loop*/
      if(isEmptyDynArr(stack)) {
          balanced = 0;

          break;
      }
      /*If top of stack does not complement c, set balanced to 0 and break loop*/
      else if((c == ')' && topDynArr(stack) != '(') || 
              (c == ']' && topDynArr(stack) != '[') || 
              (c == '}' && topDynArr(stack) != '{')) {
          balanced = 0;

          break;
      }
      /*If top of stack complements c, pop from stack*/
      else {
        popDynArr(stack);

        /*Set balanced to 1*/
        balanced = 1;
      }
    }

    /*If stack is not empty after loop, set balanced to 0*/
    if(!isEmptyDynArr(stack)) {
      balanced = 0;
    }

    /*Shift c to next character in the string using nextChar()*/
    c = nextChar(s);
  }

  return balanced;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

