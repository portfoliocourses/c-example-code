/*******************************************************************************
*
* Program: Random Password Generator
* 
* Description: Generates random passwords of a user-specified length using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=laIQbFLznRo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
  // Prompt the user to enter the desired password length
  printf("Length: ");
  
  // Store the length entered into the password variable
  int length;
  scanf("%d", &length);
  
  // If the password length is not at least 1 we can't create a password, so 
  // exit with an error message and status
  if (length <= 0)
  {
    // Output the error message to inform the user what the problem is
    printf("Password length must be >= 1!");

    // Returning 1 instead of 0 is a signal to the terminal something has gone 
    // wrong in the execution of our program
    return 1;
  }
  
  // Dynamically allocate enough space to store the password... i.e. enough 
  // characters for the password (length) and + 1 for the null terminator to
  // terminate the string.
  char *password = malloc(length + 1);


  // If we are using newer versions of C such as C99 onwards we could declare 
  // a password char array on the stack as a local variable with:
  //
  // char password[length + 1];
  //
  // A local variable would no longer exist when the function returns so in 
  // this example the password is kept as dynamically allocated memory so that 
  // a pointer to the password can be maintained so long as it is still needed.
  

  // We'll randomly create the password with a combination of digits, lowercase 
  // letters, uppercase letters, and symbols.  We create 4 string literals for 
  // each "type" of character, and obtain the length of each to help us randomly
  // select characters from each string literal (see below).

  char *digits = "0123456789";
  int digits_length = strlen(digits);
  
  char *lowers = "abcdefghijklmnopqrstuwxyz";
  int lowers_length = strlen(lowers);
  
  char *uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int uppers_length = strlen(uppers);
  
  char *symbols = "!@#$%^&*()";
  int symbols_length = strlen(symbols);
    

  // We need to seed the random number generator with a value that will be
  // different each time our program runs in order to get different sequences
  // of random numbers each time our program runs.  time(NULL) will give us 
  // the current time as represented by an integer, which will be different 
  // each time the program runs.  We multiply the current time by the process
  // id of the running program as provided by getpid() to improve the seed 
  // by making it 'more unique', and we pass this as an argument to the 
  // srand() function to seed the random number generation.
  srand(time(NULL) * getpid());
  
  // Loop through each index in the password string from i = 0 .. length and 
  // set it to a random character
  for (int i = 0; i < length; i++)
  {
    // First we randomly choose a TYPE of character by setting char_type to 
    // 0,1,2, or 3 at random.  The rand() function will return a random 
    // integer between 0 and a very large number (RAND_MAX) and % 4 will 
    // return the remainder of dividing this number by 4... i.e. either 
    // 0,1,2, or 3! 
    int char_type = rand() % 4;
    
    // Use the char_type value to determine the type of character (digit, 
    // lowercase letter, uppercase letter, symbol) for the next index
    // in the password string as specified by the counter variable i.  We 
    // then randomly select a character from the specific string literal 
    // (e.g. lowers[ ... ]) by using the same technique as above and we 
    // set the password string at this index to this character.
    //
    // i.e. rand() % lowers_length
    //
    // will give us a random integer in the range 0 ... lowers_length-1, 
    // which is exactly the range of indexes in the lowers string literal.  
    //
    if (char_type == 0)
      password[i] = digits[rand() % digits_length];
    else if (char_type == 1)
      password[i] = lowers[rand() % lowers_length];
    else if (char_type == 2)
      password[i] = uppers[rand() % uppers_length];
    else
      password[i] = symbols[rand() % symbols_length];
    
  }

  // Add the null terminator to the end of the password char array to terminate
  // the string
  password[length] = '\0';
  
  // Output the randomly generated password
  printf("Password: %s\n", password);
  
  // Free the dynamically allocated memory for the password
  free(password);


  // Important: note that C uses pseudo random number generation where the 
  // same seed value will produce the same sequence of random numbers.  It's 
  // possible that someone could determine the randomly generated password 
  // if they could determine the seed value from the time and process ID.  We 
  // would need to use more advanced techniques such as "true" random number 
  // generation to improve the security of the generated password.

  return 0;
}