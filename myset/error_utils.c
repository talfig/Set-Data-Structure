/**
 * @file error_utils.c
 * @brief Utility functions for error handling.
 *
 * This file contains utility functions for error handling in set operations.
 */

#include <stdio.h>
#include <string.h>
#include "integer_utils.h"
#include "set_utils.h"
#include "string_utils.h"

/**
 * @brief Checks if the given string represents a readable set of integers.
 *
 * @param str Pointer to the string to be parsed.
 * @param ptr Temporary pointer used for parsing.
 * @return 1 if the set is readable and correctly formatted, 0 otherwise.
 */
int isReadableSet(char **str, char *ptr) {
    int num, foundErr = 0;

    /* Check for the first token in the string */
    if(nextToken(str, ptr)) return 0;

    /* Iterate through each token */
    while(*ptr) {
        num = parseInt(ptr);

        /* Check if the token is a valid integer */
        if(num == -2) {
            foundErr = 1;
            break;
        }

        /* Validate the length of the integer */
        else if(strlen(ptr) != countDigits(num)) {
            printf("Invalid set member - not an integer\n");
            foundErr = 1;
            break;
        }

        /* Check for the end of the list */
        else if(num == -1) break;

        /* Move to the next token */
        else if(nextToken(str, ptr)) return 0;

    }

    /* Final validation of the set format */
    if(!foundErr) {
        if(num != -1) printf("List of set members is not terminated correctly\n");
        else if(**str) printf("Extraneous text after end of command\n");
        else return 1;
    }

    return 0;
}

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
int prompt_err(Operation opr, char *ptrArr[], set *A, set *B, set *C) {
    int foundErr = 1;

    switch(opr) {
        case READ:
            /* Checks whether the user entered the name of the set and elements to read into the set */
            if(!(*ptrArr[1]) || !(*ptrArr[2])) printf("Missing parameter\n");
            else if(!A) printf("Undefined set name\n");
            else foundErr = 0;
            break;

        case PRINT:
            /* Checks whether the user entered the name of the set */
            if(!(*ptrArr[1])) printf("Missing parameter\n");
            else if(!A) printf("Undefined set name\n");
            else if(*ptrArr[2]) printf("Extraneous text after end of command\n");
            else foundErr = 0;
            break;

        default:
            /* Checks whether the user entered the names of the sets */
            if(!(*ptrArr[1]) || !(*ptrArr[2]) || !(*ptrArr[3])) printf("Missing parameter\n");
            else if(!A || !B || !C) printf("Undefined set name\n");
            else if(*ptrArr[4]) printf("Extraneous text after end of command\n");
            else foundErr = 0;

    }

    return foundErr;
}