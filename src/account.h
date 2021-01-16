///////////////////////////////////////////////////////////////////////////////
// Data structure defining a user account, that is, a username and password. //
// Author: Andrew Huffman                                                    //
///////////////////////////////////////////////////////////////////////////////

#ifndef ACCOUNT_PROPWD_H
#define ACCOUNT_PROPWD_H

/////////////////////
// STDLIB INCLUDES //
/////////////////////



#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


//////////////////////
// PROJECT INCLUDES //
//////////////////////



#include "account.h"



/////////////
// STRUCTS //
/////////////



// A user account, that is, a username and password.
struct account
{
    char* username;
    char* password;
    char* holder;
};



//////////////////////
// STRUCT FUNCTIONS //
//////////////////////



// Initialization function for the 'account' struct.
//
// username: const char* -> The username of the account.
// password: const char* -> The password of the account.
//
// returns ->
//      The initialized struct pointer.
//      NULL if there are any errors.
//
// error conditions ->
//      either parameters are NULL.
//      malloc() fails (not enough memory).
struct account* account_init(const char* username, const char* password, const char* holder);

// Free function for pointers to 'accounts.'
//
// ptr: struct account* -> The account pointer to free.
void account_free(struct account* ptr);


// Creates a DYNAMICALLY ALOCATED string representation of an acount struct.
//
// ptr: const struct account* -> The account to build a string off of.
//
// returns ->
//      The dynamically alocated string representation.
//      NULL if any error conditions are met.
//
// error conditions ->
//      param ptr is NULL.
//      malloc() fails (out of memory).
char* account_to_str(const struct account* ptr);

// Builds an account data structure from a provided character string.
//
// str: const char* -> The string to convert to an 'account'.
//
// returns ->
//      The dynamically allocated account data structure.
//      NULL if any error conditions are met.
//
// error conditions ->
//      param 'str' is NULL.
//      malloc() fails (out of memory).
//      'str' is of an incorrect format.
bool account_from_str(const char* str, struct account** result);



//////////////////////
// HELPER FUNCTIONS //
//////////////////////


bool account_write(const char * filename, const char* password, const struct account ** accounts, size_t accounts_len);

bool account_read(const char * filename, const char* password, struct account *** accounts, size_t * accounts_len);

// Writes an array of accounts to a file specified by the filename.
//
// filename: const char* -> The name of the file to open.
// password: const char* -> The obscuration password to obscure the file with.
// accounts: const struct account** -> The array of accounts to write to.
// accounts_len: size_t -> The length of the array of accounts to write to.
//
// returns ->
//      1 if the function operates correctly.
//      0 if any error conditions are met.
//
// error conditions ->
//      Any pointer parameter is NULL.
//      No writes were completed to the file.
//      The file was unable to be opened for writing.
int accounts_write_to_file_old(const char* filename, const char* password, const struct account** accounts, size_t accounts_len);

int account_write_to_file_old(const char* filename, const char* password, const struct account* account);

// Gets a DYNAMICALLY ALLOCATED array of accounts from a specified filename.
//
// filename: const char* -> The name of the file to open.
// password: const char* -> The obscuration password to unobscure the file with.
// result_len_out: size_t* -> An out parameter specifying the size of the resulting array.
//
// returns ->
//      A DYNAMICALLY ALLOCATED list of DYNAMICALLY ALLOCATED account structures read from the file.
//      NULL if any error conditions are met.
//
// error conditions ->
//      Any parameter is NULL.
//      The file was unable to be opened for reading.
struct account** account_get_from_file_old(const char* filename, const char* password, struct account*** result, size_t* size);

#endif // ACCOUNT_PROPWD_H