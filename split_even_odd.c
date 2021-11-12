/*******************************************************************************
*
* Program: Split Even And Odd Elements Of An Array Into Two Arrays
* 
* Description: Example of how to split the even and odd elements of an array
* into two other arrays in C, using two different techniques.  One technique
* is to create arrays of equal length, the other technique is more (memory)
* efficient and creates arrays that are exactly large enough to store the 
* even and odd values.
*
* YouTube Lesson: https://www.youtube.com/watch?v=9r3WX0mDG4o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void split_nums(int array[], int array_length,
                int **odd, int *odd_length,
                int **even, int *even_length);

int main(void)
{
  // test array and length
  int array[] = {1,2,3,4,5,6,7,8,9,10};
  int array_length = 10;
  
  // ********* FIXED ARRAY SIZE TECHNIQUE *********
  
  // In this technique we create even and odd arrays of the same length as the 
  // original array, which are then large enough to store the maximum possible
  // number of even and odd numbers.  But this will leave much of the 
  // memory/elements in each array unused as twice the space as necessary is 
  // being declared!
  //
  
  // declare the arrays
  int even_array[array_length], odd_array[array_length];
  
  // count the number of odd numbers, store them into odd_array, remember that
  // odd integers have a remainder of 1 when divided by 2
  int odd_count = 0;
  for (int i = 0; i < array_length; i++)
    if (array[i] % 2 == 1)
    {
      odd_array[odd_count] = array[i];
      odd_count++;
    }

  // count the number of even numbers, store them into even_array, remember that
  // even integers have a remainder of 0 when divided by 2  
  int even_count = 0;
  for (int i = 0; i < array_length; i++)
    if (array[i] % 2 == 0)
    {
      even_array[even_count] = array[i];
      even_count++;
    }
  
  // output the contents of the odd array
  for (int i = 0; i < odd_count; i++)
    printf("odd_array[%d] = %d\n", i , odd_array[i]);
  
  // output the contents of the even array
  printf("\n");
  for (int i = 0; i < even_count; i++)
    printf("even_array[%d] = %d\n", i, even_array[i]);
  printf("\n");
  

  // ********* DYNAMIC ARRAY SIZE TECHNIQUE *********
  
  // In this technique we dynamically allocate arrays that are exactly large 
  // enough to store the number of even and odd integers required.  This 
  // technique is more efficient in terms of the amount of memory used.
  //  

  // split_nums will accept pointers (i.e. memory addresses) to all these 
  // variables and it will set them accordingly
  int *even = NULL, *odd = NULL;
  int even_length = 0, odd_length = 0;
  
  // call split_nums to conduct the split... even and odd will become dynamic 
  // arrays and even_length and odd_length will store their lengths
  split_nums(array, array_length,
             &odd, &odd_length,
             &even, &even_length);
  
  // output the contents of the even array
  for (int i = 0; i < even_length; i++)
    printf("even[%d] = %d\n", i, even[i]);
  
  // output the contents of the odd array
  printf("\n");
  for (int i = 0; i < odd_length; i++)
    printf("odd[%d] = %d\n", i, odd[i]);
  
  
  return 0;
}

// accepts the array and its length as 'input', and uses pointers to 'return'
// an odd array, its length, and even array, and its length
void split_nums(int array[], int array_length,
                int **odd, int *odd_length,
                int **even, int *even_length)
{
  // init the values pointed to by odd_length and even_length to 0, we'll use 
  // these to keep a count and ultimately a total of how many even and odd 
  // integers are in the array
  *odd_length = 0;
  *even_length = 0;
  
  // loop over the array and count the odd and even integers
  for (int i = 0; i < array_length; i++)
    if (array[i] % 2 == 1)
      *odd_length = *odd_length + 1;
    else
      *even_length = *even_length + 1;
  
  // allocate enough space to store the number of even and odd integers that 
  // were found into each array
  *odd = malloc(*odd_length * sizeof(int));
  *even = malloc(*even_length * sizeof(int));
  
  // loop over the array again and this time store into the odd and even arrays
  // that have now been created the odd and even values themselves
  int array_count = 0, even_count = 0, odd_count = 0;
  while (array_count < array_length)
  {
    if (array[array_count] % 2 == 1)
    {
      // odd is a pointer to a pointer (an array), and so we dereference the 
      // pointer *first* before we access the array itself with array syntax
      (*odd)[odd_count] = array[array_count];
      odd_count++;
    }
    else
    {
      // we do the same as above, but this time with even
      (*even)[even_count] = array[array_count];
      even_count++;
    }
    array_count++;
  }
}
