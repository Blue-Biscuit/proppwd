///////////////////////////////////////////////////////////////////
// Console user interface functions for the ProPass application. //
// Author: Andrew Huffman                                        //
///////////////////////////////////////////////////////////////////

#ifndef C_INTERFACE_PROPWD_H
#define C_INTERFACE_PROPWD_H





///////////////
// FUNCTIONS //
///////////////



// Executes the console user interface.
//
// argc: int -> The number of command-line arguments provided.
// argv: char** -> The command-line string arguments provided.
void run_cint(int argc, char** argv);

// Parses the passed arguments, figuring out which component of the
// application to run based upon user input.
//
// argc: int -> The number of command-line arguments provided.
// argv: char** -> The command-line string arguments provided.
//
// returns: int -> A return code defining what part of the application should be run.
int _parse_args_cint(int argc, char** argv);

// Prints a standard usage explanation to stdout.
void _help_print_cint();

// Adds to the specified passfile based upon user command-line arguments.
//
// argc: int -> The number of user-provided arguments.
// argv: char** -> The user-provided arguments.
//     (for this function, they should be of the format <appname> -a <mp> <username> <pass> [file])
void _add_cint(int argc, char** argv);

// Removes from the specified passfile based upon user command-line arguments.
//
// argc: int -> The number of user-provided arguments.
// argv: char** -> The user-provided arguments.
//     (for this function, they should be of the format <appname> -r <mp> <username> [file])
void _remove_cint(int argc, char** argv);

// Lists from the specified passfile based upon user command-line arguments.
// If no user is specified, then the whole file is listed.
//
// argc: int -> The number of user-provided arguments.
// argv: char** -> The user-provided arguments.
//     (for this function, they should be of the format <appname> -l <mp> [file] [username])
void _list_cint(int argc, char** argv);




#endif // C_INTERFACE_PROPWD_H