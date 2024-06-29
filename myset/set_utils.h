/**
 * @file set_utils.h
 * @brief Header file for a collection of functions for set operations.
 */

#ifndef SET_UTILS_H
#define SET_UTILS_H

#include "set.h"

/**
 * @brief Enumeration representing various operations on sets.
 */
typedef enum {
    STOP,          /**< Stop the program */
    READ,          /**< Read a set */
    PRINT,         /**< Print a set */
    UNION,         /**< Union of two sets */
    INTERSECT,     /**< Intersection of two sets */
    SUB,           /**< Subtraction of two sets */
    SYMDIFF,       /**< Symmetric difference of two sets */
    NONE_OPERATION /**< No operation */
} Operation;

/**
 * @brief Fills a set with elements parsed from a string.
 *
 * @param A Pointer to the set to be filled.
 * @param str Pointer to the string to parse.
 * @param ptr Pointer to the current position in the string.
 * @param len Length of the string.
 * @note This function dynamically allocates memory for the array of elements.
 *       It is the caller's responsibility to free this memory.
 */
void fillSet(set *, char **, char *, size_t);

/**
 * @brief Parses a set name and returns a pointer to the corresponding set.
 *
 * @param set_name Name of the set to parse.
 * @param setArr Array of set pointers.
 * @return Pointer to the corresponding set, or NULL if the set name is invalid.
 */
set *parseSet(char *, set *[]);

/**
 * @brief Parses a command string and returns the corresponding operation.
 *
 * @param command String representing the command to parse.
 * @return The corresponding operation enum value.
 */
Operation parseCommand(char *);

#endif /* SET_UTILS_H */