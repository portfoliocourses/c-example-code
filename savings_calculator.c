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
  // we'll need a balance, rate of return, annual contribution and total years 
  // to grow in order to create the yearly investment returns table
  double balance = 0;
  double rate_of_return = 0;
  double annual_contribution = 0;
  int total_years = 0;
  
  printf("********** Savings Calculator **********\n\n");
  
  // accept initial deposit amount >= 0
  do {
    printf("Initial Deposit: ");
    scanf("%lf", &balance);
    if (balance < 0)
      printf("Initial Deposit Must Be >= 0.00\n");
  } while (balance < 0);
  
  // accept annual contribution >= 0
  do {
    printf("Annual Contribution: ");
    scanf("%lf", &annual_contribution);
    if (annual_contribution < 0)
      printf("Annual Contribution Must Be >= 0.00\n");
  } while (annual_contribution < 0);
 
  // accept rate of return >= 0
  do {
    printf("Rate Of Return: ");
    scanf("%lf", &rate_of_return);
    if (rate_of_return < 0)
      printf("Rate of Return Must Be >= 0.00\n");
  } while (rate_of_return < 0);
 
  // accept years to grow > 0
  do {
    printf("Years To Grow: ");
    scanf("%d", &total_years);
    if (total_years <= 0)
      printf("Years Must Be > 0\n");
  } while (total_years <= 0);
  
  // output table headings
  printf("\n%10s%18s%16s%16s\n",
         "Year", "Start Balance", "Interest", "End Balance");
  for (int i = 0; i < 60; i++) printf("*");
  printf("\n");
  
  // output each year's year #, start balance, interest earned, and end balance
  for (int year = 1; year <= total_years; year++)
  {
    // output the year and starting balalance
    printf("%10d%18.2f", year, balance);

    // calculate the interest earned for the year and end balance
    double interest = balance * (rate_of_return / 100);
    balance += interest + annual_contribution;

    // output the interest earned and end balance
    printf("%16.2f%16.2f\n", interest, balance);
  }
  printf("\n");
  
  return 0;
}

