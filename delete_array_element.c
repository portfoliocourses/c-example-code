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

#define MAX_CAPACITY 100

int main()
{
  int array[MAX_CAPACITY];
  int total = 0;
  int delete_index = 0;
  
  printf("Enter Total Number Of Values To Store: ");
  scanf("%d", &total);
  
  for (int i = 0; i < total; i++)
  {
    printf("array[%d] = ", i);
    scanf("%d", &array[i]);
  }
  printf("\n");
  
  printf("array = ");
  for (int i = 0; i < total; i++)
    printf("%d ", array[i]);
  printf("\n\n");
  
  printf("Enter Value Index To Delete: ");
  scanf("%d", &delete_index);
  printf("\n");
  
  //                    __  __  __
  //                   ↓  \↓  \↓  \
  //  index:   0   1   2   3   4   5
  //  value:   9   8   6   5   4
  //
  //  total: 5
  
  for (int i = delete_index; i < total; i++)
    array[i] = array[i + 1];
  total--;
  
  printf("array = ");
  for (int i = 0; i < total; i++)
    printf("%d ", array[i]);
  printf("\n\n"); ¢  
  
  return 0;
}