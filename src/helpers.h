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

// A string compare function which ignores case (basically strcmp but with tolower() calls on each character)
//
// returns: int ->
//     -1 if either strings are NULL.
//     0 if the strings are not equal.
//     1 if the strings are equal.
int equals_ignore_case(const char* a, const char* b);


bool file_exists(const char* filename);

// Allocates a substring of str, from the range of [begin, end).
char* substring(const char* str, size_t begin, size_t end);




#endif // HELPERS_PROPWD_H