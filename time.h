/*******************************************************************************
*
* Program: Time library demo
* 
* Description: Examples of using the time library in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Qoed2uBwF_o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void) 
{
  // gets the current time as the number of seconds since Jan. 1, 1970 midnight
  time_t now = time(NULL);
  
  // time_t is really a long value, so we can print it out with %ld
  printf("%ld\n", now);

  // we can use difftime to get the difference between two times, here we sleep
  // for 2 seconds so that there will be a difference in time
  //
  // sleep(2);
  // time_t two_secs = time(NULL);
  // printf("%ld\n", two_secs);
  // double diff = difftime(two_secs, now);
  // printf("diff: %f\n", diff);

  // ctime will return a nicely formatted string representation of the time
  char *string_now = ctime(&now);
  printf("%s\n", string_now);
 

  // gmtime returns a pointer to a struct tm which has members for each 
  // individual piece of time data that we might want to work with.  Returns 
  // it in Greenwich Mean Time.
  struct tm *gm_time = gmtime(&now);
  
  // See the definition of the struct members here:
  //   https://www.tutorialspoint.com/c_standard_library/time_h.htm
  printf("tm_sec: %d\n", gm_time->tm_sec);
  printf("tm_min: %d\n", gm_time->tm_min);
  printf("tm_hour: %d\n", gm_time->tm_hour);
  printf("tm_mday: %d\n", gm_time->tm_mday);
  printf("tm_mon: %d\n", gm_time->tm_mon);
  printf("tm_year: %d\n", gm_time->tm_year);
  printf("tm_wday: %d\n", gm_time->tm_wday);
  printf("tm_yday: %d\n", gm_time->tm_yday);
  printf("tm_isdst: %d\n", gm_time->tm_isdst);
  printf("\n");
  

  // local time also returns a struct tm, but for our own local time zone
  struct tm *cur_time = localtime(&now);
  printf("tm_sec: %d\n", cur_time->tm_sec);
  printf("tm_min: %d\n", cur_time->tm_min);
  printf("tm_hour: %d\n", cur_time->tm_hour);
  printf("tm_mday: %d\n", cur_time->tm_mday);
  printf("tm_mon: %d\n", cur_time->tm_mon);
  printf("tm_year: %d\n", cur_time->tm_year);
  printf("tm_wday: %d\n", cur_time->tm_wday);
  printf("tm_yday: %d\n", cur_time->tm_yday);
  printf("tm_isdst: %d\n", cur_time->tm_isdst);

  // asctime uses a struct tm to created a nicely formatted string 
  // representation of the time
  char *other_string = asctime(cur_time);
  printf("%s\n", other_string);
  
  // mktime will convert from a struct tm time to a time_t representation
  // here we increment the # of minutes of cur_time by 1 and then convert 
  // it, and so when we compare it to now it should be 60 seconds larger!
  cur_time->tm_min = cur_time->tm_min + 1;
  time_t new_time = mktime(cur_time);
  printf("now: %ld\n", now);
  printf("new_time: %ld\n", new_time);

  // strftime will format a string representation of a given time 
  // according to specifiers, see a full list of them here:
  // https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm
  //
  // The function accepts a buffer to store the string, a max number of chars, 
  // a string with specifiers specifying the format to create, and the time 
  // in the form a struct tm.  It returns the length of the created string (or
  // 0 if the string is over the max length specified).
  char s[100];
  int strlen = strftime(s,100,"%l %p", cur_time);
  printf("%s\n", s);
  printf("%d\n", strlen);
  
  // clock() returns the number of CPU clock ticks since the program began, so 
  // we can get the clock tics before and after some process (stored as clock_t
  // type data), and divide by the constant value CLOCKS_PER_SEC to get the 
  // number of seconds (perhaps a fraction of seconds) for some process to 
  // occur!
  clock_t start, end;
  start = clock();
  for (int i = 0; i < 100000000; i++) { }
  end = clock();
  
  double total = (double) (end - start) / 
                 CLOCKS_PER_SEC;
  printf("Time: %fs\n", total);

  return 0;
}
