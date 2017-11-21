/* CS261- Assignment 1 - Q.3*/
/* Name: Benjamin Tate
 * Date: 4/10/2016
 * Solution description: This program uses a simple bubble sort algorithm to sort an
 *   array of 20 ints. The algorithm works by iterating through each element of the
 *   array except the last, and then compares said elements' values to all other 
 *   elements that remain unsorted, moving them towards the end of the array if they
 *   are larger than the next element.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
  /*Sort the given array number , of length n*/     
  int temp;

  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < 19 - i; j++) {
      if(number[j] > number[j + 1]) {
        temp = number[j + 1];
        number[j + 1] = number[j];
        number[j] = temp;
      }
    }
  }
}

int main(){
  /*Declare an integer n and assign it a value of 20.*/
  int n = 20;

  /*Allocate memory for an array of n integers using malloc.*/
  int* array;
  array = malloc(20 * sizeof(int));

  /*Fill this array with random numbers, using rand().*/
  for(int i = 0; i < 20; i++) {
    array[i] = rand() % 101;
  }

  /*Print the contents of the array.*/
  printf("Unsorted:\n");
  for(int i = 0; i < 20; i++) {
    printf("%d \n", array[i]);
  }

  /*Pass this array along with n to the sort() function of part a.*/
  sort(array, n);

  /*Print the contents of the array.*/    
  printf("\nSorted:\n");
  for(int i = 0; i < 20; i++) {
    printf("%d \n", array[i]);
  }

  return 0;
}
