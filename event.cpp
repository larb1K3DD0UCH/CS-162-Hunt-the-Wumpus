#include "event.h"

// sets message and event letter
Event::Event() {
    message = " ";
    eventletter = ' ';
}
// gets message
string Event::get_message() {
    return message;
}
// outputs the events message
void Event::output_message() {
    cout << message << endl;
}
