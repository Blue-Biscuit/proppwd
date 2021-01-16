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

/////////////////////
// STDLIB INCLUDES //
/////////////////////

#include <stdio.h>
#include <stdbool.h>

/////////////
// DEFINES //
/////////////

#define TESTING 0

///////////////
// FUNCTIONS //
///////////////

void run_tests();

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

void run_tests()
{   
    const size_t size = 10;
    struct account ** accounts = malloc(sizeof(struct account *) * size);

    for (int i = 0; i < size; i++)
    {
        accounts[i] = account_init("user", "pass", "holder");
    }

    bool result = account_write("test.out", "pass", (const struct account **)accounts, size);
    if (!result)
    {
        printf("Looks like account_write() failed somewhere!\n");
    }

    struct account ** accounts2 = NULL;
    size_t accounts2_size = 0;
    result = account_read("test.out", "pass", &accounts2, &accounts2_size);

    if (!result)
    {
        printf("Looks like account_read() failed somewhere!\n");
    }

    for (size_t i = 0; i < accounts2_size; i++)
    {
        printf("%s %s %s\n", accounts2[i]->holder, accounts2[i]->username, accounts2[i]->password);
    }
}