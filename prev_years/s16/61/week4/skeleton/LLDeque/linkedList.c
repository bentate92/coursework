#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	list->frontSentinel = malloc(sizeof(struct Link));
  assert(list->frontSentinel != 0);
  list->backSentinel = malloc(sizeof(struct Link));
  assert(list->backSentinel != 0);

  list->frontSentinel->next = list->backSentinel;
  list->backSentinel->prev = list->frontSentinel;

  list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
  struct Link* addition = malloc(sizeof(struct Link));

  addition->value = value;

  addition->next = link;
  addition->prev = link->prev;
  addition->next->prev = addition;
  addition->prev->next = addition;

  list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
  link->next->prev = link->prev;
  link->prev->next = link->next;

  free(link);

  list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void linkedListDestroy(struct LinkedList* list)
{
	struct Link* link = list->frontSentinel->next;
	while (link != list->backSentinel)
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
  struct Link* addition = malloc(sizeof(struct Link));

  addition->value = value;

  addition->next = list->frontSentinel->next;
  addition->prev = list->frontSentinel;
  addition->next->prev = addition;
  addition->prev->next = addition;

  list->size++;
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	struct Link* addition = malloc(sizeof(struct Link));
  
  addition->value = value;

  addition->next = list->backSentinel;
  addition->prev = list->backSentinel->prev;
  addition->next->prev = addition;
  addition->prev->next = addition;

  list->size++;
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
  TYPE frontVal = list->frontSentinel->next->value;
  
  return frontVal;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
  TYPE backVal = list->backSentinel->prev->value;
  
  return backVal;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
  assert(!linkedListIsEmpty(list));

  removeLink(list, list->frontSentinel->next);

  list->size--;
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
  assert(!linkedListIsEmpty(list));

  removeLink(list, list->backSentinel->prev);

  list->size--;
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
  int empty;

  if(list->size > 0) {
    empty = 0;
  }
  else {
    empty = 1;
  }

  return empty;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
  struct Link* current = malloc(sizeof(struct Link));
  current = list->frontSentinel->next;

  printf("\nHere are the values in the list currently:\n");  

  while(current != list->backSentinel) {
    printf("%d\n", current->value);

    current = current->next;
  }
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
  linkedListAddFront(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	int contains = 0;

  struct Link* current = malloc(sizeof(struct Link));
  current = list->frontSentinel->next;

  while(current != list->backSentinel) {
    if(current->value == value) {
      contains = 1;

      break;
    }
  
    current = current->next;
  }

  return contains;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
  if(!linkedListContains(list, value)) {
    printf("\nError: value not found.\n");
  }
  else {
    struct Link* current = malloc(sizeof(struct Link));
    current = list->frontSentinel->next;
  
    while(current != list->backSentinel) {
      if(current->value == value) {
        removeLink(list, current);
  
        break;
      }
    
      current = current->next;
    }
  }
}
