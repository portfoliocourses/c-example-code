/*******************************************************************************
*
* Program: Delete Array Elements Based On User Input
* 
* Description: Example of how to "delete" all array elements in C that match 
* a value provided by user input.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1uf75EJsveU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // create the array
  int buffer[100] = {2,1,4,5,6,7,7,5,4,4};
  
  // we'll use a variable size to keep track of how many array elements are 
  // actually 'in use' and consider this to be the 'size' of our array (even 
  // though the array can contain up to 100 elements total)
  int size = 10;

  // stores the value to be deleted from the array
  int delete = 0;
  
  // print out the array before deleting
  for (int i = 0; i < size; i++)
    printf("%d ", buffer[i]);
  printf("\n\n");
 
  // ask the user for the value to be deleted from the array, store it into 
  // the delete variable 
  printf("Enter Number To Delete: ");
  scanf("%d", &delete);
  
  // loop through the array one index at a time until we reach the array size
  int i = 0;
  while (i < size)
  {
    // if the element at the current index matches the element to be deleted, 
    // then we need to delete the element from the array
    if (buffer[i] == delete)
    {
      // if it is NOT the last element of the array that is being deleted, 
      // then pull forward all remaining elements in the array after this 
      // element to be deleted by one index
      //
      // e.g. if we had 4,5,6,7,2,3,5
      //
      //      and we want to delete 7, then after the array should look like:
      //
      //      4,5,6,2,3,5
      //
      if (i < (size - 1))
        for (int j = i; j < (size - 1); j++)
          buffer[j] = buffer[j + 1];

      // decrease the size of the array by 1 in recognition that we have just 
      // deleted an element... if we are deleting the last element of the array
      // then this is all that is necessary to 'delete' the element from the 
      // array as we consider size to be the size of the array for our purposes
      size--;
    }
    // we only increment i if we did not delete an element because it's possible
    // that the NEXT element in the array (which was just pulled forward into 
    // index i) ALSO matches the element to be deleted
    else i++;  
  }
  
  // print out the array after conducting the delete
  printf("\n");
  for (int i = 0; i < size; i++)
    printf("%d ", buffer[i]);
  printf("\n\n");
  
  return 0;
}