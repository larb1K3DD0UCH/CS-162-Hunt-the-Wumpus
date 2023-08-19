/******************************************************
 ** File: main.cpp
 ** Author:
 ** Date: 08/10/2023
 ** Description: Implementation of the Hunt the Wumpus game
 ** Input: User specifies the size of the cave and their chosen moves.
 ** Output: Displays whether the player wins or loses the game.
 ******************************************************/
#include <iostream>

#include <cstdlib> // Required for atoi

#include <limits> // Required for numeric_limits

#include <stdlib.h> // Required for atoi

#include "game.h" // Include the game header file

using namespace std;

int main(int argc, char * argv[]) { // Check if command line arguments are provided
    if (argc <= 1) {
        cout << "ERROR: Insufficient command line arguments.\n";
        cout << "Please enter the size of your game board:\n";
        return 1; // Exit the program with an error code
    }

    Game test; // Create a Game object
    int size = atoi(argv[1]); // Convert command line argument to integer

    // Validate the size of the game board
    while (size <= 4) {
        cout << "Error: You must enter a size greater than 4. \nTry again: ";
        cin >> size;

        // Clear the input buffer in case of invalid input
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }

    system("clear"); // Clear the console screen
    cout << "Welcome to the Hunt the Wumpus game!" << endl;
    test.run_game(size); // Run the game with the specified size
    return 0;
}
