/*
    This is to certify that this project is my own work, based on my personal
    efforts in studying and applying the concepts learned. I have constructed
    the functions and their respective algorithms and corresponding code by
    myself. The program was run, tested, and debugged by my own efforts. I
    further certify that I have not copied in part or whole or otherwise
    plagiarized the work of other students and/or persons.
    Timothy Aaron S. Go
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Description : This function is the pseudo AI that randomizes pegs.
    @param : int range
    @return : char; 1 for R, 2 for P, 3 for G, 4 for Y, 5 for O, 6 for S
              and so on for numbers greater than 6
*/

char random(int range){
    int color = rand() % range + 1;

    if (color <= 6 && color >= 1)
        switch (color){
            case 1:
                return 'R';
            case 2:
                return 'P';
            case 3:
                return 'G';
            case 4:
                return 'Y';
            case 5:
                return 'O';
            case 6:
                return 'S';
        }
    else
        return color + 'A' - 1;
}

/*
    Description : This function checks if the pegs are in the correct
                  positions.
    @param : char c1, char c2, char c3, char c4, char g1, char g2, 
             char g3, char g4
    @return : void function
*/

void check(char c1, char c2, char c3, char c4, 
           char g1, char g2, char g3, char g4){
            if (g1 == c1)
                printf("B ");
            else if (g1 == c2 || g1 == c3 || g1 == c4)
                printf("W ");

            if (g2 == c2)
                printf("B ");
            else if (g2 == c1 || g2 == c3 || g2 == c4)
                printf("W ");

            if (g3 == c3)
                printf("B ");
            else if (g3 == c1 || g3 == c2 || g3 == c4)
                printf("W ");

            if (g4 == c4)
                printf("B ");
            else if (g4 == c1 || g4 == c2 || g4 == c3)
                printf("W ");
            
            printf("\n");
           }

int main(){

    int choice, rounds, role;
    int difficulty = 1;
    int range = 6;
    int attempts = 10;

    char char1, char2, char3, char4; 
    char guess1, guess2, guess3, guess4;

    int points1 = 0;
    int points2 = 0;

    srand(time(NULL));

    do {
        // Display Menu
        printf("\n");
        printf("1. Play\n");
        printf("2. Select Difficulty\n");
        printf("3. Exit\n");
        printf("\n");

        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                do {
                    printf("Enter number of rounds: ");
                    scanf("%d", &rounds);

                    if (rounds % 2 != 0 || rounds <= 0 || rounds > 10)
                        printf("Invalid. Enter an even number between 1 and 10.\n");
                } while (rounds % 2 != 0 || rounds <= 0 || rounds > 10);


                do {
                    printf("\n1. Codebreaker\n");
                    printf("2. Codemaker\n");
                    printf("\nEnter your choice (1-2): ");
                    scanf("%d", &role);
                } while (role < 1 || role > 2);

                for (int round = 1; round <= rounds; ++round) {
                    switch (role) {
                        case 1:
                            //Codebreaker
                                do {
                                    char1 = random(range);  //stores the character
                                    char2 = random(range);
                                    char3 = random(range);
                                    char4 = random(range);

                                } while (char1 == char2 || char1 == char3 || char1 == char4 ||
                                        char2 == char3 || char2 == char4 || char3 == char4);    //ensures that the pegs are not duplicates
                                
                                printf("\nGenerated Code: %c %c %c %c\n", char1, char2, char3, char4);

                                printf("Human Player's Turn\n");

                                if (range == 6)
                                    printf("(Use R, P, G, Y, O, and S for the pegs)\n");
                                else if (range == 8)
                                    printf("(Use R, P, G, Y, O, S, H, and I for the pegs)\n");
                                else if (range == 10)
                                    printf("(Use R, P, G, Y, O, S, H, I, J, and K for the pegs)\n");
                                else 
                                    printf("(Use R, P, G, Y, O, S, H, I, J, K, L, M, N, O, P, and Q)\n");

                                for (int gattempts = 1; gattempts <= attempts; gattempts++){ //gattempts is short for guessed attempts
                                    //Codebreaker's turn
                                    printf("\nAttempt %d: ", gattempts);
                                    scanf(" %c %c %c %c", &guess1, &guess2, &guess3, &guess4);
                                    
                                    // Check pegs
                                    printf("Checking pegs... done!\n");
                                    printf("Here are the results: \n");
                                    check(char1, char2, char3, char4, guess1, guess2, guess3, guess4);

                                    if (guess1 == char1 && guess2 == char2 && guess3 == char3 && guess4 == char4) {
                                        printf("Congratulations! You got the code!\n");
                                        break;
                                    } else if (gattempts >= attempts) {
                                        printf("\nYou lose!\n");
                                        points2++;
                                        break;
                                    } else {
                                        printf("Try again!\n");
                                        points2++;
                                    }
                                }

                        role = 2; //switches roles after turn
                        printf("\nRound %d\n", round); 
                        break;

                        case 2:
                                //Codemaker
                                printf("Human Player's Turn\n");
                                
                                if (range == 6)
                                    printf("(Use R, P, G, Y, O, and S for the pegs)\n");
                                else if (range == 8)
                                    printf("(Use R, P, G, Y, O, S, H, and I for the pegs)\n");
                                else if (range == 10)
                                    printf("(Use R, P, G, Y, O, S, H, I, J, and K for the pegs)\n");
                                else 
                                    printf("(Use R, P, G, Y, O, S, H, I, J, K, L, M, N, O, P, and Q)\n");

                                scanf(" %c %c %c %c", &char1, &char2, &char3, &char4);

                                for (int gattempts = 1; gattempts <= attempts; gattempts++){
                                    
                                    //Codebreaker's turn
                                    do {
                                        if (guess1 != char1)
                                            guess1 = random(range); //pseudo ai guessing
                                        if (guess2 != char2)
                                            guess2 = random(range);
                                        if (guess3 != char3)
                                            guess3 = random(range);
                                        if (guess4 != char4)
                                            guess4 = random(range);

                                    } while (guess1 == guess2 || guess1 == guess3 || guess1 == guess4 || //ensures that the guesses are not duplicates
                                            guess2 == guess3 || guess2 == guess4 || guess3 == guess4);

                                    printf("\nAttempt %d: %c %c %c %c\n", gattempts, guess1, guess2, guess3,
                                                                        guess4);
                                    
                                    // Check pegs
                                    printf("Checking pegs... done!\n");
                                    printf("Here are the results: \n");
                                    check(char1, char2, char3, char4, guess1, guess2, guess3, guess4);


                                    if (guess1 == char1 && guess2 == char2 && guess3 == char3 && guess4 == char4) {
                                        printf("Congratulations! You got the code!\n");
                                        break;
                                    } else if (gattempts >= attempts) {
                                        printf("\nYou lose!\n");
                                        points1++;
                                        break;
                                    } else {
                                        printf("Try again!\n");
                                        points1++;
                                    }
                                }

                        role = 1;
                        printf("\nRound %d\n", round); 
                        break;
                    }
                }
                printf("\nPLAYER1 Points: %d\n", points1);
                printf("BOT Points: %d\n", points2);

                if (points1 > points2)
                    printf("\nPLAYER1 WINS!\n");
                else 
                    printf("\nBOT WINS!\n");

                points1 = 0;
                points2 = 0;

                break;

            case 2: //Difficulty
                printf("1. Easy\n");
                printf("2. Average\n");
                printf("3. Difficult\n");
                printf("4. Extreme\n");
                printf("\n");

                printf("Enter a number (1-4): ");
                scanf("%d", &difficulty);

                switch (difficulty) { //difficulty scaling
                    case 1:
                        range = 6;
                        attempts = 10;
                    break;

                    case 2:
                        range = 8;
                        attempts = 12;
                    break;

                    case 3:
                        range = 10;
                        attempts = 16;
                    break;

                    case 4:
                        range = 16;
                        attempts = 20;
                    break;
                }

            printf("\nRange: %d\n", range);    
            printf("Attempts: %d\n", attempts);
                
            break;

            case 3: //Exit
                printf("Exiting program.");
                printf("\n");
            break;

            default:
                printf("Invalid choice. Please enter a valid option (1-3).\n");
            break;
        }

    } while (choice != 3);

    return 0;
}