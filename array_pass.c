/*******************************************************************************
*
* Program: Passing an array to a function
* 
* Description: Example of passing an array to a function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=oe2bZKjiWrg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void add(int x);
void array_add(int array[]);
void array_add_ptr(int *array);

int main(void)
{
  // When we pass a regular variable to a function, what's happening is that 
  // the *value* of that variable is being passed to the function as an 
  // argument, and so the function actually has no access to the variable 
  // in the calling environment, such as 'a' in this case!  We call this 
  // behaviour pass-by-value.
  int a = 5;
  add(a);

  // 'a' will be left unchanged despite the fact that the function increments 
  // the parameter x
  printf("a: %d\n", a);

  // declare an array so that we can pass it to the function
  int myarray[5] = {1,2,3,4,5};
  
  // Either function call will have the same effect, with myarray[0] beign 
  // incremented by 1 to 2.  When we pass an array to a function, what is 
  // being passed is not all the values of the array, instead of what is being 
  // passed is the memory address of the array.  We say that the array "decays 
  // to a pointer" (pointers store memory addresses).  Because the function 
  // is given a pointer/addres to the array, when it modifies the array, it 
  // will modify it in the calling environment.  We call this pass-by-reference,
  // or more accurately we can call it pass-by-pointer.
  array_add_ptr(myarray);
  // array_add(myarray);
  
  // notice thay myarray[0] will be incremented by 1!
  printf("myarray[0]: %d\n", myarray[0]);

  // when we use the array name like this, without an index such as myarray[0], 
  // we say it "decays to a pointer" (i.e. a memory address) and so what we 
  // print out here is the memory address that myarray is stored at
  printf("myarray: %p\n", myarray);

  return 0;
}

// Adds 1 to x, but because the parameter is "pass by value", it will have 
// no effect on a in the calling environment.  All that happens is that a 
// variable called x that is local to the function is set to a a value (5),
// we increment that variable x to 6, and the function is done.  The 'a' 
// variable in main has no relationship to x, it remains unchanged.
void add(int x)
{
  printf("x: %d\n", x);
  x = x + 1;
}

// This function accepts an array as a parameter.  When we pass an array to 
// the function, what will *really* be passed is not the values of the array 
// but the memory address of the array.  This allows the function to modify 
// myarray in main... we call this "pass by reference" (or more accurately 
// pass-by-pointer).
void array_add(int array[])
{
  // When we output array (without any index like array[0]), it decays to a 
  // pointer (i.e. memory address), and we'll see that the memory address is 
  // the same as the memory address of myarray in main!  When we access this 
  // array with array[0], we are using "array notation" to modify the myarray 
  // in the main function!  In essence array in array_add and myarray in 
  // the main function are the same array. 
  printf("array: %p\n", array);

  array[0] = array[0] + 1;
}

// This function is equivalent to the above!  We just use pointer notation to 
// specify the parameter this time. int array[] is the equivalent of int *array!
// Because remember that arrays "decay to pointers" when we don't access them 
// with an index, and so ultimately when we pass the array to a function, we're 
// really passing a pointer (memory address) to the function!
void array_add_ptr(int *array)
{
  printf("array: %p\n", array);
  array[0] = array[0] + 1;
}



