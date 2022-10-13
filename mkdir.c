/*******************************************************************************
*
* Program: mkdir() Demonstration
* 
* Description: Example of using the mkdir() in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=teu0_tEKJLw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

// use the global variable errno that will be set with an error code by mkdir()
// if an error occurs
extern int errno;

int main(void)
{
  // Creates a directory test1 with permissions assigned by combining these 
  // constants using the bitwise or operator:
  //   https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html
  //
  // We could also use 0777 for the 2nd argument, in a very similar style to the 
  // chmod terminal command: https://linuxcommand.org/lc3_man_pages/chmod1.html
  if (mkdir("test1", S_IRWXU | S_IRWXG | S_IRWXO ) == -1)
  {
    // we could use perror() to output the error if it occurs, the error 
    // message will be preprended with "Error" because we have supplied this 
    // as an argument
    perror("Error");
    
    // We could also look at the error code assigned to errno, and then handle
    // the error programmatically (perhaps depending on what the error is, using
    // a control structure like an if-else if-else or switch).  In this case we 
    // detect when the file directory already exists.
    //
    // See error codes: 
    // https://www.gnu.org/software/libc/manual/html_node/Creating-Directories.html
    //
    if (errno == EEXIST)
    {
      // We could make a *different* directory if the directory we tried to 
      // create already exists.
      //

      // mkdir("test2", 0777);
    }
   
    // returning 1 is a signal to the shell/terminal that something has gone 
    // wrong in the execution of our program, in contrast to returning 0 
    // as below...
    return 1;
  }

  return 0;
}
