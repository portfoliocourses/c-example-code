/*******************************************************************************
*
* Program: Magic 8-Ball Game
* 
* Description: A magic 8-ball game implemented in C.  A magic 8-ball is asked a
* yes or no question by the player, and it randomly returns one of 20 results:
*   https://en.wikipedia.org/wiki/Magic_8-Ball
*
* YouTube Lesson: https://www.youtube.com/watch?v=2aJzGL_cKzY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // seed the random number generator
  srand(time(NULL));
  
  // stores the player's question
  char question[1024];

  // array of 20 possible answers
  char *answers[] =
  {
    "It is certain.",
    "It is decidedly so.",
    "Without a doubt.",
    "Yes definitely.",
    "You may rely on it.",
    "As I see it, yes.",
    "Most likely.",
    "Outlook good.",
    "Yes.",
    "Signs point to yes.",
    "Reply hazy, try again.",
    "Ask again later.",
    "Better not tell you now.",
    "Cannot predict now.",
    "Concentrate and ask again.",
    "Don't count on it.",
    "My reply is no.",
    "My sources say no.",
    "Outlook not so good.",
    "Very doubtful."
  };
  
  // makes it so that each time the program is run, the same question could 
  // yield a different result, by adding a random number to the typical 
  // determination that is based on the question characters
  int rotation = rand() % 20;
  
  do
  {
    // ask the user to enter a question (or quit to exit)
    printf("***** Ask Magic 8-Ball *****\n\n");
    printf("[Enter quit to exit.]\n\n");
    printf("Question: ");
    
    // store the question into the question array
    fgets(question, 1024, stdin);
    
    // if the user enters quit, then exit
    if (strcmp(question, "quit\n") == 0)
      break;
    
    // We use the question characters to help determine the answer!  Each 
    // character has some positive integer ascii value (e.g. a - 97, b -98 and 
    // so on), we first add together the total of all the question ascii value.
    int length = strlen(question);
    int total = 0;
    for (int i = 0; i < length; i++)
      total += question[i];
    
    // We then compute the answer by adding the total to the random rotation 
    // value and doing a modulus of 20, which will give a result between 0-19.
    // We present the answer using this value as the index for the answers array
    // above (see below).  The rotation value is randomly calculated *once* 
    // per run of the program... this means if they user asks the exact same 
    // question again during one run of the program, they'll get back the exact 
    // same answer.  If however they run the program again, a new rotation value
    // is calculated, and the answer may be different.  This adds some 
    // randomization to the answers (across different runs of the program), 
    // while still keeping the answer as tied to a particular question.  This is
    // a bit different than how a magic 8-ball typically works where it always 
    // returns a random result... we could move the calculation of rotation 
    // inside the do-while loop to get the same effect.  But I find this to be 
    // more fun that there is "an answer" for each question, and that the same 
    // question will get the same answer for the same execution of the program
    // (even though it is still random across different runs of the program). 
    
    int answer = (total + rotation) % 20;

    // output the answer
    printf("\nMagic 8-Ball Says: %s\n\n\n", answers[answer]);
    
  // keep going until the user enters quit
  } while (true);
  
  return 0;
}