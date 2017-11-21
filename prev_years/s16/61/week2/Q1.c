/* CS261- Assignment 1 - Q.1*/
/* Name: Benjamin Tate
 * Date: 4/10/2016
 * Solution description: For allocate(), all that was needed was to use malloc() to 
 *   allocate enough space for 10 student structs. 
 *   For generate(), I had to iterate through the array and add a random score from 
 *   0-100 to the current student. To avoid repeats, I used an int, repeat, which 
 *   would be assigned 1 if a repeat id was found and 0 if not. This way, I could 
 *   just iterate through all previous values of the array, and reassign tempID and 
 *   start the loop over if a matching id was found. After the loop was successfully 
 *   completed with no repeats found, tempID would be assigned to the current 
 *   student's id.
 *   output() was just a matter of arranging print statements to make a nice looking
 *   table of ids and scores.
 *   For summary(), I just iterated through each student in the array, added their
 *   score to sum, and then compared their score against the previous min and max
 *   to determine if it should replace the current value. After the loop completed,
 *   the program divides sum by 10 to get the average, and prints min, max, and avg.
 *   Lastly, deallocate() simply frees the array memory if the array is not NULL.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate() {
  /*Allocate memory for ten students*/
  struct student* students;
  students = malloc(10 * sizeof(struct student));

  /*return the pointer*/
  return students;
}

void generate(struct student* students){
  /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
  for(int i = 0; i < 10; i++ ) {
    students[i].score = rand() % 101;
    
    int tempID = rand() % 10 + 1;

    int repeat = 1;

    while(repeat == 1) {
      for(int j = 0; j <= i; j++) {
        if(students[j].id == tempID) {
          tempID = rand() % 10 + 1;
        
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
}

void output(struct student* students){
  /*Output information about the ten students in the format:
           ID1 Score1
           ID2 score2
           ID3 score3
           ...
           ID10 score10*/
  printf("ID Score\n");
  
  for(int i = 0; i < 10; i++) {
    if(students[i].id == 10) {
      printf("%d %d \n", students[i].id, students[i].score);
    }
    else {
      printf("0%d %d \n", students[i].id, students[i].score);
    } 
  }
}

void summary(struct student* students){
  /*Compute and print the minimum, maximum and average scores of the ten students*/
  int min;
  int max;
  int sum;
  int avg;

  for(int i = 0; i < 10; i++) {
    sum += students[i].score;
  
    if(i == 0) {
      min = students[i].score;
      max = students[i].score;
    }
    else {
      if(students[i].score < min) {
        min = students[i].score;
      }
      if(students[i].score > max) {
        max = students[i].score;
      }
    }
  }

  avg = sum / 10;

  printf("\nLow score:     %d \n", min);
  printf("High score:    %d \n", max);
  printf("Average score: %d \n \n", avg);
}

void deallocate(struct student* stud){
  /*Deallocate memory from stud*/
  if(stud != 0) {
    free(stud);
  }
}

int main(){
  struct student* stud;
  
  /*call allocate*/
  stud = allocate();
  
  /*call generate*/
  generate(stud);

  /*call output*/
  output(stud);

  /*call summary*/
  summary(stud);

  /*call deallocate*/
  deallocate(stud);

  return 0;
}
