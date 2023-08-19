#include "game.h"

// Constructor initializes member variables and sets the random number generator seed
Game::Game() {
    Size = 0;
    arrows = 3;
    action = 0;
    numGold = 0;
    start_x = start_y = position_x = position_y = 0;
    player_mvnt = 'o';
    gameover = false;
    won = false;
    startingOver = false;
    wumpusdead = false;
    srand(time(NULL)); // Seed random number generator
}

// Set the grid size by taking input from the user
void Game::set_Size() {
    std::cout << "Enter grid size: ";
    cin >> Size;
}

// Allocate memory for the 2D array of Room objects representing the game grid
void Game::set_rooms() {
    rooms = new Room * [Size];
    for (int i = 0; i < Size; ++i)
        rooms[i] = new Room[Size];
}

// Set the movement direction based on user input
void Game::set_movement() {
    std::cout << "\nWhich way to go?: " << endl;
    std::cout << "W - up" << endl;
    std::cout << "S - down" << endl;
    std::cout << "A - left" << endl;
    std::cout << "D - right \n\n--> ";
    cin >> player_mvnt;
}

// Display the game grid, showing events in each room
void Game::output_grid() {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; j++) {
            std::cout << "+---";
        }
        std::cout << "+" << endl;
        for (int j = 0; j < Size; ++j) {
            std::cout << "| " << rooms[i][j].get_event(); // Display room event
            std::cout << " ";
        }
        std::cout << "|" << endl;
    }

    for (int j = 0; j < Size; j++) {
        std::cout << "+---";
    }
    std::cout << "+" << endl;
}

// Retrieve the player's selected action (move or shoot)
void Game::get_action() {
    std::cout << "Kindly indicate your preferred action:\n";
    std::cout << " 1. Proceed through a tunnel\n";
    std::cout << " 2. Launch an arrow through an adjacent room\n\nChoice: ";
    cin >> action;
    while (action != 1 && action != 2) {
        std::cout << "Invalid input, please make a valid selection: ";
        cin >> action;
    }
}

// Move the player based on user input and update room events
void Game::mv_player() {
    if ((player_mvnt == 'S') && (inbounds(position_x + 1, position_y) == true)) {
        rooms[position_x][position_y].set_event(' ');
        position_x++;
        check_event();
        rooms[position_x][position_y].set_event('X');
    } else if ((player_mvnt == 'D') && (inbounds(position_x, position_y + 1) == true)) {
        rooms[position_x][position_y].set_event(' ');
        position_y++;
        check_event();
        rooms[position_x][position_y].set_event('X');
    } else if ((player_mvnt == 'A') && (inbounds(position_x, position_y - 1) == true)) {
        rooms[position_x][position_y].set_event(' ');
        position_y--;
        check_event();
        rooms[position_x][position_y].set_event('X');
    } else if ((player_mvnt == 'W') && (inbounds(position_x - 1, position_y) == true)) {
        rooms[position_x][position_y].set_event(' ');
        position_x--;
        check_event();
        rooms[position_x][position_y].set_event('X');
    } else {
        std::cout << "**** out of bounds! ****" << endl;
    }
}

void Game::check_event() {
    // Check the event in the current room and perform corresponding actions
    if (rooms[position_x][position_y].get_event() == 'P') {
        std::cout << "You have fallen into a pit and perished. You lose:(" << endl;
        gameover = true;
    } else if (rooms[position_x][position_y].get_event() == 'G') {
        std::cout << "Congratulations, you have discovered gold!" << endl;
        numGold++;
    } else if (rooms[position_x][position_y].get_event() == 'B') {
        std::cout << "Watch out! Super bats have spirited you away to a new location." << endl;
        // Move the player to a random new location due to bat encounter
        rooms[position_x][position_y].set_event(' ');
        position_x = set_RandPos();
        position_y = set_RandPos();
        rooms[position_x][position_y].set_event('X');
    } else if (rooms[position_x][position_y].get_event() == 'W') {
        std::cout << "You've entered the Wumpus lair, awakening the Wumpus! It devours you." << endl;
        gameover = true;
    }
}

int Game::set_RandPos() {
    // Generate a random position within the grid size
    int num = rand() % Size;
    return num;
}

void Game::set_events() {
    // Set events in various rooms within the cave
    rooms[start_x][start_y].set_event('X');
    rooms[set_RandPos()][set_RandPos()].set_event('G'); // Gold
    rooms[set_RandPos()][set_RandPos()].set_event('W'); // Wumpus
    rooms[set_RandPos()][set_RandPos()].set_event('B'); // Super Bats
    rooms[set_RandPos()][set_RandPos()].set_event('B'); // Super Bats
    rooms[set_RandPos()][set_RandPos()].set_event('P'); // Pit
    rooms[set_RandPos()][set_RandPos()].set_event('P'); // Pit
}

void Game::set_StartingPos() {
    // Set player's initial position
    position_x = start_x = set_RandPos();
    position_y = start_y = set_RandPos();
    std::cout << "Player start: " << start_x << " " << start_y << endl;
}

void Game::adjust_arrows() {
    // Adjust the number of arrows and check if the player has any remaining
    if (arrows > 0) {
        arrows--;
    } else {
        std::cout << "You have exhausted all your arrows!" << endl;
        gameover = true;
    }
}

char Game::get_movement() {
    // Return the current movement direction
    return player_mvnt;
}

bool Game::get_won() {
    // Return the game's winning status
    return won;
}

void Game::menu() {
    // Handle the player's menu choice
    get_action();

    switch (action) {
    case 1:
        set_movement();
        mv_player();
        check_event();
        break;

    case 2:
        adjust_arrows();
        shoot_arrow();
        break;

    default:
        // Handle other cases here if needed
        break;
    }
}

Game::~Game() {
    // Destructor to release memory occupied by the room objects
    for (int i = 0; i < Size; ++i) {
        delete[] rooms[i];
    }
    delete[] rooms;
}

void Game::endgame() {
    // Display game over message based on winning status
    if (won == true) {
        std::cout << "Congratulations, you won!" << endl;
    } else {
        std::cout << "You have lost the game!" << endl;
    }
}

void Game::check_if_won() {
    // Check if the player has won based on conditions
    if (wumpusdead == true && numGold == 1 && position_y == start_y && position_x == start_x) {
        won = true;
        gameover = true;
    }
}

bool Game::inbounds(int x, int y) {
    // Check if the given coordinates are within the bounds of the grid
    return !(x > Size - 1 || x < 0 || y > Size - 1 || y < 0);
}

// Display messages for adjacent rooms containing events
void Game::out_messages() {
    std::cout << "************ Messages for Indications !***********************" << endl;
    if ((inbounds(position_x + 1, position_y) == true) && (rooms[position_x + 1][position_y].get_event() != ' ')) {
        std::cout << rooms[position_x + 1][position_y].get_messages() << endl;
    }

    if ((inbounds(position_x, position_y + 1) == true) && (rooms[position_x][position_y + 1].get_event() != ' ')) {
        std::cout << rooms[position_x][position_y + 1].get_messages() << endl;
    }

    if ((inbounds(position_x, position_y - 1) == true) && (rooms[position_x][position_y - 1].get_event() != ' ')) {
        std::cout << rooms[position_x][position_y - 1].get_messages() << endl;
    }

    if ((inbounds(position_x - 1, position_y) == true) && (rooms[position_x - 1][position_y].get_event() != ' ')) {
        std::cout << rooms[position_x - 1][position_y].get_messages() << endl;
    }
}
void Game::shoot_arrow() {
    set_movement();
    int tempX = position_x;
    int tempY = position_y;
    std::cout << "Arrow shot -> -> ->" << endl;

    // Determine the arrow's path and check if it hit the Wumpus
    if (player_mvnt == 'S') {
        for (int i = 1; i < 4; i++) {
            tempX = position_x + i;
            tempY = position_y;
            if (!(inbounds(tempX, tempY) && rooms[tempX][tempY].get_event() == 'W')) {
                std::cout << "Your arrow missed the Wumpus." << endl;
            } else {
                std::cout << "You have successfully eliminated the Wumpus!" << endl;
                wumpusdead = true;
                break;
            }

        }
    } else if (player_mvnt == 'D') {
        for (int i = 1; i < 4; i++) {
            tempX = position_x;
            tempY = position_y + i;
            if (!(inbounds(tempX, tempY) && rooms[tempX][tempY].get_event() == 'W')) {
                std::cout << "Your arrow missed the Wumpus." << endl;
            } else {
                std::cout << "You have successfully taken down the Wumpus!" << endl;
                wumpusdead = true;
                break;
            }

        }
    } else if (player_mvnt == 'A') {
        for (int i = 1; i < 4; i++) {
            tempX = position_x;
            tempY = position_y - i;
            if (inbounds(tempX, tempY) && rooms[tempX][tempY].get_event() == 'W') {
                std::cout << "You have successfully slain the Wumpus!" << endl;
                wumpusdead = true;
                break;
            } else {
                std::cout << "Your arrow missed the Wumpus." << endl;
            }
        }
    } else if (player_mvnt == 'W') {
        for (int i = 1; i < 4; i++) {
            tempX = position_x - i;
            tempY = position_y;
            if (inbounds(tempX, tempY) && rooms[tempX][tempY].get_event() == 'W') {
                std::cout << "You have successfully vanquished the Wumpus!" << endl;
                wumpusdead = true;
                break;
            } else {
                std::cout << "Your arrow missed the Wumpus." << endl;
            }
        }
    }
}

void Game::run_game(int num) {
    if (startingOver) {
        set_Size(); // Determine the cave size if restarting
    }
    Size = num;
    set_rooms(); // Create the array and initialize as empty spaces
    set_StartingPos(); // Establish a random starting point within the cave
    set_events(); // Populate cave locations with events
    output_grid(); // Display the layout of the cave

    while (!gameover) { // Transition from a do-while loop to a while loop
        std::cout << endl;
        std::cout << "Gold discovered: " << numGold << endl;
        std::cout << "Arrows remaining: " << arrows << endl;
        std::cout << "Position: " << position_x << " " << position_y << endl;

        out_messages();
        menu(); // Decide whether to move or shoot
        output_grid(); // Display the cave layout
        check_if_won();
    }

    endgame();
}
