/* CS261- Assignment 1 - Q.4*/
/* Name: Benjamin Tate
 * Date: 4/10/2016
 * Solution description: As the assignment says, this program is simply an adaptation
 *   of code from Q1.c for allocation, generation, and display of students and Q3.c
 *   for sorting of those students by scores.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
  /*Sort the n students based on their score*/     
  struct student tempStudent;

  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - 1 - i; j++) {
      if(students[j].score > students[j + 1].score) {
        tempStudent = students[j + 1];
        students[j + 1] = students[j];
        students[j] = tempStudent;
      }
    }
  }
}

int main(){
  /*Declare an integer n and assign it a value.*/
  int n = 10;
  
  /*Allocate memory for n students using malloc.*/
  struct student* students;
  students = malloc(n * sizeof(struct student));
  
  /*Generate random IDs and scores for the n students, using rand().*/
  for(int i = 0; i < n; i++ ) {
    students[i].score = rand() % 101;
    
    int tempID = rand() % n + 1;

    int repeat = 1;

    while(repeat == 1) {
      for(int j = 0; j <= i; j++) {
        if(students[j].id == tempID) {
          tempID = rand() % n + 1;
        
          repeat = 1;

          break;
        }
        else {
          repeat = 0;
        }
      }
    }

    students[i].id = tempID;
  }
  
  /*Print the contents of the array of n students.*/
  printf("Unsorted student list:\n");
  printf("ID Score\n");
  
  for(int i = 0; i < n; i++) {
    if(students[i].id >= 10) {
      printf("%d %d \n", students[i].id, students[i].score);
    }
    else {
      printf("0%d %d \n", students[i].id, students[i].score);
    } 
  }

  /*Pass this array along with n to the sort() function*/
  sort(students, n); 
 
  /*Print the contents of the array of n students.*/
  printf("\nSorted student list:\n");
  printf("ID Score\n");
  
  for(int i = 0; i < n; i++) {
    if(students[i].id >= 10) {
      printf("%d %d \n", students[i].id, students[i].score);
    }
    else {
      printf("0%d %d \n", students[i].id, students[i].score);
    } 
  }
  
  return 0;
}
