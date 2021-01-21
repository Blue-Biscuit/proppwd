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

//////////////////////////////
// PRIVATE HELPER FUNCTIONS //
//////////////////////////////

char fix_range(int out_of_range_char)
{
//	WHILE the result is over the maximum character limit, decrement it by the character range.

	const int CHAR_RANGE = CHAR_MAX + abs(CHAR_MIN) + 1;

	while (out_of_range_char > CHAR_MAX) out_of_range_char -= CHAR_RANGE;

//	WHILE the result is under the minimum character limit, increment it by the character range.

	while (out_of_range_char < CHAR_MIN) out_of_range_char += CHAR_RANGE;

//	RETURN the result, cast again as a character.

	return (char)out_of_range_char;
}

char* obscure_string_toggle(const char* password, const char* str, bool obscure_or_unobscure)
{
//	Perform an initial parameter validity check.

	if (password == NULL || str == NULL)
	{
		return NULL;
	}

//	Allocate a buffer to store the result of the obscuration.

	size_t str_len = strlen(str);

	char* result = malloc(str_len + 1);
	result[str_len] = '\0';

//	Declare loop variables.

	size_t password_i = 0;
	size_t password_len = strlen(password);

//	FOR EACH character in the string...

	for (size_t i = 0; i < str_len; i++)
	{

//		Perform a Caeserian encode based upon the character of the string and the character of the password plus the length of the password.

		if (obscure_or_unobscure)
		{
			result[i] = caeserian_encode(str[i], (int)password[password_i] + password_len);
		}
		else
		{
			result[i] = caeserian_decode(str[i], (int)password[password_i] + password_len);
		}


//		Iterate loop variables.

		password_i++;

//		Reset the password if it's greater than or equal to the length.

		if (password_i >= password_len)
		{
			password_i = 0;
		}
	}

	return result;
}

//////////////////////////
// FUNCTION DEFINITIONS //
//////////////////////////


char* obscure_string(const char* password, const char* str)
{
	return obscure_string_toggle(password, str, true);
}

char* unobscure_string(const char* password, const char* str)
{
	return obscure_string_toggle(password, str, false);
}

char caeserian_encode(char c, int offset)
{
//	Convert the passed character to an int and add the offset.

	int result = (int)c + offset;

	return fix_range(result);
}

char caeserian_decode(char c, int offset)
{
//	Convert the passed character to an int and subtract the offset.

	int result = (int)c - offset;

	return fix_range(result);
}
