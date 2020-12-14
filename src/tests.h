//
// Created by John on 12/12/2020.
//

#ifndef CS2301_HW6_BATTLESHIP_TESTS_H
#define CS2301_HW6_BATTLESHIP_TESTS_H


#include "production.h"
#include "board.h"
#include "battleship.h"

bool tests();

//Board Functions
bool testInitializeGameBoard();

bool testPrintGameBoard();

bool testPutShipOnGameBoard();

bool testRandomlyPlaceShipsOnGameBoard();

bool testUpdateGameBoard();

bool testIsWinner();



//Battleship Functions
bool testCheckSunkShip();

bool testCheckShot();

#endif //CS2301_HW6_BATTLESHIP_TESTS_H
