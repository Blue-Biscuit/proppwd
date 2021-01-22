//////////////////////////////////////////////////////////
// The main execution file for the ProPass application. //
// Author: Andrew Huffman                               //
//////////////////////////////////////////////////////////


//////////////////////
// PROJECT INCLUDES //
//////////////////////

#include "c_interface.h"
#include "account.h"
#include "obscure_str.h"
#include "tester.h"

/////////////////////
// STDLIB INCLUDES //
/////////////////////

#include <stdio.h>
#include <stdbool.h>

/////////////
// DEFINES //
/////////////

#define TESTING 1

///////////////
// FUNCTIONS //
///////////////


int main(int argc, char** argv)
{
    if (TESTING)
    {
        run_tests();
    }
    else
    {
        run_cint(argc, argv);
    }

}
