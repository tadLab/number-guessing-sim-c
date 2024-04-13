#include <stdio.h>
#include <stdlib.h>


void guide(){

    printf("              *WELCOME*            \n");
    printf("*THIS IS A GUESSING NUMBER SIMULATOR*\n");
    printf("      *GUESS A NUMBER FROM 1-10*     \n");

}

int main(int argc, char const *argv[])
{
    //VARIABLES
    int usersNumber;
    int randomNumber;

    //START    
    guide();

    randomNumber = arc4random_uniform(10);

    while(randomNumber != usersNumber){    
        printf("TYPE YOUR GUESS: ");
        scanf("%d", &usersNumber);
        if(randomNumber != usersNumber){
            printf("THAT IS NOT THE NUMBER.\n");  
        }
    }

    printf("GOOD JOB, YOU GUESSED %d\n", randomNumber);

    return 0;
}
