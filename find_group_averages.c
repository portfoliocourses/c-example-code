/*******************************************************************************
*
* Program: Find Average Of Groups Of Numbers In A File
* 
* Description: Example of finding the average of groups of numbers in a file
* using C.  This is a solution to the problem described here:
* http://cplusplus.com/forum/beginner/165952/
*
* YouTube Lesson: https://www.youtube.com/watch?v=kMAg6diYCI0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  FILE *numbers_file;
  
  // open the file for reading, the file is assumed to have the content:
  //
  // 5 96 87 78 93 21 4 92 82 85 87 6 72 69 85 75 81 73
  //
  // Where the numbers 5, 4 and 6 indicate the size of the next group of numbers
  // and the subsequent 5, 4 and 6 numbers are part of each group of numbers.
  //
  numbers_file = fopen("numbers.dat", "r");

  // if file did not open successfully, warn the user, and exit with an error
  if (numbers_file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  double next_number = 0;
  int remaining_group_numbers = 0;
  int group_length;
  double total = 0;
  
  // keep reading in numbers until we reach the end of the file
  while (!feof(numbers_file))
  {
    // remaining_group_numbers will keep track of how many numbers are 
    // remaining in a group of numbers, and when it reaches zero, we expect 
    // the next number in the file to be a number specifying how many numbers
    // are in the next group of numbers
    if (remaining_group_numbers == 0)
    {
      // read in the group length number, reset remaining_group_numbers
      fscanf(numbers_file, "%d", &group_length);
      remaining_group_numbers = group_length;

      // output how many elements are in the next group
      printf("The number of elements in this group is %d\n", group_length);
      printf("The data in this group is: ");
    }
    // if more numbers are left to be read in the remaining group, read in 
    // that number
    else 
    {
      // read in the number and output it as part of the list of group data
      fscanf(numbers_file, "%lf", &next_number);
      printf("%.0lf ", next_number);
      
      // add the number to the total so we can compute the average, decrement
      // remaining_group_numbers as we have now processed another group number
      total += next_number;
      remaining_group_numbers--;
      
      // if there are no more numbers remaining in the group, we can now compute
      // the average, output it, and reset the total
      if (remaining_group_numbers == 0)
      {
        printf("\nAverage: %.2f\n\n", total / group_length );
        total = 0;
      }
    }
  }

  return 0;
}