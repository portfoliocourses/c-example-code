/*******************************************************************************
*
* Program: Count The Words In A String
* 
* Description: Example counting the number of words in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=JpquiHExpfI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int word_count(char *s);

int main()
{
  // count the words in this test string and output the result
  char s[] = "This is, the way. Another...";
  int count = word_count(s);
  printf("%d\n", count);

  return 0;
}

// returns the number of words in the string that is provided as an argument
int word_count(char *s)
{
  // get the length of the string, use count to keep the word count
  int len = strlen(s);
  int count = 0;

  // we'll treat these characters as "word delimeters" that separate words, 
  // we'll check if a character can be found in this array to help make the 
  // distinction between words and the characters that separate them
  char nonwords[] = " .,;\n\t";
  
  // step through each character in the string with i as an index
  for (int i = 0; i < len; i++)
  {
    // step through the next word (if there is one)
    while (i < len)
    {
      // strchr() will return NULL if the char s[i] cannot be found in nonwords,
      // which means so long as it *is* returning NULL, it means we must be on a
      // word character (and not a delimeter).  When we do eventually advance i 
      // enough to reach a delimter, it will return a non-NULL value, and at 
      // that point we'll know we've stepped through another word.
      if (strchr(nonwords, s[i]) != NULL)
        break;
      i++;
    }
     
    // increment count as we have stepped through another word
    count++;
    
    // step through any delimeter characters until we reach a word character
    while (i < len)
    {
      // when we can't find the character s[i] of our current string index in 
      // nonwords, then the function will return NULL, and we'll know we've 
      // reached the next word and will continue on to step through it in the 
      // next pass of the loop
      if (strchr(nonwords, s[i]) == NULL)
        break;
      i++;
    }
  }
  return count;
}



