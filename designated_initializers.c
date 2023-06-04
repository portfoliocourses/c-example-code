/*******************************************************************************
*
* Program: Designated Initializers For Arrays
* 
* Description: Examples of using designated initializers in C to initialize 
* array elements.  Designated initializers allow us to initialize array elements
* with more flexibility, for example we can use them to initialize array 
* elements out of order.  Designated initializers are supported in C99 onwards
* and so will work in newer versions of C from this version onwards.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zL_pcJq6Lws 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// A simple function which accepts an int as an argument and returns that int 
// value incremented by 1
int function(int a)
{
  return a + 1;
}

int main(void)
{
  // Uncomment the different array initializations below and see the output...

  // Typically an array is initialized like this... with each element
  // initialized in order
  //
  // int array[10] = {1,2,3,4,5,6,7,8,9,10};
  
  // Designated initializers allow us to initialize array elements by only 
  // explicitly initializing some elements, and doing so out of order.  The 
  // below will initialize the element at the index 3 to 20 and the element at
  // the index 5 to 50, and all other elements will be initialized with 0.
  // Notably designated initializers are only supported in versions of C from
  // C99 onwards so they will not work in older versions of C.
  //
  // int array[10] = { [3] = 20, [5] = 50 };
  
  // So the above initialization is equivalent to this...
  //
  // int array[10] = {0,0,0,20,0,50,0,0,0,0};
  
  // We can initialize the array elements "out of order" like this...
  //
  // int array[10] = { [5] = 50, [3] = 20 };
  
  // If we don't include the length of the array in the declaration its length
  // will be set to 1 more than the last index initialized, so in the below 
  // example the array will be declared with a length of 6 as the last index 
  // initialized is 5.
  //
  // int array[] = {[3] = 20, [5] = 50};
  
  // We can initialize elements after those initialized using the designated 
  // initializer, so the below will initialize the element at the index 1 to 3,
  // and the elements at the indexes 2 and 3 to 9 and 5.  And the element at the
  // index 7 will be initialized to 2, and the element at the index 8 will be 
  // initialized to 8.
  // 
  // int array[10] = { [1] = 3, 9, 5, [7] = 2, 8};
  
  // We can initialize an element using an expression or function call, 
  // example the below will initialize the element at the index 4 to the value
  // 5 when the function returns 5.
  //
  // int array[10] = { [4] = function(4) };
  
  // But the index itself must be an integer constant expression, the below 
  // code will produce a compiler error because the index is not an integer 
  // constant expression.
  //
  // int array[10] = { [function(4)] = function(7) };
  
  // This is not part of the C Standard, so it will not work across all 
  // compilers, it is a GNU extension that some compilers support.  But we can
  // initialize elements across a range of indexes, the below code will 
  // initialize the elements in the range 0 - 4 to 4 and the elements in the 
  // range 5 - 9 to 7.
  //
  int array[] = { [0 ... 4] = 4, [5 ... 9] = 7 };
  
  // Output the array element value at each index so we can see the result of 
  // the different initializations above.
  for (int i = 0; i < 10; i++)
  {
    printf("array[%d] = %d\n", i, array[i]);
  }
  
  return 0;
}