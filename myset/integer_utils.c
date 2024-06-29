/**
 * @file integer_utils.c
 * @brief A collection of utility functions for integer manipulation.
 */

#include <stdio.h>
#include "integer_utils.h"

/**
 * @brief Counts the number of digits in an integer.
 *
 * This function counts the number of digits in an integer, including
 * negative numbers. It adds 1 to the number of digits for 0 or any negative integer.
 *
 * @param num The integer whose digits are to be counted.
 * @return The number of digits in the integer.
 */
int countDigits(int num) {
    int count = 0;

    /* If the number is negative or zero, it adds one digit */
    if(num <= 0) count++;

    /* Counting digits by continuously dividing by 10 until num is equal to 0 */
    while(num) {
        num /= 10;
        count++;
    }
    return count;
}

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
int parseInt(char *str) {
    int result = 0;

    /* Handling negative numbers */
    if(*str == '-') {
        /* Checking if it's "-1" */
        if(*(str + 1) == '1') return -1;
        else if(*(str + 1) < '0' || *(str + 1) > '9')
            printf("Invalid set member - not an integer\n");
        else printf("Invalid set member - value out of range\n");

        /* Indicates an error */
        return -2;
    }

    /* Parsing positive numbers */
    while(*str) {
        /* Checking if each character is a digit */
        if(*str < '0' || *str > '9') {
            printf("Invalid set member - not an integer\n");
            return -2;
        }

        /* Converting character to integer and accumulating result */
        result = result * 10 + (*str - '0');

        /* Checking if result is within the acceptable range */
        if(result < MIN_VALUE || result > MAX_VALUE) {
            printf("Invalid set member - value out of range\n");
            return -2;
        }
        str++;
    }

    /* Return the parsed integer */
    return result;
}