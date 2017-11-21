/* CS261- Assignment 6 - Concordance (main.c)*/
/* Name: Benjamin Tate
 * Date: 5/29/2016
 * Description: Implementation of concordance to count occurences of each word
 *    in a file
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
  const char* fileName = "input1.txt";
  if (argc > 1)
  {
      fileName = argv[1];
  }
  printf("Opening file: %s\n", fileName);
  
  clock_t timer = clock();
  
  HashMap* map = hashMapNew(10);
  
  // --- Concordance code begins here ---
  // Be sure to free the word after you are done with it here.
  /*Open file and declare word*/
  FILE* file = fopen(fileName, "r");
  char* word;

  /*Loop through words*/
  while(word != NULL) {
    /*Set word using nextWord*/
    word = nextWord(file);

    /*Break for final NULL word at end of file*/
    if(word == NULL) { break; }

    /*If the word is already in the HashMap, increment value*/
    if(hashMapContainsKey(map, word)) {
      int count = *hashMapGet(map, word);

      hashMapPut(map, word, count + 1);
    }
    /*Otherwise add to HashMap with value = 1*/
    else {
      hashMapPut(map, word, 1);
    }

    /*Free word*/
    free(word);
  } 

  /*Print each word and number of occurrences*/
  for(int i = 0; i < hashMapCapacity(map); i++) {
    HashLink* curr = map->table[i];

    while(curr != NULL) {
      printf("\n%s: %d", curr->key, curr->value);

      curr = curr->next;
    }
  }

  printf("\n");
  // --- Concordance code ends here ---
  
  hashMapPrint(map);
  
  timer = clock() - timer;
  printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
  printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
  printf("Number of links: %d\n", hashMapSize(map));
  printf("Number of buckets: %d\n", hashMapCapacity(map));
  printf("Table load: %f\n", hashMapTableLoad(map));
  
  hashMapDelete(map);
  return 0;
}
