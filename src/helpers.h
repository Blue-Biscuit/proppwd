/////////////////////////////////////////////////////////////////////
// Helper functions which will be used throughout the application. //
// Author: Andrew Huffman                                          //
/////////////////////////////////////////////////////////////////////


#ifndef HELPERS_PROPWD_H
#define HELPERS_PROPWD_H


/////////////////////
// STDLIB INCLUDES //
/////////////////////


#include <stdbool.h>
#include <stddef.h>


//////////////////////////
// FUNCTION DEFINITIONS //
//////////////////////////


// A string compare function which ignores case (basically strcmp but with tolower() calls on each character)
//
// returns: int ->
//     -1 if either strings are NULL.
//     0 if the strings are not equal.
//     1 if the strings are equal.
int equals_ignore_case(const char* a, const char* b);

// Tells whether a file exists at the filepath provided.
//
// filename: const char* -> The name of the file to check the existance of.
//
// returns: bool ->
//     true (1) if the file exists on the file system.
//     false (0) if the file does not exist on the file system.
bool file_exists(const char* filename);

// Allocates a substring of str, from the range of [begin, end).
//
// str: const char* -> The string to take the substring of.
// begin: size_t -> The beginning inclusive index of the substring.
// end: size_t -> The ending exclusive index of the substring.
//
// returns: char* ->
//     The substring at [begin, end), if successful.
//     NULL if any error conditions are met.
//
// error conditions ->
//     'str' is NULL.
//     'begin' is numerically greater than or equal to 'end'.
//     malloc() fails (out of memory).
char* substring(const char* str, size_t begin, size_t end);


#endif // HELPERS_PROPWD_H
