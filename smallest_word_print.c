/*******************************************************************************
*
* Program: Find And Print Smallest Word
* 
* Description: Finds and prints out the smallest word in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=viREXI8tvNc
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* smallest_word(char *s);

int main()
{
  // test out the function with a test string
  char s[] = "A sentence with several words.";
  char *word = smallest_word(s);
  printf("%s\n", word);
  
  // because the memory for the word is dynamically allocated we free the memory
  free(word);
  
  return 0;
}

// returns a pointer to a dynamically allocated char array containing the
// smallest word found in string s, and NULL if the provided string is empty
char* smallest_word(char *s)
{
  // stores the length of the string
  int len = strlen(s);

  // we can't find a smallest word in a string with no characters, so return
  // NULL to signify an error
  if (len == 0) return NULL;

  // count will keep track of the number of characters in each word
  int count = 0;

  // min will keep track of the number of characters in the smallest
  // word found so far, it is initially set to a special value -1
  int min = -1;
  
  // temp_buffer will store the word currently being analyzed
  char temp_buffer[256];

  // min_word will store the smallest word found so far
  char min_word[256];

  // these are the characters we considered to be "non-word" characters
  char nonwords[] = " .,;\n\t";
  
  // i will keep track of our current index in the array
  int i = 0;
  
  // the outer loop stops when we reach the end of the string, it has a loop
  // that steps through the next word, followed by a loop that steps through
  // any delimeter characters that separate words
  while (i < len)
  {

    // this loop steps through a word and keeps a count of the characters,
    // as well as stores the word into temp_buffer
    count = 0;
    while (i < len)
    {
      // we know we've reached the end of a word when strchr() no longer
      // returns NULL as it means that it found a match for s[i] in nonwords,
      // the function returns NULL if it cannot find the char and a pointer
      // to the matching character if it can
      if (strchr(nonwords, s[i]) != NULL) break;
      
      temp_buffer[count] = s[i];
      i++;
      count++;
    }
    temp_buffer[count] = '\0';
    
    // If we've found a word smaller than the previous smallest word, then
    // we'll update min and min_word.  If the word is the first word found in
    // the string then min will equal -1, a special value, and in this case
    // we also set this word as the smallest word (this time by default, it
    // being the ONLY word found so far).
    if (count < min || min == -1)
    {
      min = count;
      strcpy(min_word, temp_buffer);
    }
    
    // step through any non-word characters until we reach the next word
    while (i < len)
    {
      // once strchr() returns NULL, we know that s[i] is NOT one of the
      // delimeter characters that separates words, and we have reached the
      // next word
      if (strchr(nonwords, s[i]) == NULL)
        break;
      i++;
    }
  }
  
  // copy the min_word into a dynamically allocated char array that is
  // exactly large enough to store the word, rather than keeping it in
  // min_word which is 256 chars and much larger than necessary
  char *word = malloc(sizeof(char) * (min  + 1));
  strcpy(word, min_word);
  return word;
}
