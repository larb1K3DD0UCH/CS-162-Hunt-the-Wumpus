/******************************************************
 ** Program: Wumpus.cpp
 ** Author: 
 ** Date: 08/10/2023
 ** Description: Hunt the Wumpus game 
 ** Input: Choose size of cave, select where want to go.
 ** Output: Win or loose game.
 ******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

// Child class Wumpus inherits from the Event base class
class Wumpus : public Event {
protected:
    string message; // Message associated with the Wumpus event
    bool alive;     // Indicates if the Wumpus is alive or not

public:
    // Constructor for the Wumpus class
    Wumpus();

    // Function to retrieve the message associated with the Wumpus event
    string get_message();

    // Function to check if the Wumpus is alive
    bool get_alive();
};

#endif

