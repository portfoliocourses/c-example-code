/*******************************************************************************
*
* Program: If Statement Best Practice Example
*
* Description: Example of a C programming best practice when using if-statements
* with an equality operator in the condition.
*
* YouTube Lesson: https://www.youtube.com/watch?v=iD05HmGLZXc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
  // Declare a variable percent for storing a percent the user will enter
  int percent = 0;

  // Prompt the user for the percent and store it into the perecent variable
  printf("Enter Percent Complete: ");
  scanf("%d", &percent);

  // We want the program to output "Work Done!" if the percent is equal to 100
  // and "Work Not Done Yet!" if it is not.  We could write the below code
  // like like this, which is probably the most natural way of thinking about
  // "checking if perecent is equal to 100":
  //
  //   if (percent == 100)
  //     printf("Work Done!\n");
  //   else
  //     printf("Work Not Done Yet!\n");
  //
  // And it would function correctly.  The issue is that if we made a typo when
  // entering this code and forget the second equals symbol in the equality
  // operator, we would instead get the assignment operator:
  //
  //   if (percent = 100)
  //     printf("Work Done!\n");
  //   else
  //     printf("Work Not Done Yet!\n");
  //
  // This would actually be VALID C code!  So despite the fact that our program
  // would have a bug, the compiler would not flag this issue for us.  The
  // assignment operator = would assign the value 100 to perecent, potentially
  // altering whatever the user entered (i.e. if the user did not enter 100
  // already).  The assignment statement itself would evalaute in the value 100
  // which is considered true, and we would output "Work Done!" no matter what
  // the user entered for percent!
  //
  // If we write our conditions involving equality operator as:
  //
  // if (variable == value) ...
  //
  // Our program will be vulnerable to this sort of bug occurring.
  //
  // Instead if write conditions involving the equality operato as:
  //
  // if (value == variable)
  //
  // THEN if we forget the second equals symbol, we would get:
  //
  // if (value = variable)
  //
  // Which WILL result in a compiler error as we cannot assign to a value in C!
  // So at least with this approach, the programmer would be made aware that
  // there is a bug in the code and would have have a chance to fix it.
  //
  // So as a best practice if we get into the habit of writing our conditions
  // invovling equality operators as:
  //
  // if (value == variable)
  //
  // We can reduce the chances of this sort of bug from occurring!


  // We write our if-statement condition as value == variable, in this case
  // 100 == percent, so that if by accident we wrote 100 = percent a compiler
  // error would result.  Try out some of the different conditions discussed in
  // these comments to see the affect.
  if (100 == percent)
    printf("Work Done!\n");
  else
    printf("Work Not Done Yet!\n");

  printf("percent: %d\n", percent);

  return 0;
}