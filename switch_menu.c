/*******************************************************************************
*
* Program: Switch Menu 
* 
* Description: Example of creating a menu using a switch statement in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=eStBZCSL-gQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
  double balance = 0, amount = 0;
  int choice = 0;
  
  // repeatedly present an "ATM Machine" menu to the user
  while (true)
  {
    // present the menu, accept the user's choice
    printf("1) Deposit\n");
    printf("2) Withdraw\n");
    printf("3) Print Balance\n");
    printf("4) Print Balance And Quit\n");
    printf("5) Quit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    
    // decide what action to carry out based on the user's choice
    switch (choice)
    {
      // deposit money
      case 1:
        printf("Enter Amount: ");
        scanf("%lf", &amount);
        balance += amount;
        break;

      // withdraw money
      case 2:
        printf("Enter Amount: ");
        scanf("%lf", &amount);
        balance -= amount;
        break;
      
      // print balance
      case 3:
        printf("%.2f\n", balance);
        break;
      
      // print balance AND quit by using fall-through logic... the lack of a 
      // break at the end of this case means that execution will "fall through"
      // to the statements of the next case... where we're going to quit anyways
      case 4:
        printf("%.2f\n", balance);
      
      // quit 
      case 5:
        exit(0);
    }
    
  }
  
  return 0;
}
