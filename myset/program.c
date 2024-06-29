/**
 * @file program.c
 * @brief Program to perform various set operations based on user commands.
 *
 * This program allows the user to perform operations such as reading, printing,
 * union, intersection, subtraction, and symmetric difference on sets. The user
 * inputs commands, and the program parses and executes these commands accordingly.
 * The program continues to run until the STOP command is received.
 *
 * @note The sets are represented using an array of unsigned chars where each bit corresponds
 * to an element in the set.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set_utils.h"
#include "error_utils.h"
#include "string_utils.h"

/**
 * @brief Parses the input command and executes the corresponding set operation.
 *
 * @param setArr Array of set pointers that represent the available sets.
 * @return Returns 1 if the STOP command is received, otherwise returns 0.
 * @note This function handles memory allocation and deallocation for command parsing.
 */
int parseInput(set *setArr[]) {
    char *ptrArr[5], *command, *str, *ptr;
    set *S1, *S2, *S3;

    /* Prompt the user to enter a command */
    command = read_line("Please enter a command:\n");
    if(!command) return 1;
    printf("Command received:\n%s\n", command);

    /* Allocate memory for the command tokens */
    allocPtrArray(ptrArr, 5, strlen(command) + 1);
    ptr = command;

    /* Extract the first and second tokens (operation and set name) */
    if(firstToken(&ptr, ptrArr[0]) || nextToken(&ptr, ptrArr[1])) {
        freePtrArray(ptrArr, 5);
        free(command);
        return 0;
    }
    str = ptr;

    /* Extract the remaining tokens (can be sets names, 'numbers' or NULL) */
    if(nextToken(&ptr, ptrArr[2]) || nextToken(&ptr, ptrArr[3]) || nextToken(&ptr, ptrArr[4])) {
        freePtrArray(ptrArr, 5);
        free(command);
        return 0;
    }

    /* Parse the sets from the tokens.
     * if a set does not exist, then it parsed as NULL */
    S1 = parseSet(ptrArr[1], setArr);
    S2 = parseSet(ptrArr[2], setArr);
    S3 = parseSet(ptrArr[3], setArr);

    /* Execute the command based on the parsed tokens */
    switch(parseCommand(ptrArr[0])) {
        case STOP:
            /* Free the memory */
            freePtrArray(ptrArr, 5);
            free(command);
            return 1;

        case READ:
            if(!prompt_err(READ, ptrArr, S1, S2, S3))
                /* ptrArr[0] is used as a temporary buffer */
                fillSet(S1, &str, ptrArr[0], strlen(command));
            break;

        case PRINT:
            if(!prompt_err(PRINT, ptrArr, S1, S2, S3))
                print_set(S1);
            break;

        case UNION:
            if(!prompt_err(UNION, ptrArr, S1, S2, S3))
                union_set(S1, S2, S3);
            break;

        case INTERSECT:
            if(!prompt_err(INTERSECT, ptrArr, S1, S2, S3))
                intersect_set(S1, S2, S3);
            break;

        case SUB:
            if(!prompt_err(SUB, ptrArr, S1, S2, S3))
                sub_set(S1, S2, S3);
            break;

        case SYMDIFF:
            if(!prompt_err(SYMDIFF, ptrArr, S1, S2, S3))
                symdiff_set(S1, S2, S3);
            break;

        default:
            break;
    }

    /* Free the memory */
    freePtrArray(ptrArr, 5);
    free(command);
    return 0;
}

/**
 * @brief Initializes the sets and starts the program loop to process commands.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the third set.
 * @param D Pointer to the fourth set.
 * @param E Pointer to the fifth set.
 * @param F Pointer to the sixth set.
 * @note This function runs an infinite loop until the STOP command is received.
 */
void boot_program(set *A, set *B, set *C, set *D, set *E, set *F) {
    /* Initialize the set array with the provided set pointers */
    set *setArr[SET_COUNT];
    setArr[0] = A;
    setArr[1] = B;
    setArr[2] = C;
    setArr[3] = D;
    setArr[4] = E;
    setArr[5] = F;

    /* Clear all sets in the array */
    emptySetArray(setArr, SET_COUNT);

    /* Continue parsing input until the STOP command is received */
    while(!parseInput(setArr));
}