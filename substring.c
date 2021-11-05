/*******************************************************************************
*
* Program: Substring Function
* 
* Description: Example of a substring function implementation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0X2oYHzvw0g 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void substring(char *orig, char *substr, int index, int length);

int main()
{
  // imagine that 100, 400 and 3434 are meaningful portions of the string below
  // we wish to extract as substrings... maybe a part number, manufacturer ID,
  // and a supplier ID...
  char product_code[] = "100-440-0.750-3434-A";
  
  // create arrays to store the substrings
  char part_number[4];
  char manu_id[4];
  char supp_id[5];
  
  // use the function to create the substrings
  substring(product_code, part_number, 0, 3);
  substring(product_code, manu_id, 4, 3);
  substring(product_code, supp_id, 14, 4);
  
  // output the substrings to check for correctness
  printf("Part: %s\n", part_number);
  printf("Manu: %s\n", manu_id);
  printf("Supp: %s\n", supp_id);
  
  // for testing error handling cases
  char error1[50];
  char error2[50];
  
  // test that we get an empty string back if the index provided (200) exceeds
  // the length of the original string
  substring(product_code, error1, 200, 5);
  printf("Error 1: %s\n", error1);
  
  // test that we get back the portion of the string from the index to the end 
  // of the string if the index+length exceed the length of the original string
  substring(product_code, error2, 14, 100);
  printf("Error 2: %s\n", error2);
  
  return 0;
}

// stores in substr the substring of the original string (orig) from index for 
// length number of characters
void substring(char *orig, char *substr, int index, int length)
{
  // if the index is past the length of the original string, just return an 
  // empty string in the substring (this is better than the program crashing!)
  if (index >= strlen(orig))
  {
    substr[0] = '\0';
    return ;
  }

  // copy the substring into the substring array, using index as the offset into
  // the original string... also do some error handling and stop copying if we
  // reach the end of the original string (i.e. if the null terminator is 
  // encountered)  
  int i = 0;
  while (i < length && orig[index + i] != '\0')
  {
    substr[i] = orig[index + i];
    i++;
  }

  // put the null terminator onto the end of substr to end the string
  substr[length] = '\0';
}
