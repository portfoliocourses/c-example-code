/*******************************************************************************
*
* Program: Efficient Algorithm To Remove Duplicate Chars From A String
*
* Description: A more efficient algorithm to remove the duplicate characters
* from a string in C, in comparison to this algorithm:
*   https://www.youtube.com/watch?v=4iaYlp-axac
* This algorithm uses an array to keep track of which characters have been
* encountered, which technically makes it less "space efficient", but it allows
* the algorithm to have improved performance.
*
* YouTube Lesson: https://www.youtube.com/watch?v=LQytHnI8z7o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void remove_duplicates(char *string);

int main(int argc, char *argv[])
{
  // Declare and initialize a test string
  char s[] = "aaaaaaabbbbbbccccccaaaaaaadddddeeee";

  // Call the function to remove the duplicate characters from the string
  remove_duplicates(s);

  // Output the string after the duplicates have been removed, the result
  // should be "abcde"
  printf("%s\n", s);

  return 0;
}

// Removes the duplicate characters from the string provided as an argument
void remove_duplicates(char *string)
{
  // Find the length of the string.  We will "loop through" the string one
  // character at a time from 0 ... length.
  int length = strlen(string);

  // Assuming the string is made up of extended ASCII characters, then each
  // character is represented with an integer from 0-255.  For example 'a'=97.
  // We declare an array of 256 bools to keep track of whether we have
  // encountered a character yet or not, and initialize all elements to false
  // as when we first start reading the string we will have encountered no
  // characters at all.  We can set char_found['a'] = true to acknowledge when
  // we have encountered the character 'a' (and the same for other characters).
  // We can also check char_found['a'] to see if we have yet encountered 'a'
  // (and again, the same for other characters).  In this way we use this array
  // to keep track of whether we have encountered a character yet or not, i.e.
  // whether the character is a duplicate or not.
  //
  bool char_found[256] = {false};

  // The counter variable j will be used to keep track of the length of the
  // new string with the duplicates removed, and to write the characters for
  // the new string into the old string... overwriting the old string 'in
  // place'.
  int j = 0;

  // Use counter variable i to loop over each index in the string from
  // 0 ... length.  We can see the character at the index i is the character
  // we are currently "looking at" or "examining".
  for (int i = 0; i < length; i++)
  {
    // If the character we are currentl examinig has NOT been encountered before
    // it is NOT a duplicate and we want the character to be written into
    // the new string (we also need to acknowledge that we have now found
    // this character too).
    if (!char_found[string[i]])
    {
      // Keep track of the fact that we have found this character by setting
      // the character's index in the char_found array to true... in the future
      // if the character is ecnounterd the if condition above will now be
      // false as !false -> true
      char_found[string[i]] = true;

      // Write this character into the new string.  Because we only increment
      // j when we've encountered a non-duplicate character, over time as we
      // ecnountered duplicates, j will be less than i (by however many
      // duplicates we have encountered).  This allows us to write a new
      // string into the same char array as our old string, taking up the
      // portion of the string from 0 ... j.  This has no effect on our
      // ability to read the rest of the string as i will always be >= j.
      string[j] = string[i];
      j++;
    }
  }

  // When we're done j will be equal to the length of the string with the
  // duplciates removed (possible j=length if there are no duplicates).  We
  // insert the null terminator at this index to terminate the new string.
  string[j] = '\0';
}