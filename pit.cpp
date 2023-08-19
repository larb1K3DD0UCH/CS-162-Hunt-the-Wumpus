#include "pit.h"

// sets message and event letter
Pit::Pit() {
    message = "You feel a breeze.";
    eventletter = 'P';
}

// gets message
string Pit::get_message() {
    return message;
}
