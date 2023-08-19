#include "bats.h"

// sets message and event letter
Bats::Bats() {
    message = "You hear wings flapping.";
    eventletter = 'B';
}
// gets message
string Bats::get_message() {
    return message;
}

void Bats::output_message() {
    cout << message << endl;
}
