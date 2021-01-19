#include<stdio.h>
#include<stdlib.h>
#include<time.h>       //for random generator seed

int main()
{
    int randomNumber,guess,tries;
    time_t t;
    
    //initialization of random number generator
    srand((unsigned) time(&t));

    //get the random number between 0-20
    randomNumber = rand() % 21;

    printf("This is a guess game.\nI've chosen a number between 1-20 which you have to guess within 5 tries.\n");

    for(tries=5; tries>0; --tries)
    {
      printf("You have %d number of tr%s left.\n", tries,tries==1?"y":"ies");   //ternary operator used
      printf("Enter your guess :");
      scanf("%d", &guess);

      if(randomNumber==guess)
      {
        printf("Congratulations. You've guessed it!\n");
        break;        //return or return 1 can also be used
      }
      else if(guess<0 || guess>20)         //validating entry
        printf("I said enter number between 1 to 20.\n");
      else if (randomNumber>guess)                                              //1
        printf("Sorry, %d is wrong. My number is greater than that.\n",guess);
      else if(randomNumber<guess)                                               //2
        printf("Sorry, %d is wrong. My number is smaller than that.\n",guess);  //ternary could've been used for 1 and 2
                                                                                //1 & 2
    }
    return 0;
    


}
