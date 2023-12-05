#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game
int game(char you, char computer)
{
    // If both the user and computer
    // have chosen the same thing
    if (you == computer)
        return -1;

    // Fire beats Scissors, Sponge, and Paper
    if ((you == 'f' && (computer == 'z' || computer == 'p' || computer == 's')) ||
        // Rock beats Fire, Scissors, and Sponge
        (you == 'r' && (computer == 'f' || computer == 'z' || computer == 's')) ||
        // Water beats Rock, Fire, and Scissors
        (you == 'w' && (computer == 'r' || computer == 'f' || computer == 'z')) ||
        // Air beats Water, Rock, and Fire
        (you == 'a' && (computer == 'w' || computer == 'r' || computer == 'f')) ||
        // Paper beats Air, Water, and Rock
        (you == 'p' && (computer == 'a' || computer == 'w' || computer == 'r')) ||
        // Sponge beats Paper, Water, and Air
        (you == 's' && (computer == 'p' || computer == 'w' || computer == 'a')) ||
        // Scissors beats Sponge, Paper, and Air
        (you == 'z' && (computer == 's' || computer == 'p' || computer == 'a')))
    {
        return 1; // User wins
    }
    else
    {
        return 0; // User loses
    }
}

void displayOpeningBoard();

int main()
{
    // Stores the random number
    int n;

    char you, computer;
    int result;

    // Display the opening board
    displayOpeningBoard();

    while (1)
    {
        // Chooses the random number every time
        srand(time(NULL));

        // Make the random number less than 100, divided it by 100
        n = rand() % 100;

        // Using simple probability 100 is roughly divided among choices
        if (n < 14)
            computer = 'f'; // Fire
        else if (n < 28)
            computer = 'r'; // Rock
        else if (n < 42)
            computer = 'w'; // Water
        else if (n < 56)
            computer = 'a'; // Air
        else if (n < 70)
            computer = 'p'; // Paper
        else if (n < 84)
            computer = 's'; // Sponge
        else
            computer = 'z'; // Scissors

        printf("\nEnter the corresponding letter for your choice (Press '0' to exit):\n");
        // input from the user
        scanf(" %c", &you); // Note the space before %c to consume the newline character

        // Check if the user wants to exit
        if (you == '0')
        {
            printf("Exiting the game. Thanks for playing!\n");
            break;
        }

        // Function Call to play the game
        result = game(you, computer);

        printf("You choose: %c\n", you);
        printf("Computer chooses: %c\n", computer);

        if (result == -1)
        {
            printf("Game Draw!\n");
        }
        else if (result == 1)
        {
            printf("Wow! You have won the game!\n");
        }
        else
        {
            printf("Oh! You have lost the game!\n");
        }
    }

    return 0;
}

void displayOpeningBoard()
{
    printf("Welcome to Rock, Paper, Scissors, and More!\n");
    printf("Opening Board:\n");
    printf("f - FIRE\n");
    printf("r - ROCK\n");
    printf("w - WATER\n");
    printf("a - AIR\n");
    printf("p - PAPER\n");
    printf("s - SPONGE\n");
    printf("z - SCISSORS\n");
    printf("-----------------------------------\n");
}
