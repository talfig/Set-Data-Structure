/**
 * @file set.h
 * @brief Definitions and functions for set operations.
 */

#ifndef SET_H
#define SET_H

#define SET_SIZE 128 /**< Define the maximum size of the set */
#define ROW_SIZE 16  /**< Define the number of elements per row for printing */
#define DATA_SIZE 16 /**< Define the size of the data array in bytes */
#define BYTE_SIZE 8  /**< Define the size of a byte in bits */
#define SET_COUNT 6  /**< Define the number of sets */

/**
 * @brief Structure representing a set.
 *
 * The set is represented using an array of unsigned char, each bit representing an element.
 */
typedef struct {
    unsigned char data[DATA_SIZE]; /**< Array to hold set data */
} set;

/**
 * @brief Retrieves the data array from a set.
 *
 * @param A Pointer to the set.
 * @return Pointer to the data array of the set.
 */
unsigned char *getData(set *A);

/**
  * @brief Empties a set by setting all its data elements to 0.
 *
 * @param A Pointer to the set to be emptied.
 * @note This function modifies the set in place.
 */
void emptySet(set *A);

/**
 * @brief Empties an array of sets by setting all their data elements to 0.
 *
 * @param setArr Array of set pointers to be emptied.
 * @param len Length of the set array.
 * @note This function modifies each set in the array in place.
 */
void emptySetArray(set *setArr[], int len);

/**
 * @brief Adds a number to a set.
 *
 * @param A Pointer to the set.
 * @param num Number to be added to the set.
 */
void addToSet(set *A, unsigned char num);

/**
 * @brief Checks if a number is in a set.
 *
 * @param A Pointer to the set.
 * @param num Number to check for membership in the set.
 * @return 1 if the number is in the set, 0 otherwise.
 */
int isInSet(set *A, unsigned char num);

/**
 * @brief Reads an array of numbers into a set.
 *
 * @param A Pointer to the set.
 * @param arr Array of numbers to be read into the set.
 * @param len Length of the array.
 * @note This function empties the set before adding new numbers.
 */
void read_set(set *A, unsigned char *arr, int len);

/**
 * @brief Prints the contents of a set.
 *
 * @param A Pointer to the set.
 * @note This function prints the set in a specified format.
 */
void print_set(set *A);

/**
 * @brief Computes the union of two sets and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the union result.
 * @note This function modifies the result set in place.
 */
void union_set(set *A, set *B, set *C);

/**
 * @brief Computes the intersection of two sets and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the intersection result.
 * @note This function modifies the result set in place.
 */
void intersect_set(set *A, set *B, set *C);

/**
 * @brief Computes the difference of two sets (A \ B) and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the difference result.
 * @note This function modifies the result set in place.
 */
void sub_set(set *A, set *B, set *C);

/**
 * @brief Computes the symmetric difference of two sets and stores the result in a third set.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the set to store the symmetric difference result.
 * @note This function modifies the result set in place.
 */
void symdiff_set(set *A, set *B, set *C);

#endif /* SET_H */
