#include "wumpus.h"
 // sets message and event letter

Wumpus::Wumpus() {
    message = "You smell a terrible stench.";
    alive = true;
    eventletter = 'W';
}

// gets message
string Wumpus::get_message() {
    return message;
}

bool Wumpus::get_alive() {
    return alive;
}
