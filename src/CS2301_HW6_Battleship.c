//
// Created by John on 12/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "battleship.h"
#include "board.h"

int main(int argc, char* argv[]) {
    setvbuf (stdout, NULL, _IONBF, 0); //If we don't set this, we get some really strange buffering issues, and many things just don't print
    puts("!!!Let's do  HW6!!!"); /* prints !!!Hello World!!! */
    if(tests())
    {
        puts ("All tests passed");
        puts ("-------------------------");
        puts("About to run production.");
        production(argc, argv);
    }
    else
    {
        puts("Tests did not pass.");
    }

    return EXIT_SUCCESS;

}