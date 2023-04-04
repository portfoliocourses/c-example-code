/*******************************************************************************
*
* Program: Quiz Game
* 
* Description: A simple multiple-choice quiz game in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=tG--A0ZMLnA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Maximum string lengths (including null terminator) for the quiz questions 
// and answers.
#define MAX_QUESTION 256
#define MAX_ANSWER 128

// Total number of questions in the quiz.
#define TOTAL_QUESTIONS 5

// Define a struct for representing quiz questions.  Each struct will store the 
// question and 4 possible answers A-D as strings in char arrays, as well as the
// correct answer as a char member.
typedef struct
{
  char question[MAX_QUESTION];
  char answerA[MAX_ANSWER];
  char answerB[MAX_ANSWER];
  char answerC[MAX_ANSWER];
  char answerD[MAX_ANSWER];
  char correct_answer;
} quiz_question;

int main(void)
{
  // Declare an array of quiz_question structs that is TOTAL_QUESTIONS in length
  // to store all the data to represent our quiz.
  quiz_question quiz[TOTAL_QUESTIONS];
  
  // Create the first quiz question by storing strings for the quiz question 
  // text and possible answers into the associated struct members, as well as 
  // the correct answer (in this case, B).
  strcpy(quiz[0].question, "What does the ++ operator do?");
  strcpy(quiz[0].answerA, "Add two to a number");
  strcpy(quiz[0].answerB, "Add one to a number");
  strcpy(quiz[0].answerC, "Subtract one from a number");
  strcpy(quiz[0].answerD, "Subtract two from a number");
  quiz[0].correct_answer = 'B';
  
  // Create the second quiz question
  strcpy(quiz[1].question, "C is a successor of which language?");
  strcpy(quiz[1].answerA, "B");
  strcpy(quiz[1].answerB, "C++");
  strcpy(quiz[1].answerC, "Python");
  strcpy(quiz[1].answerD, "Java");
  quiz[1].correct_answer = 'A';
  
  // Create the third quiz question
  strcpy(quiz[2].question, "When is a do-while loop condition checked?");
  strcpy(quiz[2].answerA, "Before the loop body executes");
  strcpy(quiz[2].answerB, "Never");
  strcpy(quiz[2].answerC, "While the loop body executes");
  strcpy(quiz[2].answerD, "After the loop body executes");
  quiz[2].correct_answer = 'D';
  
  // Create the fourth quiz question
  strcpy(quiz[3].question, "What does a pointer variable store?");
  strcpy(quiz[3].answerA, "A floating-point number");
  strcpy(quiz[3].answerB, "A string");
  strcpy(quiz[3].answerC, "A memory address");
  strcpy(quiz[3].answerD, "An array");
  quiz[3].correct_answer = 'C';
  
  // Create the fifth quiz question
  strcpy(quiz[4].question, "How can we check if x does not equal y in C?");
  strcpy(quiz[4].answerA, "x <> y");
  strcpy(quiz[4].answerB, "x != y");
  strcpy(quiz[4].answerC, "x === y");
  strcpy(quiz[4].answerD, "x DNE y");
  quiz[4].correct_answer = 'B';

  // Declare variable to store the total number of questions answered correctly
  double total_correct = 0;
  
  // Declare variable to store the answers entered by the user
  char answer;
  
  // Loop with counter variable i going from 0 to TOTAL_QUESTIONS by 1 will have
  // i go through each index of our quiz array, we'll use i to present each quiz
  // question to the user.
  for (int i = 0; i < TOTAL_QUESTIONS; i++)
  {
    // Output the question, including a 'question number' as given by i+1 for 
    // Question 1, Question 2, and so on.
    printf("Question %d: %s\n\n", (i+1), quiz[i].question);
    
    // Output the possible answers as a menu of options A,B,C, or D
    printf("A) %s\n", quiz[i].answerA);
    printf("B) %s\n", quiz[i].answerB);
    printf("C) %s\n", quiz[i].answerC);
    printf("D) %s\n", quiz[i].answerD);

    // Prompt the user to enter either A,B,C, or D
    printf("\nEnter Answer (A,B,C or D): ");
    
    // Store the character entered by the user into answer.  We put a ' ' char
    // in front of %c so that scanf will "skip over" any whitespace characters
    // such as newline \n before reading in the next character.  Otherwise if 
    // for example the user enters in 'B' for the first question, we'll have
    // on the standard input buffer:
    //
    // B\n
    //
    // and scanf() will 'pull off' the character 'B' and store it into answer,
    // but there will be a newline \n character left on the input buffer:
    //
    // \n
    //
    // So then on the next loop iteration, scanf() won't stop for a character 
    // of input and it will seem as if the call to scanf() was "skipped over".
    // By using ' ' to skip over whitespace, the newline \n will be skipped over
    // and scanf() will 'pause' and allow the user to enter in another char.
    //
    scanf(" %c", &answer);
    
    // Check to see if the user got the correct answer.  Just in case the user 
    // enters in a lowercase 'a', 'b', 'c' or 'd' we use toupper() to convert 
    // the answer char to an uppercase letter.  If answer is set to a lowercase
    // letter toupper() will return the uppercase version of that letter, 
    // otherwise it will return the same character it was passed as an argument.
    if (toupper(answer) == quiz[i].correct_answer)
    {
      // Increment total_correct to reflect the user has answered another 
      // question correctly, and output a correct answer message to the user.
      total_correct++;
      printf("\n\nCorrect Answer!");
    }
    else
    {
      // Otherwise if the user did not get the correct answer, output an
      // incorrect answer message as well as the correct answer.
      printf("\n\nIncorrect Answer!");
      printf("\n\nThe correct answer was %c.", quiz[i].correct_answer);
    }
    
    // Output newlines to separate the questions
    printf("\n\n\n");
  }

  // Output the total number of questions correct out of the total number of
  // questions.  We use (int) to type cast total_correct to an int so we can
  // output it as an int with %d, we declared total_correct as a double so 
  // we could use it to calculate the total percentage of questions answered
  // correctly (see below). 
  printf("%d/%d questions answered correctly",
         (int) total_correct, 
         TOTAL_QUESTIONS);

  // Output the total percentage of questions answered correctly. We use %f 
  // to output a floating point number with %.2f to restrict the output to 
  // two decimal places of accuracy.  We use %% after this to output a single
  // % character for 'perecent' (note that % is a special char for printf, 
  // normally used for placeholders).  We use total_correct and TOTAL_QUESTIONS
  // to calculate the percentage of questions answered correctly. 
  printf(" (%.2f%%)\n\n", (total_correct / TOTAL_QUESTIONS) * 100);

  return 0;
}