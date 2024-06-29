/**
 * @file string_utils.h
 * @brief Header file for a collection of utility functions for string manipulation.
 */

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdlib.h>

/**
 * @brief Reads a line of input from stdin.
 *
 * @param prompt The prompt to display to the user.
 * @return A dynamically allocated string containing the input line.
 * @note It is the caller's responsibility to free this memory.
 */
char *read_line(char *);

/**
 * @brief Extracts the first token from a string.
 *
 * @param str The input string.
 * @param dest The destination buffer to store the token.
 * @return 0 if successful, 1 if error occurred.
 */
int firstToken(char **, char *);

/**
 * @brief Extracts the next token from a string.
 *
 * @param str The input string.
 * @param dest The destination buffer to store the token.
 * @return 0 if successful, 1 if error occurred.
 */
int nextToken(char **, char *);

/**
 * @brief Allocates memory for an array of strings.
 *
 * @param ptrArr The array of string pointers.
 * @param len The length of the array.
 * @param allocSize The size to allocate for each string.
 * @note This function dynamically allocates memory for each string in ptrArr.
 *       It is the caller's responsibility to free this memory.
 */
void allocPtrArray(char *[], int, size_t);

/**
 * @brief Frees memory allocated for an array of strings.
 *
 * @param ptrArr The array of string pointers.
 * @param len The length of the array.
 * @note This function frees memory allocated for each string in ptrArr.
 */
void freePtrArray(char *[], int);

#endif /* STRING_UTILS_H */
