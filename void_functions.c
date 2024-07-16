/*******************************************************************************
*
* Program: Void Functions
*
* Description: Example of a void function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=jOoiVmVUy-Q
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

void print_array(int array[], int length);
int add(int a, int b);

int main(void)
{
  // A "value-returning function" like add() returns a value that we can use 
  // somehow, like assigning it to a variable.
  int sum = add(10,5);

  // Output the resulting sum
  printf("Sum: %d\n", sum);

  // A test array of numbers to print out
  int numbers[] = {5,6,7,8,9};

  // A void function does not return a value, so we don't assign any 
  // return value to a variable in this case, we simply call the function.
  //
  // Void functions are sometimes called non value returning functions.
  // 
  // One reason we create functions is so that we don't have to repeat 
  // the same code in different places in our program, instead we can 
  // write the code once and execute it by calling the function.  Not all
  // code produces or calculates a value, some code does other work such
  // as outputting values or information.  So a void function that does 
  // not return a value can still be useful this and other reasons why 
  // functions are useful.
  //
  print_array(numbers, 5);
  
  // The void function does not return a value so we can't store a 
  // return value into a variable like this.
  //
  // int return_value = print_array(numbers, 5);

  // Void functions actually can use return statements to stop the execution
  // of the function, as this function does if the length argument value is
  // less than or equal to 0.
  print_array(numbers, -5);
  
  return 0;
}

// A void function which prints out the values stored in the array with hte 
// provided length.
//
// The function does not have to have a return statement anywhere, execution
// of the function will simply stop when the end of the function body is 
// reached.  We can optionally include return statements though as in this 
// example, to stop the execution of the function "early".
void print_array(int array[], int length)
{
  // An array with a length <= 0 does not make sense so we stop the function
  // using return in this case
  if (length <= 0) return ;
  
  // Otherwise we use a loop with a counter variable i to go through the 
  // indexes of the array from 0, 1, ..., length-1, and we output each 
  // value in the array separated by a space.  We output a newline after 
  // all the values in the array have been output.
  for (int i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// A value returning function that returns the sum of parameters 'a' and 'b'
int add(int a, int b)
{
  return a + b;
}
