/**
 * @file error_utils.h
 * @brief Utility functions for error handling.
 *
 * The header file contains function prototypes for error handling in set operations.
 */

#ifndef ERROR_UTILS_H
#define ERROR_UTILS_H

#include "set_utils.h"

/**
 * @brief Checks if the given string represents a readable set of integers.
 *
 * @param str Pointer to the string to be parsed.
 * @param ptr Temporary pointer used for parsing.
 * @return 1 if the set is readable and correctly formatted, 0 otherwise.
 */
int isReadableSet(char **str, char *ptr);

/**
 * @brief Validates the parameters and sets for a given operation.
 *
 * @param opr The operation to be performed.
 * @param ptrArr Array of pointers to parameter strings.
 * @param A Pointer to the first set.
 * @param B Pointer to the second set (if applicable).
 * @param C Pointer to the third set (if applicable).
 * @return 1 if there is an error, 0 otherwise.
 */
int prompt_err(Operation opr, char *ptrArr[], set *A, set *B, set *C);

#endif /* ERROR_UTILS_H */
