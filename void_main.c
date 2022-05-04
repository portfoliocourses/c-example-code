/*******************************************************************************
*
* Program: Why Not To Use void main()
* 
* Description: Examples relevant to why we should NOT use the void main()
* function prototype in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Hr1pznlCd44  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// When our program returns an int value in our main function, that int value 
// becomes the 'exit status' for our program.  That exit status can be used 
// by shell scripts.  For example, the diff program used to examine the 
// differences between text files will have an exit status of 0 if NO
// differences were found between files and and exit status of 1 if ANY 
// differences were found between files.  In the below shell script, we examine
// the exit status of two diff commands and output results.  This sort of 
// script might be used to help automate tests... for example we could run our 
// program with sample input, and examine whether the ouput matches what is 
// expected or not using diff.
//
/*
#!/bin/bash

result1=$(diff f1.txt f2.txt)
if [ $? -eq 0 ]
then echo f1 f2 match success
else echo f1 f2 match fail
fi

result2=$(diff f1.txt f3.txt)
if [ $? -eq 0 ]
then echo f1 f3 match success
else echo f1 f3 match fail
fi
*/

#include <stdio.h>
#include <stdlib.h>

// A basic program to check whether or not the first command-line argument 
// provided, which is assumed to be an int, is an even number or not.  The 
// program has an exit status of 0 if it is an even number, 1 if it is not, 
// and 2 if the wrong number of command-line arguments is provided.  The 
// intention is to run the program like this on the command-line:
//
// ./void_main 8
//
int main(int argc, char *argv[])
{
  // if the wrong number of command line arguments are provided, terminate 
  // the program with an exit status of 2
  if (argc != 2) return 2;
  else 
  {
    // convert the command-line argument provided to an int using atoi()
    int num = atoi(argv[1]);
   
    // if dividing the number by 2 results in 0 remainder than the number is 
    // even and the exit status is set to 0, otherwise it is odd and we set 
    // the exit status to 1
    if (num % 2 == 0) return 0;
    else return 1;
  }
}

// We can use the above program this this script below, which uses the exit 
// status of the program to automate the inspection of whether ints are even 
// or odd.  This is a simple example but it again demonstrates how shell 
// scripting can utilize a program's exit status to help automate tasks.
// 
/*
#!/bin/sh
for i in 1 2 3 4 5 6 7 8 9 10
do
  result=$(./void_main $i)
  if [ $? -eq 0 ] 
  then echo $i is even
  else echo $i is odd 
  fi
done

result=$(./void_main 4 abc)
if [ $? -eq 2 ] 
then echo "invalid arguments"
fi
*/

// A big problem with using void as the main function return type is that we 
// lose the ability to set the exit status of the program using the return 
// statement.  Though it is still possible to use the exit() function to do so.
//
// The other problem is that not ALL compilers support using void as a main 
// function return type.  The C standard does not require that compilers support
// using void as a main function return type.  The C standard does allow for 
// compilers to do so though, so strictly speaking it is not illegal.  However 
// writing a program that uses void as the return type of our main function 
// can make the program less portable as it is not guaranteed to compile with 
// all C compilers.
//
// Some textbooks and online examples will use the void main() function 
// prototype, but as a best practice we should not, we should use int instead.
// 
// Uncomment the below code (and comment the above main function) to check out 
// the exit status of the program.  On a Unix-like system's shell (Linux, Mac) 
// you can type 'echo $?' after running the program to examine the exit status 
// of the program.
//
/*
void main(int argc, char *argv[])
{
  
  // We could still provide an exit status by using the exit function
  //
  // exit(5); 
}
*/