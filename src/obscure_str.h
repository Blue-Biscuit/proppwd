///////////////////////////////////////////////////////////////////////////////////////////
// Function definitions to obscure (not encrypt) strings based upon a provided password. //
// Author: Andrew Huffman                                                                //
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef OBSCURE_STR_PROPWD_H
#define OBSCURE_STR_PROPWD_H

///////////////
// FUNCTIONS //
///////////////



// Obscures a string based upon the provided password.
//
// password: const char* -> The password to obscure the string based upon.
// str: const char* -> The string to obscure.
//
// returns ->
//      a DYNAMICALLY ALOCATED string representing the obscuration result.
//      if an error condition is met, returns NULL.
//
// error conditions ->
//      either param is NULL.
//      malloc() fails (out of memory).
char* obscure_string(const char* password, const char* str);


// Converts an obscured string back to its normal form based upon a password.
//
// password: const char* -> The password to obscure the string based upon.
// str: const char* -> The string to unobscure.
//
// returns ->
//      a DYNAMICALLY ALOCATED string representing the unobscuration result.
//      if an error condition is met, returns NULL.
//
// error conditions ->
//      either param is NULL.
//      malloc() fails (out of memory).
char* unobscure_string(const char* password, const char* str);


#endif // OBSCURE_STR_PROPWD_H