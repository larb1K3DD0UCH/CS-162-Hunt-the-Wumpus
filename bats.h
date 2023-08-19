/******************************************************
** File: bats.cpp
** Author:
** Date: 08/10/2023
** Description: Implementation of the Bats event in the Hunt the Wumpus game
** Input: None
** Output: Message indicating encounter with bats
******************************************************/
#ifndef BATS_H
#define BATS_H

#include "event.h"

// Child class Bats inherits from the Event base class
class Bats : public Event {
protected:
    string message; // Message associated with the Bats event

public:
    // Constructor for the Bats class
    Bats();

    // Function to retrieve the message associated with the Bats event
    string get_message();

    // Function to output the message associated with the Bats event
    void output_message();
};

#endif

