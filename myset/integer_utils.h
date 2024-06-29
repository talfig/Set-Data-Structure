/**
 * @file integer_utils.h
 * @brief Utility functions for integer manipulation.
 *
 * This header file provides utility functions for working with integers,
 * including counting the number of digits in an integer and parsing an integer
 * from a string. It defines macros for maximum and minimum integer values.
 */

#ifndef INTEGER_UTILS_H
#define INTEGER_UTILS_H

#define MAX_VALUE 127 /**< Maximum integer value in the set */
#define MIN_VALUE 0 /**< Minimum integer value in the set */

/**
 * @brief Counts the number of digits in an integer.
 *
 * This function counts the number of digits in an integer, including
 * negative numbers. It adds 1 to the number of digits for 0 or any negative integer.
 *
 * @param num The integer whose digits are to be counted.
 * @return The number of digits in the integer.
 */
int countDigits(int num);

/**
 * @brief Parses an integer from a string.
 *
 * This function parses an integer from a string. It handles negative
 * numbers and checks for invalid characters or out-of-range values.
 *
 * @param str The string containing the integer.
 * @return The parsed integer, -1 if the string represents "-1",
 *         -2 if the string is not a valid integer or is out of range.
 */
int parseInt(char *str);

#endif /* INTEGER_UTILS_H */
