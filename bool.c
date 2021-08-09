/*******************************************************************************
*
* Program: Bool values demonstration
* 
* Description: Examples of using boolean values in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=TFWV3Q5W76M
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// stdbool allows us to create variables of type bool and use values 'true' and
// 'false' which are essentially synonyms for 1 and 0 respectively.  
#include <stdbool.h>

// In older C code you may see TRUE and FALSE defined as constants like this, 
// because stdbool was only added in with C99 (a more recent version of C).
// Now you should use stdbool, but you should be aware of this approach too!
#define TRUE 1
#define FALSE 0

int main(void) 
{
  // any non-zero value will evaluate to true
  if (45) printf("true\n");
  else printf("false\n");

  // zero will evaluate to false
  if (0) printf("true\n");
  else printf("false\n");
  
  // we can create bool variables when stdbool is included, and we can use 
  // true and false literal values
  bool x = true; 
  bool y = false;
  
  // we can use true and false values in the expected ways
  if (x) printf("true\n");
  else printf("false\n");
  if (y) printf("true\n");
  else printf("false\n");
  
  // But *really* true and false are just 1 and 0
  printf("x: %d\n", x);
  printf("y: %d\n", y);

  // we can assign 0 to a bool variable and it will be considered false, if 
  // we attempt to assign any other value to the variable it will be set to 
  // 1 instead which is considered true
  bool z = -10;
  printf("z: %d\n", z);

  return 0;
}
