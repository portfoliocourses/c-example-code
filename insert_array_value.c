/*******************************************************************************
*
* Program: Insert A Value Into An Array At A Specific Position 
* 
* Description: Example of inserting a value into an array at a specific index 
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nIJvKd5I1cY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Defines the maximum number of values that the array can possibly store.  We
// use the array as a more general data structure and make a distinction between
// the capacity of the array (i.e. its size/length) and the total number of 
// values stored in the array.
#define MAX_CAPACITY 100

int main()
{
  // Declare the array with the length of MAX_CAPACITY 
  int array[MAX_CAPACITY];
  
  // Keeps track of the total values stored in the array
  int total = 0;
  
  // Store the value to insert, and the index to insert the value at
  int insert_index = 0;
  int insert_value = 0;

  // Prompt the user to enter the total values to store, and store the value 
  // they enter into the variable total
  printf("Enter Total Number Of Values To Store: ");
  scanf("%d", &total);
  
  // We also can't store a total number of values that exceeds the capacity of
  // the array so we exit with an error message and status in this case too.
  if (total > MAX_CAPACITY)
  {
    printf("Error: Total exceeds max array capacity.\n");
    return 1;
  }
  
  // A total less than 0 makes no sense so we can output an error message and
  // return 1, which will cause our program to exit with a status of 1 which
  // is a signal to the shell/terminal that something has gone wrong in the
  // execution of our program.
  if (total < 0)
  {
    printf("Error: Total must be >= 0.\n");
    return 1;
  }
  
  // Prompt the user to enter total number of values and store them into the
  // array at the index from 0 ... total-1.  We output the index that the 
  // value the user is about to enter next will be stored at.
  for (int i = 0; i < total; i++)
  {
    printf("array[%d] = ", i);
    scanf("%d", &array[i]);
  }
  
  // Output the values stored in the array separated by spaces 
  printf("\n");
  printf("array = ");
  for (int i = 0; i < total; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n\n");
  
  // Prompt the user to enter the value to be inserted, store the value entered
  // into the insert_value variable.
  printf("Enter Value To Insert: ");
  scanf("%d", &insert_value);
  
  // Prompt the user to enter the index to insert the value, store the value 
  // entered into the insert_index variable.
  printf("Enter Index To Insert Value At: ");
  scanf("%d", &insert_index);
  
  // An insert_index less than 0 is invalid, so we could exit with an error
  // message and status.  We could also optionally say that the valid indexes
  // to insert a value range from 0 ... total, i.e. the index one beyond the 
  // last index used to store a value into the array.  And we could exit with
  // an error message and status if the user enters an index beyond this 
  // index as well.
  if (insert_index < 0 || insert_index > total)
  {
    printf("Error: Index out of range.\n");
    return 1;
  }
  
  // If the total has already reached the max capacity, we cannot insert 
  // another value and we could exit with an error message and status.
  if (total == MAX_CAPACITY)
  {
    printf("Error: Array at max capacity already.\n");
    return 1;
  }
  
  //  Before inserting 2 at index 2...
  //
  //                     ___ ___ ___
  //                    /  ↓/  ↓/  ↓
  //  index:   0   1   2   3   4   5  ...
  //  value:   9   8   7   6   5   ~  ...
  //
  //  total: 5
  //
  // If we have an array storing 5 total values: 9 8 7 6 5, it will look like
  // the above.  If we want to insert the value 2 at the index 2, we need to
  // shift over all the values stored at the index 2 onwards to the right by 
  // one index in order to make room for 2.  
  //
  //  After insert the array should look like this...
  //
  //  index:   0   1   2   3   4   5  ...
  //  value:   9   8   2   7   6   5  ...
  //
  //  total: 6  
  // 

  // Shift all values from the insert_index to total over by 1.  We do this by
  // starting a counter variable i from the "right side" at the total index, 
  // and copying the value stored one index to the left (as given by i-1).  We
  // decrement i with each loop iteration to "move over to the left", and stop
  // once we reach the insert_index where we wish to insert the value.  We 
  // will now have made room for the value to be inserted.
  for (int i = total; i > insert_index; i--)
  {
    array[i] = array[i-1];
  }
  
  // Insert the value to be inserted at the index for it to be inserted
  array[insert_index] = insert_value;
  
  // Increment the total now that we have inserted another value into the array
  total++;
  
  // Output the values stored in the array separated by spaces so we can see the
  // affect of inserting the value into the array.
  printf("\n");
  printf("array = ");
  for (int i = 0; i < total; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n\n");
  
  return 0;
}
