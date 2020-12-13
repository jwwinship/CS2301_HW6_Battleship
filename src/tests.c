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
    bool ok1 = testReadFile();
    bool ok2 = testMakeLList();

    bool ok7 = testPrintHistory();
    answer = ok1 && ok2 && ok7;
    return answer;
}


bool testMakeLList() //Tests the making of a list and the enqueue behavior.
{
    bool ok = true;

    if (!ok)
    {
        puts("test make LList did not pass.");
    }
    else
    {
        puts("Test make LList passed.");
    }

    return ok;
}

bool testPrintHistory() //Visual test. If the following list of search results is printed, the test is a success.
{
    bool ok = true;

    return ok;
}

bool testReadFile()
{
    puts("starting testReadFile");
    bool ok = true;


    return ok;
}

