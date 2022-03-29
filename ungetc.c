/*******************************************************************************
*
* Program: ungetc() Function
* 
* Description: Examples of using the ungetc() function in C to to put a char 
* onto an input stream.
*
* YouTube Lesson: https://www.youtube.com/watch?v=p4PcAQ60O40 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  // Example #1 - Basic ungetc() Demo
  //
  // In this example we assume file.txt has the following contents:
  //
  // abcdefg
  //
  // We open the file and read/print each char one at a time.  Every time we 
  // call fgetc() it pulls the next char from the input stream.  When we read 
  // the char 'e' we then *push* 'z' on to the input stream!  So if at the start
  // our input stream looks like this:
  //
  // abcdefg
  //
  // then after reading abcd we would have:
  //
  // efg
  //
  // We then read the char 'e', recognize it is 'e', and then PUSH 'z' onto the 
  // input stream leaving us with:
  //
  // zfg
  //
  // From here we would then continue the loop and read/print zfg next!
  //

  /*
  // create file pointer variable
  FILE *file;
  
  // open the file file.txt in reading mode
  file = fopen("file.txt", "r");
  
  // if there is an error opening the file exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
   
  // read in each char of the file one at a time, handling the case the char is 
  // 'e' differently using ungetc
  int c;
  while (true)
  {
    // read in the character from the input stream
    c = fgetc(file);
    
    // if we've reached the end of the file or there was an error reading from 
    // the file, then stop
    if (feof(file) || ferror(file)) break;
    
    // if the char we've just read in is 'e' then push 'z' onto the input 
    // stream... the loop will then continue to read this 'z' char next!
    //
    // otherwise just output the char
    //
    if (c == 'e') ungetc('z', file);
    else printf("%c", c);
  }
  printf("\n");
  
  // close the file
  fclose(file);
  */

  
  // Example #2 - Parsing Inspired Demo
  //
  // A practical use case of ungetc() is being able to "peek ahead" one char 
  // in the input stream, by reading the next char, and putting it back so as 
  // not to remove it from the input stream.
  //
  // In certain situations such as reading packets of data or parsing, this 
  // ability to "peek ahead" a character can be useful as we can process the 
  // data without having the overhead of creating an input buffer (an array 
  // that stores data temporarily, that we then analyze later).
  //
  // See the description of these situations here:
  // 
  // https://stackoverflow.com/questions/476615/what-is-the-purpose-of-ungetc-or-ungetch-from-kr
  //
  // https://softwareengineering.stackexchange.com/questions/330181/why-does-the-c-stdio-ungetc-function-exist
  //
  // In this example we assume that file.txt contains the text:
  //
  // 123+245
  //
  // That represents some expression we are parsing, where we wish to extract
  // the first number in an addition operation, BUT we also wish to leave the 
  // '+' operator in the input stream for "code that will execute in the future"
  // to see for the purposes of parsing the expression.
  //
  // We use ungetc() to "peek ahead" by pulling the '+' from the input stream,
  // recognizing it is a '+', and then pushing it back.
  //

  // Create the file pointer variable
  FILE *file;
  
  // open file text for reading
  file = fopen("file.txt", "r");

  // if there is an error opening the file exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
 
  // as with example 1, stores each char read in from file.txt
  int c;
  
  // op1 will store the first 'operand' in the expression 123+245 we intend to
  // read in, i will keep track of our index into the op1 char array as we read 
  // in each char of the operand
  char op1[256];
  int i = 0;

  // keep reading chars from file.txt until we reach the end of the file, 
  // encounter an error reading the file, or encounter the '+' character
  while (true)
  {
    // read in the next char from the file
    c = fgetc(file);

    // stop if we've reached the end of the file or an error occurs
    if (feof(file) || ferror(file)) break;
    
    // if we've read in the '+' character, put it back onto the input stream
    // using ungetc, and then stop reading
    if (c == '+')
    {
      ungetc(c, file);
      break;
    }
    // otherwise store the char into op1, increment i to store the next char
    // in the next position in op1
    else 
    {
      op1[i] = c;
      i++;
    }
  }
  // make op1 a proper string by putting the null terminator at the end 
  op1[i] = '\0';

  // print out op1 and it will contain the first operand
  printf("op1: %s\n", op1);
  
  // BUT if we print out the rest of the string we will find that we have 
  // +256, and so we have read the + character without "consuming it", peeking
  // ahead like this can be helpful for parsing algorithms!
  char rest[256];
  fgets(rest, 256, file);
  printf("rest: %s\n", rest);
  
  // close our access to the file
  fclose(file);
  
  return 0;
}