/*******************************************************************************
*
* Program: Token-Pasting Operator Demonstration
* 
* Description: Examples of using the token-pasting operator in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Cl2rinXQWgs  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Function-like macro uses ## token-pasting operator to join together tokens, 
// prefixing x with 'Big'.
#define print(x) printf("%s\n", Big##x);

// Function-like macro uses ## token-pasting operator to join together command
// name with _instruction to complete the name of the function to call for that 
// instruction.  Also uses # stringizing operator to create string literal for 
// the name of the instruction.  The macro is used to initialize an array of 
// Instruction structs.
#define INSTRUCTION(NAME) \
  { #NAME, NAME ## _instruction }

// struct for representing an "Instruction" with a name and function pointer 
// to an associated functions
typedef struct 
{
  char name[100];
  void (*function) (void);
} Instruction;

// add instruction function
void add_instruction(void)
{
  printf("add instruction");
}

// subtract instruction function
void subtract_instruction(void)
{
  printf("subtract instruction");
}

int main()
{
  // Initialize char arrays BigApple and BigPear
  char BigApple[] = "Big Apple";
  char BigPear[] = "Big Pear";
  
  // The function-like macro will prefix Apple and Pear with Big to produce 
  // the new tokens BigApple and BigPear which can be used to print out the 
  // above char arrays using the printf of the function-like macro.
  print(Apple)
  print(Pear)
  
  // Create an array of Instructions using our function-like macro to 
  // help initialize each instruction.  The function like macro prevents us 
  // from having to repeat the text 'add' and 'subtract' when initializing 
  // each struct as in the below example.
  Instruction instructions[] = 
  {
    INSTRUCTION(add),
    INSTRUCTION(subtract)
  };

  // Without the function-like macro and the token-pasting operator we would
  // initialize the Instructions array like this, repeating the 'add' and 
  // 'subtract' text.
  /*
  Instruction instructions[] =
  {
    {"add", add_instruction},
    {"subtract", subtract_instruction}
  };
  */
  
  // Output each Instruction's name nad call it's function to see the result
  for (int i = 0; i < 2; i++)
  {
    printf("\n");
    printf("Name: %s\n", instructions[i].name);
    instructions[i].function();
  }

  return 0;
}