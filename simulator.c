#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guide() {
    printf("              *WELCOME*            \n");
    printf("*THIS IS A GUESSING NUMBER SIMULATOR*\n");
    printf("      *GUESS A NUMBER FROM 1-10*     \n");
    printf("          *YOU HAVE 5 TRIES*         \n");
}

int main() {
    int usersNumber;
    int randomNumber;
    char answerContinue;
    int tries; 

    srand(time(NULL));

    guide();

    do {
        tries = 5; 
        while (tries > 0) {
            randomNumber = 1 + rand() % 10; 
            usersNumber = 0; 
            
            while (randomNumber != usersNumber && tries > 0) {
                printf("TYPE YOUR GUESS (1-10): ");

                while (scanf("%d", &usersNumber) != 1 || usersNumber < 1 || usersNumber > 10) {
                    printf("Invalid input. Please enter a number from 1 to 10: ");
                    while (getchar() != '\n'); 
                }

                if (randomNumber != usersNumber) {
                    printf("THAT IS NOT THE NUMBER. ");
                    tries--;
                    printf("You have %d tries left.\n", tries);
                }
            }

            if (randomNumber == usersNumber) {
                printf("GOOD JOB, YOU GUESSED %d\n", randomNumber);
                break; 
            } else {
                printf("Out of tries. The correct number was %d\n", randomNumber);
            }
        }

        printf("DO YOU WANT TO CONTINUE (Y/N)? ");
        scanf(" %c", &answerContinue);

    } while (answerContinue == 'y' || answerContinue == 'Y');

    printf("Exiting the game. Goodbye!\n");

    return 0;
}