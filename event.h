/******************************************************
** File: event.cpp
** Author:
** Date: 08/10/2023
** Description: Implementation of the Event base class in the Hunt the Wumpus game
** Input: None
** Output: None
******************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

using namespace std;

// Abstract base class Event with pure virtual functions
class Event {
protected:
    int locationx,   // X-coordinate of the event's location
        locationy;   // Y-coordinate of the event's location
    string message;  // Message associated with the event
    char eventletter; // Letter representing the event type

public:
    // Constructor for the Event class
    Event();

    // Pure virtual function to retrieve the message associated with the event
    virtual string get_message();

    // Pure virtual function to output the message associated with the event
    virtual void output_message();
};

#endif

