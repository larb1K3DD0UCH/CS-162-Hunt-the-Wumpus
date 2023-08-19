/******************************************************
 ** Program:pit.cpp
 ** Author: 
 ** Date: 08/10/2023
 ** Description: Hunt the Wumpus game 
 ** Input: Choose size of cave, select where want to go.
 ** Output: Win or loose game.
 ******************************************************/
#ifndef PIT_H
#define PIT_H

#include "event.h"

// Child class Pit inherits from the Event base class
class Pit : public Event {
protected:
    string message; // Message associated with the Pit event

public:
    // Constructor for the Pit class
    Pit();

    // Function to retrieve the message associated with the Pit event
    string get_message();
};

#endif

