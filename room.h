/******************************************************
 ** Program:room.cpp
 ** Author: 
 ** Date: 08/10/2023
 ** Description: Hunt the Wumpus game 
 ** Input: Choose size of cave, select where want to go.
 ** Output: Win or loose game.
 ******************************************************/
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std;

class Room {
protected:
    Event* inRoom;  // Pointer to an Event object representing what's in the room
    char event;     // Character representing the event type in the room
    char player;    // Character representing the player's position in the room

public:
    // Constructor for the Room class
    Room();

    // Accessors
    char get_event();       // Get the event type in the room
    char get_player();      // Get the player's position in the room
    string get_messages();  // Get messages associated with the event

    // Mutators
    void set_player(char);  // Set the player's position in the room
    void set_event(char);   // Set the event type in the room
    void set_Wumpus();      // Set the room as having a Wumpus event

    // Destructor for the Room class
    ~Room();
};

#endif

