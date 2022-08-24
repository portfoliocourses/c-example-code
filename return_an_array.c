/*******************************************************************************
*
* Program: Return An Array From A Function
*
* Description: Examples of how to "return" an array from a function in C.  In C
* we can't actually return an array from a function, but we can achieve more or
* less the same effect by using pointers.
*
* YouTube Lesson: https://www.youtube.com/watch?v=uI1J8o1rY10
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// We can't actually return an array from a function in C, if we uncommment
// the below code where we try to do so we'll get a compiler error as
// this is not allowed in C.
/*
int[] set_array()
{

}
*/


// What we can do is return a pointer to an array... i.e. a pointer to an int
// that stores the memory address of the first element in the array.  We
// can then use that pointer to effectively access the array using array
// index syntax (see the main function).  BUT the pointer returned cannot
// be a pointer to an array that is a local variable of the function, as in
// the below example.  The local_array[] array has the lifetime of each
// function call to set_array(), once the function returns, the variable
// no longer exists.  So when we try to use the pointer that is returned
// from this function call, it's pointing to memory that we don't have
// access to anymore!
//
/*
int *set_array(int value)
{
  int local_array[5];

  for (int i = 0; i < 5; i++)
    local_array[i] = value;

  return local_array;
}
*/

// One common approach to "return" an array from a function is to actually
// accept a pointer to an array as a parameter.  The function can then use
// array index notation like array[i] to manipulate the values of the array,
// effectively "returning" a new array of values.  The array itself can be
// declared in the main function (or another function) and when the pointer
// to the array is passed to the function as an argument, and the function
// then returns, the array will still exist!  This and the other set_array()
// functions will set all array elements to a provided value.
void set_array1(int value, int *array)
{
  for (int i = 0; i < 5; i++)
    array[i] = value;
}

// We could also use dynamic memory allocation to dynamically allocate space
// for the array on the heap.  Here we use malloc to allocate space for an
// array of 5 ints, we set the values, and then we return a pointer to this
// block of memory which we can then treat as an array.  Dynamically allocated
// memory is in a different part of memory called the heap that we need to
// manage ourselves by later calling free to the free dynamically allocated
// memory (in order to make the memory available to our program again for
// later use).  Local varibles are kept in a different part of memory called
// the stack, and they will cease to exist when the function returns.
int *set_array2(int value)
{
  int *array = malloc(sizeof(int) * 5);

  for (int i = 0; i < 5; i++)
    array[i] = value;

  return array;
}

// We could also use the static keyword to create a static array of ints.  A
// static variable has the lifetime of the entire program's execution, instead
// of each function call to set_array3().  This means even after the function
// returns, the array will still exist in memory, and if we return a pointer to
// this array to main as we do here, the main function can use the pointer
// to access the array!
int *set_array3(int value)
{
  static int array[5];

  for (int i = 0; i < 5; i++)
    array[i] = value;

  return array;
}

int main()
{
  // Declare an array of 5 ints locally
  int array[] = {1,2,3,4,5};

  // When we use the identifier 'array' like this it decays to a pointer and
  // we pass the memory address of the first element in the array (i.e. a
  // 'pointer to the array') to the set_array1() function.  That function can
  // then use that pointer to manipulate this array in main and change its
  // values, effectively "returning" a new array.
  set_array1(4, array);

  // Print out the array element values to verify they have all been set to 4
  for (int i = 0; i < 5; i++)
    printf("array[%d] = %d\n", i, array[i]);


  // The set_array2() function returns a pointer to a dynmically allocated
  // block of memory that we store into result2.  We can use this memory address
  // like an array and access elements with result2[4], etc.  We would say this
  // is a "dynmically allocated array".
  int *result2 = set_array2(4);

  // Print out the elements of the array that result2 points to, to verify they
  // have all been set to 4
  for (int i = 0; i < 5; i++)
    printf("result2[%d] = %d\n", i, result2[i]);

  // Free the dynamically allocated memory.  If we forgot to do this, we would
  // have a memory leak as a place in memory would be set aside to store 5
  // ints, but our program would no longer be using it.  This is a drawback
  // of this approach, but to an extent this is just we do things in C too.
  free(result2);


  // set_array3() has a static array of ints... which means the array will
  // exist for the entire liftime of the program, and when set_array3() returns
  // a pointer to this array (i.e. a pointer to the first element of this
  // array), we can use the pointer to acces the array in our main function
  // knowing the array will still exist in memory even though the function
  // has returned!
  int *result3 = set_array3(4);

  // Print out the elements of the array that result3 points to, to verify they
  // have all been set to 4
  for (int i = 0; i < 5; i++)
    printf("result3[%d] = %d\n", i, result3[i]);

  return 0;
}