/*
    Made by Mac as a quick and easy way to get answers from the users via a CLI
    Includes things such as (Yes/No), Integer Input, String Input etc.
    C.L.I.P. - Command Line Interface Prompt
*/

#ifndef COMMAND_LINE_INPUT_PROMPTS
#define COMMAND_LINE_INPUT_PROMPTS

#include<string>

/**
 * Command Line Interface Prompts
 */
namespace clip {

const std::string DEFAULT_PROMPT_SUFFIX = "DEFAULT_PROMPT:";

// BOOLEAN - Yes / No

/**
 * Asks a Yes / No Question with a given prompt, yes if true, no if false
 * Checks for "Yes", "No", "Y", "N" and is not case sensitive
 * Forces the User to give a Yes / No answer
 */
bool get_boolean(std::string prompt);
/**
 * Asks a Yes / No Question with a given prompt, yes if true, no if false
 * Checks for "Yes", "No", "Y", "N" and is not case sensitive
 * Throws an error if an invalid response is given.
 */
bool get_boolean_error(std::string prompt);
/**
 * Asks a Yes / No Question with a given prompt, yes if true, no if false
 * Checks for "Yes", "No", "Y", "N" and is not case sensitive
 * If an invalid answer is given a default response is used (and is reported to the User)
 */
bool get_boolean_default(std::string prompt, bool default_val);

// DOUBLE

/**
 * Gets a double value from the user
 * Forces the User to give a Double value
 */
double get_double(std::string prompt);

/**
 * Gets a double value from the user
 * Throws an error if user doesn't enter a double
 */
double get_double_error(std::string prompt);

/**
 * Gets a double value from the user
 * Returns a default value if the user does not enter a double
 */
double get_double_default(std::string prompt, double default_val);

// INT

/**
 * Gets an integer from the user
 * Forces the user to give an integer
 */
int get_int(std::string prompt);

/**
 * Gets an integer from the user
 * Errors if the user does not enter an integer
 */
int get_int_error(std::string prompt);

/**
 * Gets an integer from the user
 * Returns a default value if the user does not enter an integer
 */
int get_int_default(std::string prompt, int default_val);


// STRING

/**
 * Gets a string from the user
 * Can get and return empty strings
 */
std::string get_string_raw(std::string prompt);

/**
 * Gets a string from the user
 * Forces them to give a non empty answer.
 */
std::string get_string(std::string prompt);

/**
 * Gets a string from the user
 * If they enter a blank stirng an error is thrown
 */
std::string get_string_error(std::string prompt);

/**
 * Gets a string from the user
 * If they enter a blank string a default value is used instead
 */
std::string get_string_default(std::string prompt, std::string default_val);

}

#endif