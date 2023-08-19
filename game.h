/******************************************************
** File: game.cpp
** Author:
** Date: 08/10/2023
** Description: Implementation of the Hunt the Wumpus game logic
** Input: User interactions for cave size and player moves
** Output: Displays game outcomes (win or lose)
******************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "room.h"


class Game : Room { // Inheriting from the Room class
protected:
    Room** rooms; // Pointer to a 2D array of Room objects
    int Size, arrows, numGold; // Various game parameters
    int start_x, start_y, position_x, position_y, action; // Player-related positions and actions
    char player_mvnt; // Player's movement choice
    bool gameover, won, startingOver, wumpusdead; // Game state indicators

public:
    // Constructor for the Game class
    Game();

    // Mutators
    void set_Size();
    void set_rooms();
    void set_events();
    void set_movement();
    void set_StartingPos();
    int set_RandPos();
    void adjust_arrows();
    bool inbounds(int, int);

    // Accessors
    char get_movement();
    void get_action();
    bool get_won();

    // Destructor for the Game class
    ~Game();

    // Game functions
    void run_game(int);
    void output_grid();
    void mv_player();
    void check_event();
    void menu();
    void out_messages();
    void shoot_arrow();
    void endgame();
    void check_if_won();
};

#endif

