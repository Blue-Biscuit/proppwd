#include "helpers.h"

/////////////////////
// STDLIB INCLUDES //
/////////////////////

#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <stdlib.h>

//////////////////////////
// FUNCTION DEFINITIONS //
//////////////////////////

int equals_ignore_case(const char* a, const char* b)
{
// If either args are NULL, return -1.

    if (a == NULL || b == NULL)
    {
        return -1;
    }

// Define loop vars.

    size_t alen = strlen(a);
    size_t blen = strlen(b);

// If the lengths are not equal, the strings are not equal.

    if (alen != blen)
    {
        return 0;
    }

// Check to see if the tolower() of both of the characters are equal.
// If not, then the strings are not equal, and 0 can be returned.

    for (size_t i = 0; i < alen; i++)
    {

        if (tolower(a[i]) != tolower(b[i]))
        {
            return 0;
        }
    }

// If all tests have passed, return 1.

    return 1;
}

bool file_exists(const char* filename)
{
    struct stat buffer;
    int exist = stat(filename, &buffer);

    if (exist == 0) return 1;
    else return 0;
}

char* substring(const char* str, size_t begin, size_t end)
{
    if (begin >= end || str == NULL) return NULL;

    char* result = malloc(end - begin + 1);
    memcpy(result, str + begin, end - begin);
    result[end - begin] = '\0';

    return result;
}