/**
 * @file set_utils.c
 * @brief A collection of functions for set operations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "integer_utils.h"
#include "string_utils.h"
#include "error_utils.h"

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
void fillSet(set *A, char **str, char *ptr, size_t len) {
    unsigned char *arr;
    char *tmp = *str;
    int num, i = 0;

    /* Check if the string is readable as a set */
    if(!isReadableSet(str, ptr))
        return;
    *str = tmp;

    /* Allocate memory for the array of elements */
    arr = (unsigned char *)malloc(len * sizeof(unsigned char));
    if(!arr){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Parse integers from the string and store them in the array */
    nextToken(str, ptr);
    while(*ptr != '-') {
        num = parseInt(ptr);
        arr[i] = (unsigned char)num;
        nextToken(str, ptr);
        i++;
    }

    /* Read the array of elements into the set */
    read_set(A, arr, i);
    /* free the memory */
    free(arr);
}

/**
 * @brief Parses a set name and returns a pointer to the corresponding set.
 *
 * @param set_name Name of the set to parse.
 * @param setArr Array of set pointers.
 * @return Pointer to the corresponding set, or NULL if the set name is invalid.
 */
set *parseSet(char *set_name, set *setArr[]) {
    if(!strcmp(set_name, "SETA")) return setArr[0];
    else if(!strcmp(set_name, "SETB")) return setArr[1];
    else if(!strcmp(set_name, "SETC")) return setArr[2];
    else if(!strcmp(set_name, "SETD")) return setArr[3];
    else if(!strcmp(set_name, "SETE")) return setArr[4];
    else if(!strcmp(set_name, "SETF")) return setArr[5];
    return NULL;
}

/**
 * @brief Parses a command string and returns the corresponding operation.
 *
 * @param command String representing the command to parse.
 * @return The corresponding operation enum value.
 */
 Operation parseCommand(char *command) {
    if(!strcmp(command, "stop")) return STOP;
    else if(!strcmp(command, "read_set")) return READ;
    else if(!strcmp(command, "print_set")) return PRINT;
    else if(!strcmp(command, "union_set")) return UNION;
    else if(!strcmp(command, "intersect_set")) return INTERSECT;
    else if(!strcmp(command, "sub_set")) return SUB;
    else if(!strcmp(command, "symdiff_set")) return SYMDIFF;
    printf("Undefined command name\n");
    return NONE_OPERATION;
}
