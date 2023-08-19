#include "room.h"

// sets variables to NULL states
Room::Room() {
    event = ' ';
    inRoom = NULL;
    player = 'X';
    srand(time(NULL));
}

// returns event
char Room::get_event() {
    return event;
}

// returns player
char Room::get_player() {
    return player;
}

// depending on which event wanted, will set that event
void Room::set_event(char event) {
    this -> event = event;
    if (event == 'W') {
        inRoom = new Wumpus;
    } else if (event == 'B') {
        inRoom = new Bats;
    } else if (event == 'P') {
        inRoom = new Pit;
    } else if (event == 'G') {
        inRoom = new Gold;
    } else if (event == ' ') {
        inRoom = NULL;
    }
}

// outputs the message
string Room::get_messages() {
    return inRoom -> get_message();
}

// deconstructor
Room::~Room() {
    delete[] inRoom;
}
