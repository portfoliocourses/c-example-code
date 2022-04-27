/*******************************************************************************
*
* Program: Read CSV File Data To An Array Of Structs
* 
* Description: Example of reading CSV file data into an array of structs in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rbVt5v8NNe8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// A struct for representing student data in a file formatted like this:
//
// U,Virat Kohli,23,95.6
// U,Serena Williams,22,83.2
// G,Wayne Gretzky,19,84.2
//
// with a "student type" (e.g. undergraduate, graduate) single character, 
// followed by the student's name, age and then average.
//
typedef struct 
{
  // members for the student's type, name, age and average
  char type;
  char name[50];
  int age;
  double average;
} Student;

int main(void)
{
  // file pointer variable for accessing the file
  FILE *file;
  
  // attempt to open file.txt in read mode to read the file contents
  file = fopen("file.txt", "r"); 
  
  // if the file failed to open, exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // array of structs for storing the Student data from the file
  Student students[100];
  
  // read will be used to ensure each line/record is read correctly
  int read = 0;
  
  // records will keep track of the number of Student records read from the file
  int records = 0;

  // read all records from the file and store them into the students array
  do 
  {
    // Read a line/record from the file with the above format, notice in 
    // particular how we read in the student's name with %49[^,] which matches
    // up to 49 characters NOT including the comma (so it will stop matching 
    // at the next comma).  The name member can store 50 characters, so 
    // factoring in the NULL terminator this is the maximum amount of characters
    // we can read in for a number.  fscanf() will return the number of values 
    // it was able to read successfully which we expect to be 4, and we store 
    // that into read.
    //
    read = fscanf(file,
                  "%c,%49[^,],%d,%lf\n",
                  &students[records].type, 
                  students[records].name, 
                  &students[records].age, 
                  &students[records].average); 
    
    // if fscanf read 4 values from the file then we've successfully read 
    // in another record
    if (read == 4) records++;
    
    // The only time that fscanf should NOT read 4 values from the file is 
    // when we've reached the end of the file, so if fscanf did not read in 
    // exactly 4 values and we're not at the end of the file, there has been
    // an error (likely due to an incorrect file format) and so we exit with 
    // an error message and status.
    if (read != 4 && !feof(file))
    {
      printf("File format incorrect.\n");
      return 1;
    }
    
    // if there was an error reading from the file exit with an error message 
    // and status
    if (ferror(file))
    {
      printf("Error reading file.\n");
      return 1;
    }

  } while (!feof(file));

  // close the file as we are done working with it
  fclose(file);
  
  // print out the number of records read
  printf("\n%d records read.\n\n", records);
  
  // print out each of the records that was read 
  for (int i = 0; i < records; i++)
    printf("%c %s %d %.2f\n", 
           students[i].type, 
           students[i].name,
           students[i].age,
           students[i].average);
  printf("\n");

  return 0;
}