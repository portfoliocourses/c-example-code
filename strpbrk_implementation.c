/*******************************************************************************
*
* Program: strpbrk() Function Implementation
* 
* Description: Example of how to implement the strpbrk() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=OcjBc_1e3M8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

char *_strpbrk(const char *str1, const char *str2);

int main()
{
  // Create char arrays to store two test strings... we'll try to find the first
  // occurrence of a char in 'vowels' in 'string', i.e. the first vowel in the
  // string.
  char string[] = "String with vowels.";
  char vowels[] = "AEIOUaeiou";
  
  // The official strpbrk() function will return a pointer to the first 'i'
  // char in the string stored in string[].
  //
  //   char *first_vowel = strpbrk(string, vowels);
  
  // The version of the function we implement below will also return a pointer 
  // to the first 'i char in the string stored in string[].
  char *first_vowel = _strpbrk(string, vowels);
  
  // We can output the string starting from this char that first_vowel points to
  // and we'll get "ing with vowels." as output
  printf("Rest Of String: %s\n", first_vowel);
  
  return 0;
}

// Like the official strpbrk() function, the function will return a pointer to
// the first char in the string pointed to by str1 that matches a char in the 
// string pointed to be str2.  If no such char can be found, the function will
// return NULL.
char *_strpbrk(const char *str1, const char *str2)
{
  // The official function has undefined behaviour if str1 and str2 do not point
  // to valid strings... we do some defensive programming here and return NULL 
  // if either str1 or str2 stores NULL.  This could happen if our program has a
  // bug related to not dynamically allocating memory, for example.  We do this
  // to prevent the program from possibly crashing if we attempt to use str1 
  // and str2 in the case they are storing NULL.
  if (str1 == NULL || str2 == NULL)
  {
    return NULL;
  }
  
  // A loop nested inside a loop is used to check for the first matching
  // character.  The outer loop uses str1 to advance through each char of the
  // string that str1 initially points to.  The inner loop uses temp to advance
  // through each char of the string that str2 points to.  For each char in the 
  // first string (outer loop), we attempt to find a matching char in the 
  // second string (inner loop).  And if we find a match, we return str1, the 
  // pointer to the char that str1 is currently pointing to.
  
  // temp will be used to loop through the characters of the second string 
  // again and again in the inner loop
  const char *temp;
  
  // We use str1 to loop through the chars in the first string, incrementing
  // it to point to the next char in the string with each loop iteration.  We
  // stop the loop when str1 points to the null terminator that ends the
  // string.
  while (*str1 != '\0')
  {
    // Set temp to point to the first char in the second string
    temp = str2;
    
    // As with the outer loop and str1, we use temp in the inner loop to 
    // check each char in the second string.  We stop the loop when temp 
    // points to the null terminator that ends the (second) string.
    while (*temp != '\0')
    {
      // If the character we're currently examining the first string matches
      // the character we're currently examining in the second string, we
      // return str1, the pointer to that character in the first string.  
      if (*str1 == *temp)
      {
        // We type cast to char * as str1 is type const char * and the 
        // function return type is char *
        return (char *) str1;
      }
      
      // Increment temp with each loop iteration to have it point to the next
      // character in the second string.  Note that because we "go through" 
      // the characters of the second string repeatedly with each run of the
      // inner loop for each iteration of the outer loop, we need to keep 
      // reseting temp to point to the first char of the string that str2 
      // points to, as we do above with temp = str2.
      temp++;
    }
    
    // Increment str1 with each loop iteration to have it point to the next
    // character in the first string
    str1++;
  }
  
  // If no matching character is found, we return NULL
  return NULL;
}
