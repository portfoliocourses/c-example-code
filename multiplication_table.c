/*******************************************************************************
*
* Program: Savings Calculator Demonstration
* 
* Description: Example of a savings calculator in C with a yearly investment 
* returns table.
*
* YouTube Lesson: https://www.youtube.com/watch?v=DJq9SjMGSys 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // dimension of the table, i.e. 10x10, 12x12, etc
  int n;
  
  // have the user enter a dimension greater than 0
  do
  {
    printf("Enter Dimension: ");
    scanf("%d", &n);
    if (n <= 0) printf("Dimension must be > 0\n");
  } while (n <= 0);
  
  // output the column headings of the table, with an 'x' in the top-left corner
  printf("%5s", "x");
  for (int i = 1; i <= n; i++)
    printf("%5d", i);
  printf("\n");
  
  // the outer loop will create each table row
  for (int i = 1; i <= n; i++)
  {
    // output the row heading
    printf("%5d", i);

    // output each product in each column of this row
    for (int j = 1; j <= n; j++)
    {
      printf("%5d", i * j);
    }

    // start the next row on the next line
    printf("\n");
  }
  
  return 0;
}