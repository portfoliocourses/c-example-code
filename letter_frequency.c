/*******************************************************************************
*
* Program: Find The Frequency Of Each Letter In A String
*
* Description: Example of how to find the frequency of each letter in a string 
* and print out the results in a neatly organized table.  This program is 
* case insensitive and so considers uppercase and lowercase letters to both be 
* an occurrence of the same letter.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1OZMcC0euic 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  // An example string that contains at least one occurrence of each letter in
  // the alphabet
  char *s = "The quick brown fox jumps over the lazy dog!";
  
  // There are 26 letters in the alphabet, and this program is case insensitive,
  // so we need to store 26 counts for each letter.  Index 0 will store the 
  // count for 'a', index 1 will store the count for 'b', and so on.  All counts
  // (i.e. array elements) are initialized to zeo.  
  int letter_counts[26] = {0};
  
  // Find the length of the string with strlen() and store it into length
  int length = strlen(s);

  // Used to store each character in the string after applying tolower()
  char c;
  
  // Use the counter variable i to "loop through" the index of each character
  // in the string, starting with index 0 and stopping once we reach the length
  // of the string.
  for (int i = 0; i < length; i++)
  {
    // Apply tolower() to the "current character we are looking at" as given by 
    // index i.  tolower() will return the lowercase version of the letter if
    // the character it is passed as an argument is an uppercase letter, or 
    // the unaltered character otherwise, and we store the returned value into 
    // the variable c.  At this point we know that if c contains a letter, that 
    // it is the lowercase version of that letter.
    c = tolower(s[i]);
    
    // It's possible c does not contain a letter, it could be a non-letter 
    // character like the space character ' ' or '!' as in our test string.  So 
    // we check to see if the character is in the range of characters from 
    // 'a' to 'z'.  The relational operators >= and <= may seem odd to use with
    // character values like 'a' and 'z' but it is not unusual if we are 
    // familiar with how characters are represented in C.  The character 'a' 
    // is represented using the int value 97, the character 'b' with the int 
    // value 98, all the way up to 'z' being represented with 122.  This mapping
    // of int values to characters is how characters are 'encoded'.  So when 
    // we have c >= 'a' we are comparing the int values... if the character 
    // stored in c is between 97 and 122 (i.e. between 'a' and 'z') then the 
    // character is a letter!  
    //
    // We also use the fact that characters are represented with int values to
    // increment the correct index of the letter_counts array for the associated
    // character.  So c - 'a' will give us 97 - 97 = 0 if c = 'a'.  And c - 'b' 
    // will give us 98 - 97 = 1 if c = 'b'.  And so on for each character up 
    // until 'z'.  So c - 'a' will give us the index associated with the letter
    // in our letter_counts array, and we increment that count by 1!
    //
    if (c >= 'a' && c <= 'z')
      letter_counts[c - 'a']++;
  }
  

  // letter_counts will now contain the count of each letter in the string, but 
  // now let's output the results into a nice table!

  // First we output the column headings by outputting Letter, Count and Percent
  // into left-aligned fields of width 10
  printf("%-10s%-10s%-10s\n", "Letter", "Count", "Percent");
  
  // To separate our column headings from the table data we output a row of 30 
  // star characters
  for (int i = 0; i < 30; i++) printf("*");
  printf("\n");
  
  // In addition to outputing the letter and it's associated count we'll also 
  // output the percent of characters in the string made up of the letter.
  double percent;
  
  // Loop through the indexes for each element in our letter_counts array using
  // the counter variable i to go from 0 .. 25, where index 0 of the array 
  // stores the count of letter 'a', index 1 stores the count of letter 'b', 
  // and so on.
  for (int i = 0; i < 26; i++)
  {
    // Calculate the percent of characters in the string made up of the 
    // current letter by dividing the number of occurrences of the letter 
    // in the string by the total number of characters in the string (and 
    // multiplying the result by 100).  Note that because the percentage 
    // values may include decimal places, we want 'double division' to 
    // occur such that we store a double value that includes decimal 
    // places into percent.  If we don't convert letter_counts[i] to a double
    // value before performing the division operation /, we will get "integer 
    // division" occuring intead, and we will have no decimal digits in our 
    // percent as a reuslt. 
    percent = ((double) letter_counts[i] / length) * 100;
    
    // Outut the row of data for this letter.  We again use -10 to output the 
    // values into left-aligned fields of width 10, to create "fixed-width 
    // columns" of data in our output.  We .2 to get two decimal digits of 
    // accuracy for our output of the percent values, and we use c, d and f 
    // to output a character (the letter itself), an integer (the count of 
    // that letter), and a double (the percent) respectively.  The argument 
    // 'a' + i will output the character associated with index i in our 
    // letter_counts array.  So for example 'a' + i in the case when i = 3
    // will give us 97 + 3 = 100, which when output as a character value 
    // using %-10c will result in the letter 'd' being output... which is what
    // we want as letter_counters[3] stores the count of the letter 'd'!
    printf("%-10c%-10d%-10.2f\n", 'a' + i, letter_counts[i], percent);
  }
  
  return 0;
}


// Characters in C are really represented with integers in what we call an 
// "encoding".  The characters from 'a' to 'z' will be represented with the 
// following integer values.  In the above program we utilize this property
// to make our program shorter and more elegant than doing something like...
//
// if (c == 'a') letter_counts[0]++;
// else if (c == 'b') letter_counts[1]++;
// else if (c == 'c') letter_counts[2]++;
// ...
//
//
//       97  -> a
//       98  -> b
//       99  -> c
//       100 -> d
//       101 -> e
//       102 -> f
//       103 -> g
//       104 -> h
//       105 -> i
//       106 -> j
//       107 -> k
//       108 -> l
//       109 -> m
//       110 -> n
//       111 -> o
//       112 -> p
//       113 -> q
//       114 -> r
//       115 -> s
//       116 -> t
//       117 -> u
//       118 -> v
//       119 -> w
//       120 -> x
//       121 -> y
//       122 -> z