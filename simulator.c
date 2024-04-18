#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h> 

/**
 * @brief Determines the difficulty level based on user input.
 * 
 * @param level The difficulty level string ("easy", "medium", "hard").
 * @return 0 for easy, 1 for medium, 2 for hard, -1 for invalid level.
 */
int difficulty(char level[7]) {
    // Convert the input level string to lowercase
    for (int position = 0; level[position] != '\0'; position++) {
        level[position] = tolower(level[position]);
    }

    // Compare the lowercase string using strcmp function
    if (strcmp(level, "easy") == 0) {
        return 0; // Return 0 for easy
    } else if (strcmp(level, "medium") == 0) {
        return 1; // Return 1 for medium
    } else if (strcmp(level, "hard") == 0) {
        return 2; // Return 2 for hard
    } else {
        return -1; // Return -1 for invalid level
    }
}

/**
 * @brief Displays the welcome message and instructions for the game.
 */
void guide() {
    printf("              *WELCOME*            \n");
    printf("*THIS IS A GUESSING NUMBER SIMULATOR*\n");
    printf("       *CHOOSE YOUR DIFFICULTY*     \n");
    printf("          *EASY MEDIUM HARD*       \n");
}

/**
 * @brief Main function to run the number guessing game.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int usersNumber;
    int randomNumber;
    char answerContinue;
    int tries; 
    char level[7];
    int range;

    guide(); // Display welcome and instructions

    srand(time(NULL)); // Seed the random number generator

    do {
        // Get user input for difficulty level
        printf("LEVEL: ");
        scanf("%6s", level); 

        // Determine the difficulty level
        int diff = difficulty(level); 

        // Check if the difficulty level is valid
        if (diff == -1) {
            printf("Invalid difficulty level. Exiting the game.\n");
            return 0; // Exit the game
        }

        tries = 5; // Set initial number of tries

        // Set the range based on difficulty level
        if(diff == 0){
            range = 10; // Easy level range
        } else if(diff == 1){
            range = 20; // Medium level range
        } else if(diff == 2){
            range = 30; // Hard level range
        }

        // Game loop
        while (tries > 0) {
            randomNumber = 1 + rand() % range; // Generate random number
            usersNumber = 0; // Reset user's guessed number
            
            // Guessing loop
            while (randomNumber != usersNumber && tries > 0) {
                printf("TYPE YOUR GUESS (1-%d): ", range);

                // Validate user input within the range
                while (scanf("%d", &usersNumber) != 1 || usersNumber < 1 || usersNumber > range) {
                    printf("Invalid input. Please enter a number from 1 to %d: ", range);
                    while (getchar() != '\n'); // Clear input buffer
                }

                // Check if guessed number is correct
                if (randomNumber != usersNumber) {
                    printf("THAT IS NOT THE NUMBER. ");
                    tries--;

                    // Provide hint (higher/lower)
                    if(randomNumber < usersNumber){
                        printf("THE NUMBER IS LOWER.\n");
                    } else if(randomNumber > usersNumber){
                        printf("THE NUMBER IS HIGHER.\n");
                    }

                    printf("You have %d tries left.\n", tries);
                }
            }

            // Display result of the game
            if (randomNumber == usersNumber) {
                printf("GOOD JOB, YOU GUESSED %d\n", randomNumber);
                break; // Break out of the loop if guessed correctly
            } else {
                printf("Out of tries. The correct number was %d\n", randomNumber);
            }
        }

        // Prompt for continuation
        printf("DO YOU WANT TO CONTINUE (Y/N)? ");
        scanf(" %c", &answerContinue);

    } while (answerContinue == 'y' || answerContinue == 'Y');

    printf("Exiting the game. Goodbye!\n");

    return 0; // Exit successfully
}