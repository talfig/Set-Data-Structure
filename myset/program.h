/**
 * @file program.h
 * @brief Header file for the program to perform various set operations based on user commands.
 *
 * This header file declares the function `boot_program`, which initializes the sets
 * and starts the program loop to process commands.
 */

#ifndef PROGRAM_H
#define PROGRAM_H

#include "set.h"

/**
 * @brief Initializes the sets and starts the program loop to process commands.
 *
 * @param A Pointer to the first set.
 * @param B Pointer to the second set.
 * @param C Pointer to the third set.
 * @param D Pointer to the fourth set.
 * @param E Pointer to the fifth set.
 * @param F Pointer to the sixth set.
 */
void boot_program(set *, set *, set *, set *, set *, set *);

#endif /* PROGRAM_H */