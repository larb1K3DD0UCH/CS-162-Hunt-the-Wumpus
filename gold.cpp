#include "gold.h"

// sets message and event letter
Gold::Gold() {
    message = "You see a glimmer nearby.";
    eventletter = 'G';
}

// gets message
string Gold::get_message() {
    return message;
}
