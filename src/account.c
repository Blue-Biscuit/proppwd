#include "account.h"

#include "obscure_str.h"
#include "helpers.h"

#include <stdio.h>
#include <ctype.h>

struct account* account_init(const char* username, const char* password, const char* holder)
{
// If params are invalid, return NULL.

    if (username == NULL || password == NULL || holder == NULL) return NULL;

// Initialize struct pointer.

    struct account* result = (struct account*) malloc(sizeof(struct account));
    if (result == NULL) return NULL;

// Initialize username, password, and holder pointers.

    result->username = (char*) malloc(sizeof(char) * (strlen(username) + 1));
    if (result->username == NULL) return NULL;

    result->password = (char*) malloc(sizeof(char) * (strlen(username) + 1));
    if (result->password == NULL) return NULL;

    result->holder = (char*) malloc(sizeof(char) * (strlen(holder) + 1));
    if (result->holder == NULL) return NULL;

// Copy param vals to result structure vals.

    strcpy(result->username, username);
    strcpy(result->password, password);
    strcpy(result->holder, holder);

// Return the resulting struct.

    return result;
}

void account_free(struct account* ptr)
{
    if (ptr != NULL)
    {
        if (ptr->username != NULL) free(ptr->username);
        if (ptr->password != NULL) free(ptr->password);
        if (ptr->holder != NULL) free(ptr->holder);
        free(ptr);
    }
}

char* account_to_str(const struct account* ptr)
{
// Variable Declarations

    char* result; // The final result of the function.
    size_t username_len; // The length of the username field.
    size_t password_len; // The length of the password field.
    size_t holder_len; // The length of the holder field.
    size_t i; // Iterator var which will be used to copy vals into result.

// Parameter Error Checking

    if (ptr == NULL) return NULL;

// Get the lengths of the username and password strings in 'ptr'.

    holder_len = strlen(ptr->holder);
    username_len = strlen(ptr->username);
    password_len = strlen(ptr->password);

// Alocate enough memory for the desired format of the resulting string in result.
// The format we are going for is <username> <password>, not too complicated.

    result = malloc(sizeof(char) * (username_len + password_len + holder_len + 3));
    if (result == NULL) return NULL;
    result[username_len + password_len + holder_len + 2] = '\0';

// Copy the holder into the string.

    for (i = 0; i < holder_len; i++)
    {
        result[i] = ptr->holder[i];
    }
    result[i] = ' ';
    i++;

// Copy the username into the string.

    size_t j;
    for (j = 0; j < username_len; j++)
    {
        result[i + j] = ptr->username[j];
    }
    result[i + j] = ' ';
    j++;

// Copy the password into the string.

    for (size_t k = 0; k < password_len; k++)
    {
        result[i + j + k] = ptr->password[k];
    }


    return result;
}

struct account* account_from_str_old(const char* str)
{
// Variable Declarations

    struct account* result; // The return of the function.
    size_t str_len; // The length of the entire provided string.
    size_t username_end_loc; // The position of the end of the username substring.
    size_t holder_end_loc; // The position of the end of the holder substring.
    size_t password_end_loc; // The position of the end of the password substring.
    char* holder_temp;
    char* username_temp; // A temp variable for storing the username substring.
    char* password_temp; // A temp variable for storing the password substring.

// Test parameter validity.

    if (str == NULL) return NULL;

// Find the space-delimited tokens within the string that will become the holder, username, and password.

    str_len = strlen(str);

    for (holder_end_loc = 0; holder_end_loc < str_len && str[holder_end_loc] != ' '; holder_end_loc++);

    for (username_end_loc = holder_end_loc + 1; username_end_loc < str_len && str[username_end_loc] != ' '; username_end_loc++);

    for (password_end_loc = username_end_loc + 1; password_end_loc < str_len && str[password_end_loc] != ' '; password_end_loc++);

// Do some simple tests of the validity to these indices.

    if (holder_end_loc == str_len || username_end_loc == str_len || holder_end_loc == 0) return NULL; // If there's any missing params, we have an error.

    if (holder_end_loc + 1 == username_end_loc || username_end_loc + 1 == password_end_loc) return NULL; // Bad spacing, there should only be one space between terms.


// Get substrings.

    size_t i = 0;

    holder_temp = (char*) malloc(sizeof(char) * (holder_end_loc + 1));
    if (holder_temp == NULL) return NULL;
    for (; i < holder_end_loc; i++)
    {
        holder_temp[i] = str[i];
    }
    holder_temp[i] = '\0';
    i++;

    username_temp = (char*) malloc(sizeof(char) * (username_end_loc - holder_end_loc));
    if (username_temp == NULL) return NULL;
    for (size_t j = 0; i < username_end_loc; i++, j++)
    {
        username_temp[j] = str[i];
    }
    username_temp[i] = '\0';
    i++;

    password_temp = (char*) malloc(sizeof(char*) * (password_end_loc - username_end_loc));
    if (password_temp == NULL) return NULL;
    for (size_t j = 0; i < password_end_loc; j++, i++)
    {
        password_temp[j] = str[i];
    }
    password_temp[i] = '\0';

// Initialize the struct instance.

    result = account_init(username_temp, password_temp, holder_temp);
    free(username_temp);
    free(password_temp);
    free(holder_temp);


    return result;
}

bool account_from_str(const char* str, struct account** result)
{
//  Do a preliminary parameter validity check.

    if (str == NULL || result == NULL) return false;

//  Allocate the passed account if it hasn't been already.

    if (*result == NULL) *result = malloc(sizeof(struct account));

//  Prepare for iteration by declaring vars and copying the passed string.

    size_t str_len = strlen(str);
    size_t i;
    size_t begin = 0;

//  (NOTE: If anything in the next few pieces of the algorithm fails, the process is in error.)
//  Find the end of the first substring (beginning -> first space), and copy to the holder field.

    for (i = 0; i < str_len && !isspace(str[i]); i++);
    (*result)->holder = substring(str, 0, i);
    i++;
    begin = i;

//  Find the end of the second substring (first space -> second space), and copy to the username field.

    for (; i < str_len && !isspace(str[i]); i++);
    if (i == str_len) return NULL;

    (*result)->username = substring(str, begin, i);
    i++;
    begin = i;

//  Find the end of the last substring (second space -> end), and copy to the password field.

    for (; i < str_len && !isspace(str[i]); i++);
    (*result)->password = substring(str, begin, i);

    return true;
}

int account_write_to_file(const char* filename, const char* password, const struct account* account)
{
    if (account == NULL) return 0;
    else return accounts_write_to_file(filename, password, &account, 1);
}

int accounts_write_to_file(const char* filename, const char* password, const struct account** accounts, size_t accounts_len)
{
// Check param validity.

    if (filename == NULL || password == NULL || accounts == NULL)
    {
        return 0;
    }

// Iterate over the list of provided accounts and print them to the file at the filename,
// all the while making sure to obscure them based upon the provided password.

    FILE* fd = fopen(filename, "w");
    if (!fd) return 0;

    size_t write_count = 0;

    for (size_t i = 0; i < accounts_len; i++)
    {
        if (accounts[i] == NULL) continue;

        char* str = account_to_str(accounts[i]);
        char* obscured = obscure_string(password, str);

        if (str == NULL) continue;
        else if (obscured == NULL)
        {
            free(str);
            continue;
        }

        fprintf(fd, "%s\n", obscured);

        free(str);
        free(obscured);
        write_count++;
    }

    fclose(fd);

// If there was no writing, that means something went wrong; return 0.
// Otherwise, if a write was completed, return 1.

    if (write_count == 0) return 0;
    else return 1;
}

struct account** account_get_from_file(const char* filename, const char* password, struct account*** result, size_t* size)
{
// Check param validity.

    if (filename == NULL || password == NULL || result == NULL)
    {
        return NULL;
    }

// Allocate vars that will be used in the reading process.

    char* line = NULL;
    size_t line_buf_len = 0;
    size_t num_accounts_loaded = 0;

    if (*result == NULL)
    {
        *size = 0;
    }

// Loop through all of the lines in the file at the given filename (if it can be opened),
// unobscuring each line and appending them to the 'result' array.

    FILE* fd = fopen(filename, "r");
    if (!fd) return NULL;

    while (getline(&line, &line_buf_len, fd) != -1)
    {
    // Unobscure the string at the current line and parse it into an account.

        size_t line_len = strlen(line);
        line[line_len - 1] = '\0';

        char* str = unobscure_string(password, line);
        struct account* a = NULL;
        account_from_str(str, &a);

        // TODO: error check the parse.

        if (str == NULL) continue;
        else if (a == NULL)
        {
            free(str);
            continue;
        }

    // Add the result to the array.

        num_accounts_loaded++;

        if (num_accounts_loaded >= *size)
        {
            *size = num_accounts_loaded;
            *result = (struct account**) realloc(*result, sizeof(struct account*) * (*size));
        }

        (*result)[num_accounts_loaded - 1] = a;

        // if (num_accounts_loaded < size)
        // {
        //     *result[num_accounts_loaded - 1] = a;
        // }
        // else
        // {

        //     *result = (struct account**) realloc(*result, sizeof(struct account*) * size);
        //     *result[size - 1] = a;
        // }

        free(str);
    }

    free(line);

    return *result;
}

bool account_write(const char* filename, const char* password, const struct account ** accounts, size_t accounts_len)
{
//  Conduct a preliminary check for obvious error conditions.

    if (filename == NULL || password == NULL || accounts == NULL)
    {
        return false;
    }

//  Open the file for writing; if we cannot, there is an error.

    FILE* fp = fopen(filename, "w");
    if (!fp) return false;

//  FOR EACH account in the parameterized list 'accounts'...

    for (size_t i = 0; i < accounts_len; i++)
    {

//      Convert the account to a string and obscure it based upon the password.

        char* str = account_to_str(accounts[i]);
        char* obscured_str = obscure_string(password, str);

//      Write to the file the obscured string.

        fprintf(fp, "%s\n", obscured_str);

//      Free any resources claimed within the loop.

        free(str);
        free(obscured_str);
    }

//  Close the file and free claimed resources.

    fclose(fp);

    return true;
}

bool account_read(const char * filename, const char * password, struct account *** accounts, size_t * accounts_len)
{
//  Conduct a preliminary check for obvious error conditions.

    if (filename == NULL || password == NULL || accounts == NULL || accounts_len == NULL)
    {
        return false;
    }

//  Open the specified file for reading. If it cannot be done,
//  there is an error.

    FILE* fp = fopen(filename, "r");
    if (!fp) return false;

//  Prepare the list for reading. If it is NULL, make sure that the size is 0.

    if (*accounts == NULL) *accounts_len = 0;

//  Declare vars that will be used by the loop.

    size_t put_index = 0;
    size_t line_size = 10;
    char* line = malloc(sizeof(char) * line_size);


//  FOR EACH line in the file...

    while (getline(&line, &line_size, fp) != -1)
    {    

//      Drop the ending newline character and unobscure based upon the
//      provided password. Parse to an account.

        line[strlen(line) - 1] = '\0';

        char* str = unobscure_string(password, line);

        if (str == NULL) continue;

        struct account* acc = NULL;
        if (!account_from_str(str, &acc))
        {
            printf("TODO: Error Check this condition.\n");
        }

        if (acc == NULL)
        {
            free(str);
            continue;
        }

//      If the new account cannot fit into the list, then make room.

        if (put_index >= *accounts_len)
        {
            *accounts_len = put_index + 1;

            struct account** temp = realloc(*accounts, sizeof(struct account*) * *accounts_len);
            if (temp == NULL)
            {
                free(str);
                free(acc);
                return false;
            }

            *accounts = temp;
        }

//      Append the new account to the list and iterate.

        (*accounts)[put_index] = acc;
        put_index++;

//      Free any resources used by the loop.

        free(str);
    }

//  Free resources used and close the file.

    fclose(fp);
    free(line);
    return true;
}