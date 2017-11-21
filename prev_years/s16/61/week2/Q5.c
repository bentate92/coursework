/* CS261- Assignment 1 - Q.5*/
/* Name: Benjamin Tate
 * Date: 4/10/2016
 * Solution description: First, word is initialized as an array of characters with a max
 *   length of 30, as discussed on Piazza. word is then read from the keyboard using
 *   scanf, and passed through sticky(). Sticky uses a while loop to continue until the 
 *   character is '0', and if the character is in an even position, it checks it is
 *   uppercase, and calls toLowerCase() if so. Otherwise, if the character is in an odd
 *   position, toUpperCase() is called if the character is currently lowercase.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
  return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
  return ch-'A'+'a';
}

void sticky(char* word){
  /*Convert to sticky caps*/
  int i;

  while(word[i] != '0') {
    if(i % 2 != 0) {
      if(word[i] >= 'A' && word[i] <= 'Z') {
        word[i] = toLowerCase(word[i]);
      }
    }
    else {
      if(word[i] >= 'a' && word[i] <= 'z') {
        word[i] = toUpperCase(word[i]);
      }
    }

    i++;
  }
}

int main(){
  /*Read word from the keyboard using scanf*/
  char word[30];
  
  printf("\nEnter a word:\n");
  scanf("%s", word);
  
  /*Call sticky*/
  sticky(word);

  /*Print the new word*/
  printf("\nHere's the word in sticky case:\n");
  printf("%s \n \n", word);  

  return 0;
}
