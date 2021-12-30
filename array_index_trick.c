/*******************************************************************************
*
* Program: Array Index Trick
* 
* Description: A 'programming trick' to access array elements in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=9A5YDGSQy9o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // declare and initialize an array of ints
  int a[] = {10,20,30,40,50};
  
  // access the 3rd element of the array with the normal array[index] syntax
  printf("a[2] = %d\n", a[2]);
  
  // access the 2nd element of the array with the unusual index[array] syntax!!
  printf("1[a] = %d\n", 1[a]);
  
  // we can also set array elements using a variable with this unusual syntax
  for (int i = 0; i < 5; i++)
    i[a] = i + 4;
  
  // print out the array elements to verify they have been set as expected
  for (int i = 0; i < 5; i++)
    printf("%d[a] = %d\n", i, i[a]);


  // Why does the index[array] syntax work?!
  //
  // Really we can think of the array[index] syntax as being a "syntactic 
  // sugar" for what's *actually* happening "under the hood" in C.  We can 
  // also use pointer notation to access array elements, for example we can 
  // use:
  //
  // *(a + 2) = 200;
  //
  // to access the 3rd element of the array and set it to 200.  The pointer 
  // arithmetic "a + 2" gives us the memory address two integers over from the 
  // memory address of array 'a' (which is the first element in the array), and
  // then we dereference the memory address with * to access the value there
  // and set it to 200.
  //
  // We can think of a[2] as *really* being translated to *(a + 2) by C.
  //

  // Now "2 + a" is the same as "a + 2" and so when we have 2[a] we can think
  // of it as being translated to *(2 + a), which is valid:
  *(2 + a) = 200;
  
  printf("a[2] = %d\n", a[2]);
  
  return 0;
}
