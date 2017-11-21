/* CS261- Assignment 6 - Hash map implementation (hashMap.c)*/
/* Name: Benjamin Tate
 * Date: 5/29/2016
 * Description: Implementation of hash table data structure
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  /*Loop through buckets*/
  for(int i = 0; i < map->capacity; i++) {
    /*Initialize two HashLink pointers to iterate through current bucket*/
    HashLink* itr = map->table[i];
    HashLink* prev = itr;

    /*Iterate through current bucket and delete all links*/
    while(itr != NULL) {
      prev = itr;
      itr = itr->next;

      hashLinkDelete(prev);
      map->table[i] = itr;
    }
  }

  /*Free table*/
  free(map->table);
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
  /*Assert pre-conditions*/
  assert(map != 0);
  assert(key != 0);

  /*Find index*/
  int idx = HASH_FUNCTION(key) % hashMapCapacity(map);
  if(idx < 0) {
    idx += hashMapCapacity(map);
  }

  /*Return NULL if key is not in map*/
  if(hashMapContainsKey(map, key) == 0) {
    return NULL;
  }

  /*Pointer to current HashLink at idx*/
  HashLink* curr = map->table[idx];

  /*Iterate through bucket until key is found*/
  while(strcmp(key, curr->key) != 0) {
    curr = curr->next;
  }

  /*Return value*/
  return &curr->value;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  /*Create new HashMap with new capacity*/
  HashMap* bigMap = hashMapNew(capacity);

  /*Iterate through buckets*/
  for(int i = 0; i < map->capacity; i++) {
    /*Initialize HashLink to iterate through current bucket*/
    HashLink* curr = map->table[i];

    /*Iterate through current bucket*/
    while(curr != NULL) {
      /*Add links from old map to bigMap*/
      hashMapPut(bigMap, curr->key, curr->value);

      /*Increment curr*/
      curr = curr->next;
    }
  }

  /*Assign bigMap to map*/
  map = bigMap;
  hashMapDelete(bigMap);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  /*Index key using HASH_FUNCTION macro*/
  int idx = HASH_FUNCTION(key) % map->capacity;
  if(idx < 0) {
    idx += map->capacity;
  }

  /*If key is already in map, update value associated with it*/
  if(hashMapContainsKey(map, key)) {
    HashLink* itr = map->table[idx];
  
    while(itr != NULL) {
      if(strcmp(itr->key, key) == 0) {
        itr->value = value;
      }

      itr = itr->next;
    }
  }
  /*Otherwise, add new link to appropriate index and increment size*/
  else {
    HashLink* newLink = hashLinkNew(key, value, map->table[idx]);
    assert(newLink);
  
    map->table[idx] = newLink;
    map->size++;
  }

  /*Check that load does not excede max and adjust if necessary*/
  if(hashMapTableLoad(map) >= MAX_TABLE_LOAD) {
    resizeTable(map, map->capacity * 2);
  }  
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  /*Find index of link containing key*/
  int idx = HASH_FUNCTION(key) % map->capacity;
  if(idx < 0) {
    idx += map->capacity;
  }

  /*Create two HashLink pointers to iterate through bucket while keeping track of previous link*/
  HashLink* itr = map->table[idx];
  HashLink* prev = itr;

  /*Continue while itr !NULL to search entire bucket*/
  while(itr != NULL) {
    /*If the key is found...*/
    if(strcmp(itr->key, key) == 0) {
      /*If it is in the first link in the bucket, adjust pointer and delete link*/
      if(itr == map->table[idx]) {
        map->table[idx] = itr->next;
        hashLinkDelete(itr);

        /*Decrement size*/
        map->size--;
      }
      /*If it's anywhere else in the bucket, adjust pointers using prev and delete*/
      else {
        prev->next = itr->next;
        hashLinkDelete(itr);

        /*Decrement size*/
        map->size--;
      }
    }
    /*Otherwise advance iterators*/
    else {
      prev = itr;
      itr = itr->next;
    }
  }
}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  /*Index key using HASH_FUNCTION*/
  int idx = HASH_FUNCTION(key) % map->capacity;
  if(idx < 0) {
    idx += map->capacity;
  }

  /*Initialize HashLink to iterate through bucket at idx*/
  HashLink* itr = map->table[idx];

  /*Iterate through bucket*/
  while(itr != 0) {
    /*If key is found, return 1*/
    if(strcmp(key, itr->key) == 0) {
      return 1;
    }

    /*Otherwise, increment itr*/
    itr = itr->next;
  }
  
  /*If key wasn't found in any HashLink in any bucket, return 0*/
  return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
  /*Assert pre-conditions*/
  assert(map != 0);

  /*Declare int to hold count, initialize to 0*/
  int empty = 0;

  /*Iterate through buckets*/
  for(int i = 0; i < map->capacity; i++) {
    /*If current bucket has no links, increment empty counter*/
    if(map->table[i] == NULL) {
      empty++;
    }
  }

  return empty;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
  /*Assert pre-conditions*/
  assert(map != 0);
  assert(map->capacity > 0);
 
  /*Cast size and capacity to floats and find ratio*/ 
  float load = (float)map->size / (float)map->capacity;

  return load;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf(" (%s, %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}
