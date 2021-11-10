/*******************************************************************************
*
* Program: Return Multiple Dynamically Allocated Arrays From A Function
* 
* Description: Example of how to return multiple dynamically allocated arrays
* from a function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=qhJLVxXMBE8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int *create_dynamic(int length);
void return_two(int *a, int *b);
void allocate_two(int **a1, int **a2, int length);

int main(void)
{
  // array stores the memory address of the dynamically allocated array 
  // that is returned by create_dynamic
  int *array = create_dynamic(10);
  
  // output the values of create_dynamic to ensure the array is OK
  for (int i = 0; i < 10; i++)
    printf("array[%d] = %d\n", i, array[i]);
  

  // set ints x and y to some initial values
  int x = 4, y = 5;
  
  // we provide the memory addresses of x and y to return_two, it will use these
  // to set the values of x and y in THIS function, which is called 
  // pass-by-pointer (or often informally pass-by-reference)
  return_two(&x, &y);

  // verify that x and y have been set be return_two
  printf("x: %d\ny: %d\n", x, y);
  

  // array1 & array2 will store memory addresses of dynamically allocated arrays
  int *array1, *array2;
  
  // allocate_two is passed memory addresses of pointer variables... i.e. memory
  // addresses of variables that are themselves intended to store memory 
  // addresses... allocate_two will set array1 and array2 to point to 
  // dynamically allocated arrays
  allocate_two(&array1, &array2, 10);
  
  // verify that array1 and array2 contain the expected values
  for (int i = 0; i < 10; i++)
  {
    printf("array1[%d] = %d\n", i, array1[i]);
    printf("array2[%d] = %d\n", i, array2[i]);
  }
  
  return 0;
}

// dynamically allocates a single array of ints with the given length and 
// returns a pointer (i.e. memory address) to the array
int *create_dynamic(int length)
{
  // dynamically allocate the array with the given length
  int *a = malloc(sizeof(int) * length);
  
  // populate the array with ints from 0 - (length-1)
  for (int i = 0; i < length; i++) a[i] = i;
  
  // return the pointer (i.e. memory address)
  return a;
}

// "returns" two values 10 and 20 by de-referencing the pointer parameters 
// a and b to set the variables they are pointing to to values 10 and 20
void return_two(int *a, int *b)
{
  *a = 10;
  *b = 20;
}

// Dynamically allocates TWO arrays and "returns" a pointer (i.e. memory 
// address) to the two arrays via the pointer-TO-pointer parameters a1 and
// a2.  The arrays are created with the size of the given length argument.
//
// This function combines concepts from the above two functions in order 
// to work.
//
void allocate_two(int **a1, int **a2, int length)
{
  // de-referencing a1 and a2 results in a pointer... because a1 and a2 are 
  // pointers TO pointers... so when we deference these pointers we actually 
  // access a pointer... and this is where we save the memory addresses of 
  // the dynamically allocated blocks of memory
  *a1 = malloc(sizeof(int) * length);
  *a2 = malloc(sizeof(int) * length);
  
  // in order to populate the dynamically allocated arrays we've created with
  // data, we need to dereference a1 and a2 and THEN apply array notation... 
  // that's because a1 and a2 are pointers to the pointers to store memory 
  // address of these arrays... by derefencing them we access the memory address
  // of the arrays and can then use array notation to set values in the arrays! 
  for (int i = 0; i < length; i++)
  {
    (*a1)[i] = i;
    (*a2)[i] = length - i;
  }
}



