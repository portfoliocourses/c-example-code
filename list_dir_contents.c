/*******************************************************************************
*
* Program: List All Files And Directories In A Directory
* 
* Description: Example of how to list all files and directories contained in a 
* directory using the POSIX Library in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0pjtn6HGPVI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// included so we can use the opendir, readdir and closedir functions
#include <dirent.h>

int main(void)
{
  // directory stream variable for accessing the directory
  DIR *directory;

  // will store pointer to each entry in the directory
  struct dirent *entry;
  
  // attempt to open the current working directory, opendir() returns NULL 
  // on failure
  directory = opendir(".");
  
  // if opening the directory fails, exit with an error message and status
  if (directory == NULL)
  {
    printf("Error opening directory.\n");
    return 1;
  }
  
  // Read each entry in the directory with readdir() and store the pointer to 
  // the struct dirent into entry... when there are no more entries in the 
  // directory readdir() will return NULL and terminate the loop at that point.
  while ((entry = readdir(directory)) != NULL)
  {
    // If the entry is a regular file, output the filename prepended with 
    // "File: " so we know it is a file when examining the program output
    if (entry->d_type == DT_REG)
    {
      printf("File: %s\n", entry->d_name);
    }
    // Otherwise if the entry is a directory, output the directory name 
    // prepended with "dir: " again so we know what what it is when looking 
    // at the program output.
    else if (entry->d_type == DT_DIR)
    {
      printf(" dir: %s\n", entry->d_name);
    }
  }
  
  // close the directory... if closedir() fails it will return -1
  if (closedir(directory) == -1)
  {
    // exit with an error message and status if closedir() fails
    printf("Error closing directory.\n");
    return 1;
  }
  
  return 0;
}