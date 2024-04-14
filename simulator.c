#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h> 

int difficulty(char level[7]) {

    for (int position = 0; level[position] != '\0'; position++) {
        level[position] = tolower(level[position]);
    }

    if (strcmp(level, "easy") == 0) {
        return 0; 
    } else if (strcmp(level, "medium") == 0) {
        return 1; 
    } else if (strcmp(level, "hard") == 0) {
        return 2; 
    } else {
        return -1; 
    }
}

void guide() {
    printf("              *WELCOME*            \n");
    printf("*THIS IS A GUESSING NUMBER SIMULATOR*\n");
    printf("       *CHOOSE YOUR DIFFICULTY*     \n");
    printf("          *EASY MEDIUM HARD*       \n");
}

int main() {
    int usersNumber;
    int randomNumber;
    char answerContinue;
    int tries; 
    char level[7];
    int range;

    guide();

    srand(time(NULL));

    do {

        printf("LEVEL: ");
        scanf("%6s", level); 

        int diff = difficulty(level); 

        if (diff == -1) {
            printf("Invalid difficulty level. Exiting the game.\n");
            return 0; 
        }

        tries = 5;

        if(diff == 0){
            range = 10;
        } else if(diff == 1){
            range = 20;
        } else if(diff == 2){
            range = 30;
        }

        while (tries > 0) {
            randomNumber = 1 + rand() % range; 
            usersNumber = 0; 
            
            while (randomNumber != usersNumber && tries > 0) {
                printf("TYPE YOUR GUESS (1-%d): ", range);

                while (scanf("%d", &usersNumber) != 1 || usersNumber < 1 || usersNumber > range) {
                    printf("Invalid input. Please enter a number from 1 to %d: ", range);
                    while (getchar() != '\n'); 
                }

                if (randomNumber != usersNumber) {
                    printf("THAT IS NOT THE NUMBER. ");
                    tries--;
                    
                    if(randomNumber < usersNumber){
                        printf("THE NUMBER IS LOWER.\n");
                    } else if(randomNumber > usersNumber){
                        printf("THE NUMBER IS HIGHER.\n");
                    }

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