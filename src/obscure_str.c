#include "obscure_str.h"

/////////////////////
// STDLIB INCLUDES //
/////////////////////



#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

///////////////
// CONSTANTS //
///////////////

const size_t CHAR_RANGE = abs(CHAR_MIN) + CHAR_MAX;

//////////////////////////
// FUNCTION DEFINITIONS //
//////////////////////////



char* obscure_string(const char* password, const char* str)
{
// Check the validity of the params

    if (password == NULL || str == NULL)
    {
        return NULL;
    }

// Declare vars

    size_t str_len = strlen(str);
    size_t pass_len = strlen(password);


    size_t str_i = 0;
    size_t pass_i = 0;

// Malloc a string the same size as str to be the result.

    char* result = (char*) malloc(sizeof(char) * (str_len + 1));
    if (result == NULL) return NULL;
    strcpy(result, str);


// Obscure the string based on the password, by looping through, adding ascii values (in a ceasarian cipher kind of way),
// and adding the length of the string.

    const int CHAR_RANGE = abs(CHAR_MIN) + CHAR_MAX;

    while (str[str_i] != '\0')
    {
        int result_val = (int)str[str_i] + (int)password[pass_i] + (int)str_len;
        while (result_val > CHAR_MAX) result_val -= CHAR_RANGE;
        while (result_val < CHAR_MIN) result_val += CHAR_RANGE;

        result[str_i] = (char)result_val;

        str_i++;
        pass_i++;

        if (pass_i == pass_len) pass_i = 0;
    }

    return result;
}

char* unobscure_string(const char* password, const char* str)
{
// Check the validity of the params.

    if (password == NULL || str == NULL)
    {
        return NULL;
    }

// Declare vars

    size_t str_len = strlen(str);
    size_t pass_len = strlen(password);

    size_t str_i = 0;
    size_t pass_i = 0;

    char* result;

// Dynamically allocate a copy of str to funtion as the result.

    result = (char*) malloc(sizeof(char) * (str_len + 1));
    if (result == NULL) return NULL;
    strcpy(result, str);

// Unobscure the string based upon the password, doing the opposite of what
// was done by obscure_string().

    while (str[str_i] != '\0')
    {
        int result_val = (int)str[str_i] - (int)password[pass_i] - str_len;
        while (result_val > CHAR_MAX) result_val -= CHAR_RANGE;
        while (result_val < CHAR_MIN) result_val += CHAR_RANGE;

        result[str_i] = (char)result_val;

        str_i++;
        pass_i++;

        if (pass_i == pass_len) pass_i = 0;
    }

    return result;
}