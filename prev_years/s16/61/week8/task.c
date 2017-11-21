/* CS261- Assignment 5 - To-do list implementation (task.c)*/
/* Name: Benjamin Tate
 * Date: 5/22/2016
 * Description: Implementation of a task structure that will
 *    be used with the to-do list 
 */
 
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
  /*Allocate memory for new Task struct*/
  struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
  assert(newTask != 0);

  snprintf(newTask->name, sizeof(newTask->name), "%s", name);
  newTask->priority = priority;

  return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
  // FIXME: implement

  /*Initialize ints to hold priorities of left and right Tasks*/
  int leftNum = ((struct Task*)left)->priority;
  int rightNum = ((struct Task*)right)->priority;

  /*Compare and return as appropriate*/
  if(leftNum < rightNum) {
    return -1;
  }
  else if(leftNum > rightNum) {
    return 1;
  }
  else {
    return 0;
  }
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
