/* CS261- Assignment 2 - Dynamic array implementation (dynamicArray.c)*/
/* Name: Benjamin Tate
 * Date: 4/17/2016
 * Description: Implementation of a struct containing a dynamically
 *   allocated array, including functions for stack and bag structure
 *   types.
 */
 
#include <assert.h>
#include <stdlib.h>
#include "dynArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* newDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{	
  /*Assert pre-conditions*/
  assert(v->data != 0);

  /*Allocate space for temporary array of new capacity*/ 
  TYPE* temp = (TYPE*)malloc(sizeof(TYPE) * newCap);
  assert(temp != 0);    //Check that temp was allocated properly

  /*Copy contents of v->data into temp*/
  for(int i = 0; i < v->size; i++) {
    temp[i] = v->data[i];
  }

  /*Free v->data memory*/
  free(v->data);

  /*Copy temp into v->data*/
  v->data = temp;
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
  /*Assert pre-conditions*/
  assert(v->data != 0);

  /*Add val to last position in v, doubling capacity if necessary*/
  if(v->size < v->capacity) {
    v->data[v->size] = val;
  }
  else {
    _dynArrSetCapacity(v, v->size * 2);

    v->data[v->size] = val;
  }

  /*Increment size*/
  v->size++;
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
  /*Assert pre-conditions*/
  assert(v->data != 0);
  assert(v->size > 0);
  assert(pos >= 0 && pos < v->size);

  /*Get val from given position in the dynamic array*/
  TYPE val = v->data[pos];

  /*Return val*/
	return val; 
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
  /*Assert pre-conditions*/
  assert(v->data != 0);
  assert(v->size > 0);
  assert(pos >= 0 && pos < v->size);

  /*Replace given element with val*/ 
  v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
  /*Assert pre-conditions*/
  assert(v->data != 0);
  assert(v->size > 0);
  assert(i >= 0 && j >= 0);
  assert(i < v->size && j < v->size);

  /*Create temporary TYPE to hold element i*/
  TYPE temp = v->data[i];
  /*Replace element i with element j*/
  v->data[i] = v->data[j];
  /*Replace element j with temp*/
  v->data[j] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{
  /*Assert pre-conditions*/
  assert(v->data != 0);
  assert(v->size > 0);
  assert(idx < v->size && idx >= 0);

  /*Shift elements back, starting at idx*/
  for(int i = idx; i < v->size; i++) {
    v->data[i] = v->data[i + 1];
  }

  /*Decrement size*/
  v->size--;
}



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
  /*Assert pre-conditions*/
  assert(v->data != 0);

  /*Test return false if size > 0, and true otherwise*/
  if(v->size > 0) {
    return 0;
  }
  else {
    return 1;
  }	
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{
  /*Call addDynArr()*/
  addDynArr(v, val);
}

/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{
  /*Assert pre-conditions*/
	assert(v->data != 0);
  assert(v->size > 0);

  /*Return last element in arrayi (top)*/
  return v->data[v->size - 1];  
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
  /*Call removeDynArr()*/
  removeAtDynArr(v, v->size - 1);
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
  /*Assert pre-conditions*/
	assert(v->data != 0);
  assert(v->size > 0);

  /*Initialize int to hold boolean value*/
	int inArr = 0;

  /*Iterate through array elements, change inArr if val is found*/
  for(int i = 0; i < v->size; i++) {
    if(v->data[i] == val) {
      inArr = 1;
    }
  }

	return inArr;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
  /*Assert pre-conditions*/
	assert(v->data != 0);
  assert(v->size > 0);

  /*Iterate through array*/
  for(int i = 0; i < v->size; i++) {
    /*If val is found...*/
    if(v->data[i] == val) {
      /*Remove val from v*/
      removeAtDynArr(v, i);

      /*End loop*/
      break;
    }
  }
}
