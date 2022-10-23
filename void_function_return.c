/*******************************************************************************
*
* Program: Return Statement In A Void Function
*
* Description: Demonstration of how to use a return statement inside a void
* function using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=GcAkeHpcX_Q
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// A non-void function is a function without a void return type, a function like
// this MUST have a return statement that returns a value of its return type.
// In the function below we return x + 1 where x is an int value provided as a
// parameter and we increment that value by 1.  When we call the function with
// increment(1) the value '2' will result.
//
// In addition to returning a value, a return statement stops the execution of a
// function.  So in the below function the call to printf() will NEVER execute
// because it will never be reached.  The return statement will stop the
// execution of the function before the printf() can be executed.
//
int increment(int x)
{
  // If we were to remove the below return statement, a compiler error will
  // result, as the function MUST return an int.
  return x + 1;

  // Will never be 'reached' and executed because the above return statement
  // will stop the execution of the function.
  printf("Ouput this!\n");
}

// A function with a void return type is called a "void function", and a void
// function does NOT need to use a return statement as it returns no value.  A
// void function may do some useful work in the form of user input and output,
// for example.
//
void length_error()
{
  printf("Invalid array length!\n");
}

// Even though a void function is not required to use a return statement, void
// functions may use return statements.  The return statements are not used to
// return a value in the case of a void function, but instead to stop the
// execution of the function.  The below void function will output the elements
// of an array of the given length.  It would not make any sense for an array
// to have a length less than 0, so we use return to stop the execution of the
// function in this case.
//
void print_array(int array[], int length)
{
  // We can use "return ;" to stop the execution of a void function, as in
  // the below line of code.  The function does NOT return a value, the return
  // statement just stops the execution of the function.
  //
  // if (length < 0) return ;

  // We can actually "return" a call to another void function in a void
  // function, as here we call the void function length_error().  No value is
  // actually returned, instead the length_error() function is called as this
  // function is itself about to stop execution.
  //
  if (length < 0) return length_error();

  // Use a loop with a counter variable i that will go from 0 up to the array
  // length incrementing by 1 with each loop iteration, which will set i to
  // each possible array index in sequence.  We use i to output each array
  // element followed by a space, and the output a newline.
  for (int i = 0; i < length; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main(void)
{
  // The increment function will return the value 2, and we output it here, this
  // is the typical use case for a return statement... to return a value.
  printf("%d\n", increment(1) );

  // Declare and initialize a simple int array with 5 elements
  int array[] = {1,2,3,4,5};

  // Call the print_array() function with an array length of -1, this will
  // cause the return statement in the function to be used.
  print_array(array, -1);

  // Output Done! so we can recogonize definitively that the above function
  // call has completed execution.
  printf("Done!\n");

  return 0;
}