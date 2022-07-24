/*******************************************************************************
*
* Program: array vs &array Pointers Difference Explained
* 
* Description: A C example demonstrating the difference between the pointer we 
* get when an array decays to a pointer compared to using the & operator with 
* the array.
*
* YouTube Lesson: https://www.youtube.com/watch?v=WL1P6xiA_KY  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // declare an array of 5 ints
  int array[5];
  
  // We can access array elements using the index operator, but if we just use 
  // the array name 'array' instead the array will "decay to a pointer"
  array[2] = 5;
  
  // When we just use the array name 'array' the array 'decays to a pointer' and
  // what we get is a pointer to the first element in the array... i.e. the first 
  // int in the array.  On the machine/compiler this program was first run on 
  // int values take up 4 bytes.  If we use the pointer arithmetic '+ 1' with 
  // the resulting pointer, we'll get 4 bytes added to the memory address 
  // because the pointer we get when array decays to pointer points to something
  // of that size.  We output the memory addresses below using zu instead of p 
  // so we can see the effect more clearly (p will give us a hexidecimal number
  // as output).  We'll find that array results in a certain memory address and 
  // array + 1 results in a memory address 4 bytes higher.
  printf("     array: %zu\n", array);
  printf(" array + 1: %zu\n\n", array + 1);
  
  // &array will give us a pointer to the ENTIRE ARRAY of 5 ints.  The memory 
  // address will be the same as when array decays to pointer in the above 
  // example because the array starts at the same memory address as the first 
  // element. But because &array is a pointer to the entire array, when we use
  // pointer arithmetic with '+ 1' we will get the size of what &array is 
  // pointing to added to the memory address.... and &array is pointing to an 
  // array of 5 ints so we have 5 x 4 bytes per int = 20 bytes.  So the memory 
  // address resulting from &array + 1 should be 20 bytes more than the memory 
  // address of &array!  This is the difference between the two pointers!
  printf("    &array: %zu\n", &array);
  printf("&array + 1: %zu\n\n", &array + 1);
  

  // This effect will show up when working with 2D arrays, here we declare a
  // 2D array of 3 rows and 5 columns.
  int matrix[3][5] =
  {
    {0,1,2,3,4},
    {5,6,7,8,9},
    {10,11,12,13,14}
  };
  
  // matrix[1] will give us a pointer to the first element of the 2nd row of 
  // the 2D array.  And again because this is an int, when we use pointer 
  // arithmetic with matrix[1] + 1 we'll get a pointer to the 2nd element of
  // the 2nd row of the 2D array which will be 4 bytes more than matrix[1].
  // If we de-reference the pointer we'll then output 6.
  printf("        matrix[1]: %zu\n", matrix[1]);
  printf("    matrix[1] + 1: %zu\n", matrix[1] + 1);
  printf(" *(matrix[1] + 1): %zu\n\n", *(matrix[1] + 1));
  
  // With &matrix[1] we'll get a pointer to the entire 2nd row of the 2d array
  // which is 5 ints in length as we have 5 columns in the 2d array.  So when 
  // we output &matrix[1] + 1 we expect it to be 20 bytes more than &matrix[1].
  // The + 1 will result in a pointer to the 3rd row of the 2d array.
  // When we de-reference &matrix[1] + 1 with * we might expect it to output 
  // 10, as &matrix[1] + 1 does result in the memory address that element is 
  // stored at as it is the first element of the 3rd row.  But &matrix[1] + 1
  // is a pointer to the entire 3rd row of the 2d array (an array of 5 elements)
  // and so when we apply the * operator we actually get back a pointer to the 
  // first element of that array... the element 10.  So we actually ouput a 
  // memory address - the same memory address - as a result of that de-reference
  // operator. 
  printf("       &matrix[1]: %zu\n", &matrix[1]);
  printf("   &matrix[1] + 1: %zu\n", &matrix[1] + 1);
  printf("*(&matrix[1] +1 ): %zu\n\n", *(&matrix[1] + 1));
  
  // If we were to type cast the memory address (pointer) that results from 
  // &matrix[1] + 1 to be a pointer to an int, THEN we can output the element 
  // 10 as de-referencing the pointer will access that value as it IS now a 
  // pointer to an int instead of a pointer to an array of 5 ints!
  int *pointer = (int *) (&matrix[1] + 1);
  
  // If we output the memory address stored in pointer, it will be the exact
  // same as &matrix[1] + 1.  BUT now when we de-reference the pointer with 
  // *pointer because it is a pointer to an int we actually will output the 
  // int value 10 that's stored at this memory address.
  printf("pointer: %zu\n", pointer);
  printf("*pointer: %zu\n", *pointer);
  
  // &matrix[1] + 1 returns a pointer to the 3rd row of the array, by applying
  // the de-reference operator once we get a pointer to the first element 
  // of that array, and if we apply it AGAIN we get the value of that first 
  // element, 10!
  printf("*(*(&matrix[1] + 1)): %zu\n", *(*(&matrix[1] + 1)));

  return 0;
}