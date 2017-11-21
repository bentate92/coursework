/* CS261- Assignment 5 - Heap implementation (dynamicArray.c)*/
/* Name: Benjamin Tate
 * Date: 5/22/2016
 * Description: Implementation of a heap data structure 
 */
 
#include "dynamicArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TESTING

#ifndef TESTING
static void adjustHeap(DynamicArray* heap, int last, int position, compareFunction compare);
static void buildHeap(DynamicArray* heap, compareFunction compare);
#endif

struct DynamicArray
{
    TYPE* data;
    int size;
    int capacity;
};

// --- Dynamic array ---

static void setCapacity(DynamicArray* array, int capacity)
{
    TYPE* data = malloc(sizeof(TYPE) * capacity);
    for (int i = 0; i < array->size; i++)
    {
        data[i] = array->data[i];
    }
    free(array->data);
    array->data = data;
    array->capacity = capacity;
}

static void init(DynamicArray* array, int capacity)
{
    assert(capacity > 0);
    array->data = NULL;
    array->size = 0;
    setCapacity(array, capacity);
}

DynamicArray* dyNew(int capacity)
{
    DynamicArray* array = malloc(sizeof(DynamicArray));
    init(array, capacity);
    return array;
}

void dyDelete(DynamicArray* array)
{
    free(array->data);
    free(array);
}

void dyAdd(DynamicArray* array, TYPE value)
{
    if (array->size >= array->capacity)
    {
        setCapacity(array, 2 * array->capacity);
    }
    array->data[array->size] = value;
    array->size++;
}

void dyAddAt(DynamicArray* array, TYPE value, int position)
{
    assert(position <= array->size);
    dyAdd(array, value);
    for (int i = array->size - 1; i > position; i--)
    {
        dySwap(array, i, i - 1);
    }
}

void dyPut(DynamicArray* array, TYPE value, int position)
{
    assert(position < array->size);
    array->data[position] = value;
}

void dyRemoveAt(DynamicArray* array, int position)
{
    assert(position < array->size);
    for (int i = position; i < array->size - 1; i++)
    {
        array->data[position] = array->data[position + 1];
    }
    array->size--;
}

TYPE dyGet(DynamicArray* array, int position)
{
    assert(position < array->size);
    return array->data[position];
}

int dySize(DynamicArray* array)
{
    return array->size;
}

void dySwap(DynamicArray* array, int position1, int position2)
{
    assert(position1 < array->size);
    assert(position2 < array->size);
    TYPE temp = array->data[position1];
    array->data[position1] = array->data[position2];
    array->data[position2] = temp;
}

// --- Stack ---

void dyStackPush(DynamicArray* stack, TYPE value)
{
    dyAdd(stack, value);
}

void dyStackPop(DynamicArray* stack)
{
    dyRemoveAt(stack, stack->size - 1);
}

TYPE dyStackTop(DynamicArray* stack)
{
    return dyGet(stack, stack->size - 1);
}

int dyStackIsEmpty(DynamicArray* stack)
{
    return stack->size == 0;
}

// --- Bag ---

static int findFirst(DynamicArray* array, TYPE value, compareFunction compare)
{
    for (int i = 0; i < array->size; i++)
    {
        if (compare(value, array->data[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void dyBagAdd(DynamicArray* bag, TYPE value)
{
    dyAdd(bag, value);
}

void dyBagRemove(DynamicArray* bag, TYPE value, compareFunction compare)
{
    int position = findFirst(bag, value, compare);
    if (position != -1)
    {
        dyRemoveAt(bag, position);
    }
}

int dyBagContains(DynamicArray* bag, TYPE value, compareFunction compare)
{
    return findFirst(bag, value, compare) != -1;
}

// --- Ordered bag ---

static int binarySearch(DynamicArray* array, TYPE value, compareFunction compare)
{
    int low = 0;
    int high = array->size - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (compare(value, array->data[middle]) < 0)
        {
            high = middle - 1;
        }
        else if (compare(value, array->data[middle]) > 0)
        {
            low = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return low;
}

void dyOrderedAdd(DynamicArray* bag, TYPE value, compareFunction compare)
{
    int position = binarySearch(bag, value, compare);
    dyAddAt(bag,value, position);
}

void dyOrderedRemove(DynamicArray* bag, TYPE value, compareFunction compare)
{
    int position = binarySearch(bag, value, compare);
    if (compare(value, bag->data[position]) == 0)
    {
        dyRemoveAt(bag, position);
    }
}

int dyOrderedContains(DynamicArray* bag, TYPE value, compareFunction compare)
{
    int position = binarySearch(bag, value, compare);
    return compare(value, dyGet(bag, position)) == 0;
}

// --- Heap ---

/**
 * Adjusts heap to maintain the heap property.
 * @param heap
 * @param last  index to adjust up to.
 * @param position  index where adjustment starts.
 * @param compare  pointer to compare function.
 */
void adjustHeap(DynamicArray* heap, int last, int position, compareFunction compare)
{
  /*Declare ints to hold indexes of left and right children*/
  int leftChild = (2 * position) + 1;
  int rightChild = (2 * position) + 2;
    
  //Declare int to hold index of smallest child
  int smallChild;

  /*Assert pre-conditions*/
  assert(heap != 0);
  assert(last < dySize(heap));
  assert(position <= last);

  /*If there are 2 children*/
  if(rightChild <= last) {
    //Find index of smallest child
    if(compare(dyGet(heap, leftChild), dyGet(heap, rightChild)) == -1) {
      smallChild = leftChild;
    }
    else if(compare(dyGet(heap, leftChild), dyGet(heap, rightChild)) > -1) {
      smallChild = rightChild;
    }
    
    //Swap position and smallChild and recursively call adjustHeap(), if necessary
    if(compare(dyGet(heap, smallChild), dyGet(heap, position)) == -1) {
      dySwap(heap, position, smallChild);

      adjustHeap(heap, last, smallChild, compare);
    }
  }
  /*Else if there is only 1 child*/
  else if(leftChild <= last) {
    //Swap position and leftChild and recursively call adjustHeap(), if necessary
    if(compare(dyGet(heap, leftChild), dyGet(heap, position)) == -1) {
      dySwap(heap, position, leftChild);

      adjustHeap(heap, last, leftChild, compare);
    }
  }
}

/**
 * Builds a valid heap from an arbitrary array.
 * @param heap  array with elements in any order.
 * @param compare  pointer to compare function.
 */
void buildHeap(DynamicArray* heap, compareFunction compare)
{
  /*Assert pre-conditions*/
  assert(heap != 0);
  assert(dySize(heap) > 0);

  /*Declare int to hold size of heap*/
  int max = dySize(heap);

  /*Declare int to hold last index of heap*/
  int last = max - 1;

  /*Call adjustHeap() on each element that isn't guaranteed to already be in a heap*/
  for(int i = (max / 2) - 1; i >= 0; i--) {
    adjustHeap(heap, last, i, compare);
  }
}

/**
 * Adds an element to the heap.
 * @param heap
 * @param value  value to be added to heap.
 * @param compare  pointer to compare function.
 */
void dyHeapAdd(DynamicArray* heap, TYPE value, compareFunction compare) {\
  /*Declare ints to hold index of position and its parent*/
  int parent;
  int position;

  /*Assert pre-conditions*/
  assert (heap != 0);

  /*Initialize position to last element of heap*/
  position = dySize(heap);

  /*Add value to end of heap array*/
  dyAdd(heap, value);

  /*Move value to correct position*/
  while(position != 0) {
    /*Set parent to correct index*/
    parent = (position - 1) / 2;

    /*If val at position < val at parent, swap and reset position*/
    if(compare(dyGet(heap, position), dyGet(heap, parent)) == -1) {
      dySwap(heap, parent, position);

      position = parent;
    }
    /*Otherwise, break loop*/
    else {
      return;
    }
  }
}

/**
 * Removes the first element, which has the min priority, from the heap.
 * @param heap
 * @param compare  pointer to the compare function.
 */
void dyHeapRemoveMin(DynamicArray* heap, compareFunction compare)
{
  /*Declare int to hold last index*/
  int last;

  /*Assert pre-conditions*/
  assert(dySize(heap) > 0);

  /*Initialize last*/
  last = dySize(heap) - 1;

  /*Put last element in first position and remove last*/
  dyPut(heap, dyGet(heap, last), 0);
  dyRemoveAt(heap, last);

  /*If size > 0, reset last and call adjust heap from 0 to last*/
  if(dySize(heap) > 0) {
    last = dySize(heap) - 1;

    adjustHeap(heap, last, 0, compare);
  }
}

/**
 * Returns the first element, which has the min priority, from the heap.
 * @param heap
 * @return  Element at the top of the heap.
 */
TYPE dyHeapGetMin(DynamicArray* heap)
{
  /*Assert pre-conditions*/
  assert(dySize(heap) > 0);

  /*Return first element of heap*/
  return dyGet(heap, 0);  
}

/**
 * Sorts arbitrary array in-place.
 * @param heap  array with elements in arbitrary order.
 * @param compare  pointer to the compare function.
 */
void dyHeapSort(DynamicArray* heap, compareFunction compare)
{
  /*Assert pre-conditions*/
  assert(heap != 0);
  assert(dySize(heap) > 0);

  /*Call buildHeap()*/
  buildHeap(heap, compare);

  /*Moving backwords in heap, swap with first element and call adjustHeap()*/
  for(int i = dySize(heap) - 1; i > 0; i--) {
    dySwap(heap, 0, i);
    adjustHeap(heap, i - 1, 0, compare);
  }
}

// --- Iterator ---

DynamicArrayIterator* dyIteratorNew(DynamicArray* array)
{
    DynamicArrayIterator* iterator = malloc(sizeof(DynamicArrayIterator));
    iterator->array = array;
    iterator->current = 0;
    return iterator;
}

void dyIteratorDelete(DynamicArrayIterator* iterator)
{
    free(iterator);
}

int dyIteratorHasNext(DynamicArrayIterator* iterator)
{
    return iterator->current < iterator->array->size;
}

TYPE dyIteratorNext(DynamicArrayIterator* iterator)
{
    TYPE value = dyGet(iterator->array, iterator->current);
    iterator->current++;
    return value;
}

void dyIteratorRemove(DynamicArrayIterator* iterator)
{
    iterator->current--;
    dyRemoveAt(iterator->array, iterator->current);
}

// --- Utility ---

void dyPrint(DynamicArray* array, printFunction print)
{
    printf("\nsize: %d\ncapacity: %d\n[\n", array->size, array->capacity);
    for (int i = 0; i < array->size; i++)
    {
        printf("%d : ", i);
        print(array->data[i]);
        printf("\n");
    }
    printf("]\n");
}

void dyCopy(DynamicArray* source, DynamicArray* destination)
{
    free(destination->data);
    init(destination, source->capacity);
    for (int i = 0; i < source->size; i++)
    {
        destination->data[i] = source->data[i];
    }
    destination->size = source->size;
}
