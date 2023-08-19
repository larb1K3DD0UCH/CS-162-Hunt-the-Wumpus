/******************************************************
 ** Program: gold.cpp
 ** Author: 
 ** Date: 08/10/2023
 ** Description: Hunt the Wumpus game 
 ** Input: Choose size of cave, select where want to go.
 ** Output: Win or loose game.
 ******************************************************/

#ifndef GOLD_H
#define GOLD_H

#include "event.h"

// Child class Gold inherits from the Event base class
class Gold : public Event {
protected:
    string message; // Message associated with the Gold event

public:
    // Constructor for the Gold class
    Gold();

    // Function to retrieve the message associated with the Gold event
    string get_message();
};

#endif

