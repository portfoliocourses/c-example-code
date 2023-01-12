/*******************************************************************************
*
* Program: Delete An Array Element At A Specific Index 
* 
* Description: Example of deleting an array element at a specific index using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=xef-jecZPPw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// The maximum capacity (length) of the array... the array will not necessarily
// store this many values.
#define MAX_CAPACITY 100

int main()
{
  // Declare the array with the length set to MAX_CAPACITY
  int array[MAX_CAPACITY];

  // total will store the total amount of values actually stored in the array
  int total = 0;

  // stores the index of the value to delete from the array
  int delete_index = 0;
  
  // Prompt the user to enter the total amount of values to store, and store 
  // what the user enters into total
  printf("Enter Total Number Of Values To Store: ");
  scanf("%d", &total);
  
  // Prompt the user to enter total amount of value, storing each value entered
  // into the array in the order they were entered starting at the first inde
  for (int i = 0; i < total; i++)
  {
    printf("array[%d] = ", i);
    scanf("%d", &array[i]);
  }
  printf("\n");
  
  // Output the values in the array (separated by spaces) to confirm they were 
  // stored correctly
  printf("array = ");
  for (int i = 0; i < total; i++)
    printf("%d ", array[i]);
  printf("\n\n");
  
  // Prompt the user to enter the index of the value to delete, store the index 
  // entered into the delete_index variable
  printf("Enter Value Index To Delete: ");
  scanf("%d", &delete_index);
  printf("\n");
  
  // To delete the value from the array at delete_index, we'll shift up by 1 
  // index all the values in the array at the index delete_index + 1 onward.
  // We'll also decrement total to acknowledge the array now stores one less
  // value.
  //
  //  Before delete...
  //
  //                    __  __  __
  //                   ↓  \↓  \↓  \
  //  index:   0   1   2   3   4   5
  //  value:   9   8   7   6   5   4
  //
  //  total: 6 
  //
  // 
  //  After delete...
  //                  
  //  index:   0   1   2   3   4   5
  //  value:   9   8   6   5   4
  //
  //  total: 5
  
  // Shift the from from delete_index + 1 onwards up by 1, and decrement total,
  // in order to delete the element at the index delete_index
  for (int i = delete_index; i < total; i++)
    array[i] = array[i + 1];
  total--;
  
  // Output the values stored in the array to confirm the value was deleted
  printf("array = ");
  for (int i = 0; i < total; i++)
    printf("%d ", array[i]);
  printf("\n\n"); ¢  
  
  return 0;
}
