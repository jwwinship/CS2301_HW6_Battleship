/*==============================================================================
 | Filename: battleship.h
 | Programmer: Gabriel V. de a Cruz Jr.
 | Class: CptS 121, Fall 2012 ; Lab Section 7
 | Programming Assignment 4: Basic Game of Battleship
 | Date: October 17, 2012
 +------------------------------------------------------------------------------
 | Description: Thie file contains all the function definition of the prototypes
 |              listed in battleship.h These are the functions necessary to run
 |              the game of Battleship.
 ==============================================================================*/

#include "battleship.h"
#include "board.h"

/**
 * Function name : checkBoundsOfCardinal ()
 * Date Created  : 17 October 2012
 * Usage         : checkBoundsOfCardinal (Boolean [], int, int);
 * Definition    : This function checks if the specified direction is
 *                 not over the bounds and sets the cardinals with TRUE
 *                 if its within bounds, otherwise FALSE
 * Pre-condition : n/a
 * Post-condition: Updates the cardinals array
 */
void checkBoundsOfCardinal (Boolean cardinals[], int bound, int direction) {
    switch (direction) {
        case NORTH:
            if (bound < 0)
                cardinals[0] = FALSE;
            else
                cardinals[0] = TRUE;
            break;

        case SOUTH:
            if (bound > 9)
                cardinals[1] = FALSE;
            else
                cardinals[1] = TRUE;
            break;

        case WEST:
            if (bound < 0)
                cardinals[2] = FALSE;
            else
                cardinals[2] = TRUE;
            break;

        case EAST:
            if (bound > 9)
                cardinals[3] = FALSE;
            else
                cardinals[3] = TRUE;
            break;
    }
}

/**
 * Function name : checkSunkShip ()
 * Date Created  : 17 October 2012
 * Usage         : checkSunkShip (shor [][], short, char, FILE *);
 * Definition    : This function check if a ship has sunk based on the
 *                 how of the length of ship is left. If a ship was sunk
 *                 it is logged on an output file
 * Pre-condition : stream to output file was created
 * Post-condition: n/a
 */
Boolean checkSunkShip (short sunkShip[][NUM_OF_SHIPS], short player, char shipSymbol, FILE *stream) {
    Boolean sunked = FALSE;

    switch (shipSymbol) {
        case CARRIER:
            if (--sunkShip[player][0] == 0) {
                printf ("> Player %d's Carrier sunked!\n", player + 1);

                /* Write to battleship.log */
                fprintf (stream, "Player %d's Carrier sunked!\n", player + 1);

                sunked = TRUE;
            }
            break;

        case BATTLESHIP:
            if (--sunkShip[player][1] == 0) {
                printf ("> Player %d's Battleship sunked!\n", player + 1);

                /* Write to battleship.log */
                fprintf (stream, "Player %d's Battleship sunked!\n", player + 1);

                sunked = TRUE;
            }
            break;

        case CRUISER:
            if (--sunkShip[player][2] == 0) {
                printf ("> Player %d's Cruiser sunked!\n", player + 1);

                /* Write to battleship.log */
                fprintf (stream, "Player %d's Cruiser sunked!\n", player + 1);

                sunked = TRUE;
            }
            break;

        case SUBMARINE:
            if (--sunkShip[player][3] == 0) {
                printf ("> Player %d's Submarine sunked!\n", player + 1);

                /* Write to battleship.log */
                fprintf (stream, "Player %d's Submarine sunked!\n", player + 1);

                sunked = TRUE;
            }
            break;

        case DESTROYER:
            if (--sunkShip[player][4] == 0) {
                printf ("> Player %d's Destroyer sunked!\n", player + 1);

                /* Write to battleship.log */
                fprintf (stream, "Player %d's Destroyer sunked!\n", player + 1);

                sunked = TRUE;
            }
            break;
    }

    return sunked;
}

/**
 * Function name : getTarget ()
 * Date Created  : 17 October 2012
 * Usage         : getTarget ();
 * Definition    : This function reads a row and column values from
 *                 the user
 * Pre-condition : n/a
 * Post-condition: n/a
 */
Coordinate getTarget (void) {
    Coordinate target;

    fflush (stdin);
    Boolean getTargetFlag = TRUE;

    while (getTargetFlag == TRUE)
    {
        puts ("> Enter Target (ex. > 3 4):\n");
        puts ("> ");
        int numbersRead = scanf ("%d %d", &target.row, &target.column);
        if (numbersRead == 2)
        {
            getTargetFlag = FALSE;
        }
        else
        {
            puts("Invalid Input! Please try again");
        }
    }

    return target;
}

/**
 * Function name : checkShot ()
 * Date Created  : 17 October 2012
 * Usage         : checkShot (Cell [][], Coordinate);
 * Definition    : This function checks if the coordinates on the
 *                 game board is a miss, hit, water or water craft
 * Pre-condition : n/a
 * Post-condition: n/a
 */
short checkShot (Cell gameBoard[][COLS], Coordinate target) {
    int hit = -2;

    switch (gameBoard[target.row][target.column].symbol) {
        /* miss */
        case WATER:
            hit = 0;
            break;

            /* hit */
        case CARRIER:
        case BATTLESHIP:
        case CRUISER:
        case SUBMARINE:
        case DESTROYER:
            hit = 1;
            break;

        case HIT:
        case MISS:
        default:
            hit = -1;
            break;
    }

    return hit;
}

