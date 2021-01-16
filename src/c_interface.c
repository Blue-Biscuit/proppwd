#include "c_interface.h"

/////////////////////
// STDLIB INCLUDES //
/////////////////////

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>

//////////////////////
// PROJECT INCLUDES //
//////////////////////

#include "helpers.h"
#include "obscure_str.h"
#include "account.h"

/////////////
// DEFINES //
/////////////

#define DEFAULT_PASSFILE "pf.out"

#define PARSE_ARGS_CINT_ERROR -1
#define PARSE_ARGS_CINT_NO_ARGS 0
#define PARSE_ARGS_CINT_HELP 1
#define PARSE_ARGS_CINT_ADD 2
#define PARSE_ARGS_CINT_REMOVE 3
#define PARSE_ARGS_CINT_LIST 4

//////////////////////////
// FUNCTION DEFINITIONS //
//////////////////////////

void run_cint(int argc, char** argv)
{
// Obtain an argument code, and switch the result.

    int command = _parse_args_cint(argc, argv);
    switch(command)
    {
    
    // If no arguments were provided to parse, then inform the user of that.

        case (PARSE_ARGS_CINT_NO_ARGS):
            printf("error: no operation specified (use -h or --help to see possible operations)\n");
            break;

    // If the argument parsing errored or a help signal was returned, then print a help message.

        case (PARSE_ARGS_CINT_ERROR):
        case (PARSE_ARGS_CINT_HELP):
            _help_print_cint(argc, argv);
            break;
    
    // If there are no more errors, then route the results of the command to their dedicated functions.

        case (PARSE_ARGS_CINT_ADD):
            _add_cint(argc, argv);
            break;
        
        case (PARSE_ARGS_CINT_REMOVE):
            _remove_cint(argc, argv);
            break;

        case (PARSE_ARGS_CINT_LIST):
            _list_cint(argc, argv);
            break;
    }
}

int _parse_args_cint(int argc, char** argv)
{
// If there are no arguments provided (other than the app name), then signal a
// command error.

    if (argc < 2)
    {
        return PARSE_ARGS_CINT_NO_ARGS;
    }

// If the passed argument is -h or --help (ignoring case), then send a help signal.

    else if (equals_ignore_case("-h", argv[1]) || equals_ignore_case("--help", argv[1]))
    {
        return PARSE_ARGS_CINT_HELP;
    }

// If the passed argument is -a or --add (ignoring case), then send an add signal.

    else if (equals_ignore_case("-a", argv[1]) == 1 || equals_ignore_case("--add", argv[1]) == 1)
    {
        return PARSE_ARGS_CINT_ADD;
    }

// If the passed argument is -r or --remove (ignoring case), then send a remove signal.

    else if (equals_ignore_case("-r", argv[1]) == 1 || equals_ignore_case("--remove", argv[1]) == 1)
    {
        return PARSE_ARGS_CINT_REMOVE;
    }

// If the passed argument is -l or --list (ignoring case), then send a list signal.

    else if (equals_ignore_case("-l", argv[1]) == 1 || equals_ignore_case("--list", argv[1]) == 1)
    {
        return PARSE_ARGS_CINT_LIST;
    }

// If no other commands have been found, signal a command error.

    return PARSE_ARGS_CINT_ERROR;
}

void _help_print_cint(int argc, char** argv)
{
    char* appname = argv[0];

    if (argc < 3)
    {
        printf("usage: %s <operation> <master password> [...]\n", appname);
        printf("operations:\n");
        printf("\t%s {-a --add} <master password> <username> <password> [passfile]\n", appname);
        printf("\t%s {-r --remove} <master password> <holder> [username] [passfile]\n", appname);
        printf("\t%s {-l --list} <master password> [holder] [passfile]\n", appname);
        printf("\t%s {-h --help} [command]\n", appname);
        printf("\n");
    }
    else
    {
        char* command = argv[2];

        if (equals_ignore_case("-a", command) || equals_ignore_case("--add", command))
        {
            printf("usage: %s {-a --add} <master password> <username> <password> [passfile]\n", appname);
            printf("description:\n");
            printf("\tAdds a username/password set to a specified passfile. If none is given, defaults\n");
            printf("\tto '");
            printf(DEFAULT_PASSFILE);
            printf("'\n");

            printf("parameters:\n");
            printf("\tmaster password: The master obscuration password which will be used to\n");
            printf("\t\tinterpret the passfile.\n");
            printf("\tusername: The username of the account to add to the passfile.\n");
            printf("\tpassword: The password of the account to add to the passfile.\n");
            printf("\tpassfile: The filename of the output file which will be appended to/created.\n");

            printf("\n");
        }
        else if (equals_ignore_case("-r", command) || equals_ignore_case("--remove", command))
        {
            printf("usage: %s {-r --remove} <master password> <holder> [username] [passfile]\n", appname);
            printf("description:\n");
            printf("\tRemoves a username/password set from the specified passfile. If no passfile is given,\n");
            printf("\tdefaults to '");
            printf(DEFAULT_PASSFILE);
            printf("'\n");

            printf("parameters:\n");
            printf("\tmaster password: The master obscuration password which will be used to\n");
            printf("\t\tinterpret the passfile.\n");
            printf("\tholder: The account holder of the account to be removed from the passfile.\n");
            printf("\t\t(ex. amazon)\n");
            printf("\tusername: The username of the account to be removed from the passfile.\n");
            printf("\tpassfile: The filename of the output file which will be removed from.\n");

            printf("\n");
        }
        else if (equals_ignore_case("-l", command) || equals_ignore_case("--list", command))
        {
            printf("usage: %s {-l --list} <master password> [holder] [passfile]\n", appname);
            printf("description:\n");
            printf("\tLists one or all of the username/password sets in a passfile.\n");

            printf("parameters:\n");
            printf("\tmaster password: The master obscuration password which will be used to\n");
            printf("\t\tinterpret the passfile.\n");
            printf("\tpassfile: The filename of the input file to list from.\n");
            printf("\tholder: Optional parameter to list only usernames and passwords under a specific holder.\n");

            printf("\n");
        }
        else if (equals_ignore_case("-h", command) || equals_ignore_case("--help", command))
        {
            printf("usage: %s {-h --help} [command]\n", appname);
            printf("description:\n");
            printf("\tProvides help to the user, aiding in the process of using the program in general\n");
            printf("\tor rather in using specific commands.\n");

            printf("parameters:\n");
            printf("\tcommand: Optional parameter to display a help dialogue for a specific command.\n");

            printf("\n");
        }
    }
}

void _add_cint(int argc, char** argv)
{
// Check param validity. Print an error message and quit if a problem is found.

    bool use_default_infile;

    if (argc < 6)
    {
        printf("\tusage: %s {-a --add} <master password> <holder> <username> <password> [passfile]\n", argv[0]);
        printf("\n");
        return;
    }

    use_default_infile = argc < 7;

// Rename params for easy and clear usage

    const char* appname = argv[0];
    const char* command = argv[1];
    const char* master_pass = argv[2];
    const char* holder = argv[3];
    const char* username = argv[4];
    const char* password = argv[5];
    const char* passfile = use_default_infile ? DEFAULT_PASSFILE : argv[6];

// If the given filename exists, get its contents as a list of accounts.

    struct account** accounts = NULL;
    size_t accounts_size = 0;

    if (file_exists(passfile))
    {
        // account_get_from_file(passfile, password, &accounts, &accounts_size);
        if (!account_read(passfile, master_pass, &accounts, &accounts_size))
        {
                printf("TODO: Handle this error! (account_read() in _add_cint() failed\n");
        }
    }
    
// Build the new account and add it to the list.

    struct account* new_account = account_init(username, password, holder);
    accounts_size++;

    accounts = realloc(accounts, sizeof(struct account*) * accounts_size);
    accounts[accounts_size - 1] = new_account;

// Write the list to the specified outfile.

    // accounts_write_to_file(passfile, password, (const struct account**) accounts, accounts_size);
    account_write(passfile, master_pass, (const struct account**)accounts, accounts_size);

// Free claimed resources (new_account is in accounts, so it doesn't need to be
// explicitly free()'d outside of a general loop).

    for (size_t i = 0; i < accounts_size; i++)
    {
        account_free(accounts[i]);
    }
    free(accounts);
}

void _remove_cint(int argc, char** argv)
{
//  Check param validity.

    if (argc < 4)
    {
        printf("usage: %s {-r --remove} <master password> <holder> [username] [passfile]\n", argv[0]);
        return;
    }

//  Determine what fields are being searched for from the list of accounts.

    bool by_username = argc >= 5;
    bool default_passfile = argc < 6;

//  Give each parameter a named variable for ease of use.

    const char* appname = argv[0];
    const char* command = argv[1];
    const char* master_pass = argv[2];
    const char* holder = argv[3];
    const char* username = by_username ? argv[4] : NULL;
    const char* passfile = default_passfile ? DEFAULT_PASSFILE : argv[5];

//  IF the provided passfile exists...

    if (file_exists(passfile))
    {

//      Load the list of accounts from the file.

        struct account** accounts = NULL;
        size_t accounts_len = 0;

        bool result = account_read(passfile, master_pass, &accounts, &accounts_len);

//      LOOP THROUGH the list...

//          IF the current account matches the search criteria...

//              Mark it for deletion.

//      Rebuild the list, removing marked accounts.

//      Save the list to the file.

    }
}

void _list_cint(int argc, char** argv)
{
// Check param validity.

    bool sorting_output;
    bool default_passfile;

    if (argc < 3)
    {
        printf("usage: %s {-l --list} <master password> [holder] [passfile]\n", argv[0]);
        printf("\n");
        return;
    }
    
    sorting_output = argc >= 4;
    default_passfile = argc < 5;

// Rename params for easier and clearer usage.

    const char* appname = argv[0];
    const char* command = argv[1];
    const char* master_pass = argv[2];
    const char* holder = sorting_output ? argv[3] : "all";
    const char* passfile = default_passfile ? DEFAULT_PASSFILE : argv[4];

// See if the file exists. If not, display an error.

    if (!file_exists(passfile))
    {
        printf("file '");
        printf(passfile);
        printf("' does not exist.");
        printf("\n");

        return;
    }

// Get a list of accounts from the file.

    struct account** accounts = NULL;
    size_t accounts_len = 0;

    account_read(passfile, master_pass, &accounts, &accounts_len);

// If we are to sort output, sort output. Else, just print the entire thing.

    if (equals_ignore_case(holder, "all"))
    {
        for (size_t i = 0; i < accounts_len; i++)
        {
            char* str = account_to_str(accounts[i]);

            if (str != NULL)
            {
                printf("%s\n", str);

                free(str);
            }
            free(accounts[i]);
        }
    }
    else
    {
        for (size_t i = 0; i < accounts_len; i++)
        {
            if (equals_ignore_case(accounts[i]->holder, holder))
            {
                char* str = account_to_str(accounts[i]);
                printf("%s\n", str);

                free(str);
            }

            free(accounts[i]);
        }
    }

// Free the rest of the claimed resources.

    free(accounts);

    printf("\n");
}