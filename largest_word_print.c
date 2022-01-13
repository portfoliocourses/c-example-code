/*******************************************************************************
*
* Program: Find And Print Longest Word
* 
* Description: Finds and prints out the longest word in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vpdraEnrFnU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largest_word(char *s);

int main()
{
  // test out the function with a test string
  char s[] = "A sentence with several words.";
  char *word = largest_word(s);
  printf("%s\n", word);
  
  // because the memory for the word is dynamically allocated we free the memory
  free(word);
  
  return 0;
}

// returns a pointer to a dynamically allocated char array containing the 
// largest word found in string s
char* largest_word(char *s)
{
  // stores the length of the string
  int len = strlen(s);

  // count will keep track of the number of characters in each word
  int count = 0;

  // max will keep track of the number of characters in the largest 
  // word found so far
  int max = -1;
  
  // temp_buffer will store the word currently being analyzed
  char temp_buffer[256];

  // max_word will store the largest word found so far
  char max_word[256];

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
    
    // if we've found a word larger than the previous largest word, then 
    // we'll update max and max_word
    if (count > max)
    {
      max = count;
      strcpy(max_word, temp_buffer);
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
  
  // copy the max_word into a dynamically allocated char array that is 
  // exactly large enough to store the word, rather than keeping it in
  // max_word which is 256 chars and much larger than necessary 
  char *word = malloc(sizeof(char) * (max + 1));
  strcpy(word, max_word);
  return word;
}