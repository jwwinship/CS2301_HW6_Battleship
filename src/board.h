//
// Created by John on 12/12/2020.
//

#ifndef CS2301_HW6_BATTLESHIP_BOARD_H
#define CS2301_HW6_BATTLESHIP_BOARD_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "battleship.h"


/* FUNCTION PROTOTYPES */

void         welcomeScreen                  (void);

void         initializeGameBoard            (Cell gameBoard[][COLS]);

void         printGameBoard                 (Cell gameBoard [][COLS], Boolean showPegs);

void         putShipOnGameBoard             (Cell gameBoard[][COLS], WaterCraft ship, Coordinate position, int direction);

void         manuallyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], WaterCraft ship[]);

void         randomlyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], WaterCraft ship[]);

void         updateGameBoard                (Cell gameBoard[][COLS], Coordinate target);

Boolean      isValidLocation                (Cell gameBoard[][COLS], Coordinate position, int direction, int length);

Boolean      convertStringtoPosition        (Coordinate position[], char *stringPosition, int length);

Boolean      isWinner                       (Stats players[], int player);

Coordinate   generatePosition               (int direction, int length);

int          getRandomNumber                (int lowest, int highest);
#endif //CS2301_HW6_BATTLESHIP_BOARD_H
