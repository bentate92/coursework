/* CS261- Assignment 5 - To-do list implementation (toDo.c)*/
/* Name: Benjamin Tate
 * Date: 5/22/2016
 * Description: Implementation of a to-do list application
 *    with a heap-based priority queue 
 */
 
#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
   
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
  /*Assert pre-conditions*/
  assert(list != 0);
  assert(command != 0);

  /*Get input and provide appropriate prompts and function calls*/
  if(command == 'l') {
    //initialize string to hold filename
    char filename[128];

    //prompt for filename
    printf("\nPlease enter the filename: ");
    scanf("%s", filename);  

    //open specified file in read mode
    FILE* file;
    file = fopen(filename, "r");

    //call listLoad()
    listLoad(list, file);
  }
  else if(command =='s') {
    //initialize string to hold filename
    char filename[128];

    //prompt for filename
    printf("\nPlease enter the filename: ");
    scanf("%s", filename);

    //open specified file in write mode
    FILE* file;
    file = fopen(filename, "w");

    //call listSave()
    listSave(list, file);
  }
  else if(command =='a') {
    //initialize variables to hold fields of Task object
    char description[128];
    int priority;

    //prompt for description and priority
    printf("\nPlease enter the task description: ");
    scanf("%128[0-9a-zA-Z ]", description);
    printf("\nPlease enter the task priority (0-999): ");
    scanf("%d", &priority);

    //create new task
    struct Task* newTask = taskNew(priority, description);

    //add newTask to heap
    dyHeapAdd(list, newTask, taskCompare);

    //print confirmation
    printf("\nThe task '%s' has been added to your to-do list.", description);
  }
  else if(command =='g') {
    //initialize string to name of first Task in list 
    char* taskName;
    taskName = ((struct Task*)dyHeapGetMin(list))->name;

    //print task
    printf("\nYour first task is: %s\n\n", taskName);
  }
  else if(command =='r') {
    //initialize string to name of first Task in list 
    char* taskName;
    taskName = ((struct Task*)dyHeapGetMin(list))->name;

    //remove first Task in list
    dyHeapRemoveMin(list, taskCompare);

    //print confirmation
    printf("Your first task, '%s,' has been removed from the list.\n\n", taskName);
  }
  else if(command =='p') {
    //print newline and call listPrint()
    printf("\n");
    listPrint(list);
  }
  else if(command =='e') {
    //print farewell statement
    printf("Goodbye!"); 
  }
  else {
    //if invalid input...
    printf("\nSorry, I didn't quite get that. ");
  }
}

int main()
{
  printf("\n\n** TO-DO LIST APPLICATION **\n\n");
  DynamicArray* list = dyNew(8);
  char command = ' ';
  do
  {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
      );
      command = getchar();
      // Eat newlines
      while(command == '\n') {
        command = getchar();
      }
      while(getchar() != '\n');
      handleCommand(list, command);
  } while (command != 'e');
  dyDelete(list);
  return 0;
}
