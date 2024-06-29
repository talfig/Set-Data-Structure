/**
 * @file set.c
 * @brief A collection of functions for set operations.
 */

#include <stdio.h>
#include "set.h"

/**
 * @brief Retrieves the data array from a set.
 *
 * @param A Pointer to the set.
 * @return Pointer to the data array of the set.
 */
unsigned char *getData(set *A) {
    return A->data;
}

/**
 * @brief Empties a set by setting all its data elements to 0.
 *
 * @param A Pointer to the set to be emptied.
 * @note This function modifies the set in place.
 */
void emptySet(set *A) {
    int i;

    /* Iterate over the data array and set each element to 0 */
    for(i = 0; i < DATA_SIZE; i++)
        getData(A)[i] = 0;
}

/**
 * @brief Empties an array of sets by setting all their data elements to 0.
 *
 * @param setArr Array of set pointers to be emptied.
 * @param len Length of the set array.
 * @note This function modifies each set in the array in place.
 */

void emptySetArray(set *setArr[], int len) {
    int i;

    /* Iterate over each set in the array and empty it */
    for(i = 0; i < len; i++)
        emptySet(setArr[i]);
}

/**
 * @brief Adds a number to a set.
 *
 * @param A Pointer to the set.
 * @param num Number to be added to the set.
 */
void addToSet(set *A, unsigned char num) {
    int i = num / BYTE_SIZE;
    /* Set the bit corresponding to num */
    getData(A)[i] |= 1 << (num - BYTE_SIZE * i);
}

/**
 * @brief Checks if a number is in a set.
 *
 * @param A Pointer to the set.
 * @param num Number to check for membership in the set.
 * @return 1 if the number is in the set, 0 otherwise.
 */
int isInSet(set *A, unsigned char num) {
    int i = num / BYTE_SIZE;
    /* Check if the bit corresponding to num is set */
    return (getData(A)[i] >> (num - BYTE_SIZE * i)) & 1;
}

/**
 * @brief Reads an array of numbers into a set.
 *
 * @param A Pointer to the set.
 * @param arr Array of numbers to be read into the set.
 * @param len Length of the array.
 * @note This function empties the set before adding new numbers.
 */
void read_set(set *A, unsigned char *arr, int len) {
    int i;
    /* Empty the set before adding new numbers */
    emptySet(A);

    /* Iterate over the array and add each number to the set */
    for(i = 0; i < len; i++)
        addToSet(A, arr[i]);

}

/**
 * @brief Prints the contents of a set.
 *
 * @param A Pointer to the set.
 * @note This function prints the set in a specified format.
 */
void print_set(set *A) {
    int i, count = 0, newRow = 1;

    /* Iterate over all possible numbers in the set */
    for(i = 0; i < SET_SIZE; i++) {
        /* Check if the number is in the set */
        if(isInSet(A, i)) {
            /* If this is the first number found, print the header */
            if(!count) printf("The set is:\n");
            count++;

            /* handle formatting for new row and commas */
            if(newRow)
                /* Print the first number in the new row */
                printf("%d", i);
            else {
                /* Print subsequent numbers with a preceding comma */
                printf(", %d", i);

                /* Check if the current row has reached the maximum size */
                if(!(count % ROW_SIZE)) {
                    /* Move to the next line */
                    printf("\n");
                    /* Mark the start of a new row */
                    newRow = 1;
                    continue;
                }
            }
            /* Reset the newRow flag as we've printed a number */
            newRow = 0;
        }
    }
    /* If no numbers were found in the set, indicate that the set is empty */
    if(!count)
        printf("The set is empty\n");
    /* Ensure the last line of numbers ends correctly */
    else if(!newRow)
        printf("\n");
}

/**
 * @brief Computes the union of two sets and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the union result.
 * @note This function modifies the result set in place.
 */
void union_set(set *A, set *B, set *C) {
    int i;
    /* Empty the result set before computing the union */
    emptySet(C);

    /* Iterate over all possible numbers and add them to the result set if they are in either A or B */
    for(i = 0; i < SET_SIZE; i++)
        if(isInSet(A, i) || isInSet(B, i))
            addToSet(C, i);
}

/**
 * @brief Computes the intersection of two sets and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the intersection result.
 * @note This function modifies the result set in place.
 */
void intersect_set(set *A, set *B, set *C) {
    int i;
    /* Empty the result set before computing the intersection */
    emptySet(C);

    /* Iterate over all possible numbers and add them to the result set if they are in both A and B */
    for(i = 0; i < SET_SIZE; i++)
        if(isInSet(A, i) && isInSet(B, i))
            addToSet(C, i);
}

/**
 * @brief Computes the difference of two sets (A \ B) and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the difference result.
 * @note This function modifies the result set in place.
 */
void sub_set(set *A, set *B, set *C) {
    int i;
    /* Empty the result set before computing the difference */
    emptySet(C);

    /* Iterate over all possible numbers and add them to the result set if they are in A but not in B */
    for(i = 0; i < SET_SIZE; i++)
        if(isInSet(A, i) && !isInSet(B, i))
            addToSet(C, i);
}

/**
 * @brief Computes the symmetric difference of two sets and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the symmetric difference result.
 * @note This function modifies the result set in place.
 */
void symdiff_set(set *A, set *B, set *C) {
    int i;
    /* Empty the result set before computing the symmetric difference */
    emptySet(C);

    /* Iterate over all possible numbers and add them to the result set if they are in either A or B but not both */
    for(i = 0; i < SET_SIZE; i++)
        if(isInSet(A, i) ^ isInSet(B, i))
            addToSet(C, i);
}