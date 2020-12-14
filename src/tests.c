//
// Created by John on 12/12/2020.
//

#include "tests.h"
/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"




bool tests()
{
    bool answer = false;
    bool ok1 = testInitializeGameBoard();
    bool ok2 = testPrintGameBoard();
    bool ok3 = testPutShipOnGameBoard();
    bool ok4 = testRandomlyPlaceShipsOnGameBoard();
    bool ok5 = testUpdateGameBoard();
    bool ok6 = testIsWinner();
    bool ok7 = testCheckSunkShip();
    bool ok8 = testCheckShot();

    answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
    return answer;
}


bool testInitializeGameBoard() {
    bool ok = true;
    puts("Testing initializeGameBoard");

    //Test case 1
    Cell testGameBoard[10][10];
    initializeGameBoard(testGameBoard);
    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            if (testGameBoard[i][j].symbol != WATER)
            {
                ok = false;
            }
            if (testGameBoard[i][j].position.row != i || testGameBoard[i][j].position.column != j)
            {
                ok = false;
            }
        }
    }
    if (ok)
    {
        puts("Test initializeGameBoard  passed");
    }
    else
    {
        puts("Test initializeGameBoard  did not pass");
    }

    return ok;
}

bool testPrintGameBoard() { //Visual test
    bool ok = true;
    puts("Testing printGameBoard");

    Cell testGameBoard[10][10];
    initializeGameBoard(testGameBoard);

    testGameBoard[5][5].symbol = CARRIER;

    printGameBoard(testGameBoard, TRUE);
    if (ok)
    {
        puts("Test printGameBoard passed");
    }
    else
    {
        puts("Test printGameBoard did not pass");
    }

    return ok;
}

bool testPutShipOnGameBoard() {
    bool ok = true;
    puts("Testing PutShipOnGameBoard");
    Coordinate position;
    int direction = -1;
    int i = 0;
    Cell testGameBoard[10][10];
    initializeGameBoard(testGameBoard);
    WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
                                     {'b', 4, "Battleship"},
                                     {'r', 3, "Cruiser"},
                                     {'s', 3, "Submarine"},
                                     {'d', 2, "Destroyer"}};

    direction = HORIZONTAL;
    position.column = 3;
    position.row = 3;

    putShipOnGameBoard (testGameBoard, ship[4], position, direction);

    if (testGameBoard[3][3].symbol != DESTROYER || testGameBoard[3][4].symbol != DESTROYER)
    {
        ok = false;
    }

    if (ok)
    {
        puts("Test PutShipOnGameBoard passed");
    }
    else
    {
        puts("Test PutShipOnGameBoard did not pass");
    }

    return ok;
}

bool testRandomlyPlaceShipsOnGameBoard() {
    bool ok = true;
    puts("Testing RandomlyPlaceShipsOnGameBoard ");

    Coordinate position;
    int direction = -1;
    int i = 0;
    Cell testGameBoard[10][10];
    initializeGameBoard(testGameBoard);
    WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
                                     {'b', 4, "Battleship"},
                                     {'r', 3, "Cruiser"},
                                     {'s', 3, "Submarine"},
                                     {'d', 2, "Destroyer"}};

    randomlyPlaceShipsOnGameBoard(testGameBoard, ship);
    bool ok1 = false, ok2 = false, ok3 = false, ok4 = false,ok5 = false;
    for(int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            if (testGameBoard[i][j].symbol == CARRIER)
            {
                ok1 = true;
            }
            if (testGameBoard[i][j].symbol == BATTLESHIP)
            {
                ok2 = true;
            }
            if (testGameBoard[i][j].symbol == CRUISER)
            {
                ok3 = true;
            }
            if (testGameBoard[i][j].symbol == SUBMARINE)
            {
                ok4 = true;
            }
            if (testGameBoard[i][j].symbol == DESTROYER)
            {
                ok5 = true;
            }
        }
    }
    //printGameBoard(testGameBoard, TRUE);
    ok = ok1 && ok2 && ok3 && ok4 && ok5;
    if (ok)
    {
        puts("Test RandomlyPlaceShipsOnGameBoard passed");
    }
    else
    {
        puts("Test RandomlyPlaceShipsOnGameBoard did not pass");
    }

    return ok;
}

bool testUpdateGameBoard() {
    bool ok = true;
    puts("Testing UpdateGameBoard");

    Coordinate position;
    int direction = -1;
    int i = 0;
    Cell testGameBoard[10][10];
    initializeGameBoard(testGameBoard);
    WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
                                     {'b', 4, "Battleship"},
                                     {'r', 3, "Cruiser"},
                                     {'s', 3, "Submarine"},
                                     {'d', 2, "Destroyer"}};

    direction = HORIZONTAL;
    position.column = 3;
    position.row = 3;

    putShipOnGameBoard (testGameBoard, ship[4], position, direction);

    updateGameBoard(testGameBoard, position);
    if (testGameBoard[3][3].symbol != HIT)
    {
        ok = false;
    }
    if (ok)
    {
        puts("Test UpdateGameBoard passed");
    }
    else
    {
        puts("Test UpdateGameBoard did not pass");
    }

    return ok;
}


bool testIsWinner() {
    bool ok = true;
    puts("Testing IsWinner");

    Stats players[2] = {{0, 0, 0, 0.0},
                        {0, 0, 0, 0.0}};
    short player = 0;

    //Test Case 1
    players[player].numHits = 17;
    bool ok1 = isWinner(players, player);

    players[player].numHits = 5;
    bool ok2 = !isWinner(players, player);

    ok = ok1 && ok2;
    if (ok)
    {
        puts("Test IsWinner passed");
    }
    else
    {
        puts("Test IsWinner did not pass");
    }

    return ok;
}


bool testCheckSunkShip() {
    bool ok = true;
    puts("Testing CheckSunkShip");

    Coordinate position;
    int direction = -1;
    int i = 0;
    Cell testGameBoard[10][10];
    initializeGameBoard(testGameBoard);
    WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
                                     {'b', 4, "Battleship"},
                                     {'r', 3, "Cruiser"},
                                     {'s', 3, "Submarine"},
                                     {'d', 2, "Destroyer"}};
    short sunkShip[2][NUM_OF_SHIPS] = {{5, 4, 3, 3, 2},
                                       {5, 4, 3, 3, 2}};
    direction = HORIZONTAL;
    position.column = 3;
    position.row = 3;
    short player = 0;
    putShipOnGameBoard (testGameBoard, ship[4], position, direction);

    updateGameBoard(testGameBoard, position);
    FILE* fp = fopen("testOutput.txt", "w");
    bool ok1 = !checkSunkShip(sunkShip, player, DESTROYER, fp);
    position.column = 3;
    updateGameBoard(testGameBoard, position);
    bool ok2 = checkSunkShip(sunkShip, player, DESTROYER, fp);

    ok = ok1 && ok2;
    if (ok)
    {
        puts("Test CheckSunkShip passed");
    }
    else
    {
        puts("Test CheckSunkShip did not pass");
    }

    return ok;
}



bool testCheckShot() {
    bool ok = true;
    puts("Testing CheckShot");
    Cell testGameBoard[10][10];
    initializeGameBoard(testGameBoard);
    Coordinate position;
    int direction = -1;
    int i = 0;
    direction = HORIZONTAL;
    position.column = 3;
    position.row = 3;
    WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
                                     {'b', 4, "Battleship"},
                                     {'r', 3, "Cruiser"},
                                     {'s', 3, "Submarine"},
                                     {'d', 2, "Destroyer"}};
    putShipOnGameBoard (testGameBoard, ship[4], position, direction);

    short answer = checkShot(testGameBoard, position);
    if (answer != 1)
    {
        ok = false;
    }
    if (ok)
    {
        puts("Test CheckShot passed");
    }
    else
    {
        puts("Test CheckShot did not pass");
    }

    return ok;
}

