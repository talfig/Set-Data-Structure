/**
 * @file myset.c
 * @brief Main file for the simulation program.
 *
 * This program simulates various set operations based on user commands.
 * Users can interact with the program through a command-line interface,
 * performing actions such as reading sets, performing union operations,
 * and more. The program prompts the user for commands and executes them accordingly.
 */

#include "program.h"

/**
 * @brief The main function of the simulation program.
 *
 * The simulation allows users to perform various commands on sets,
 * such as reading a set, performing union operations, and more.
 * It prompts the user for commands and executes them accordingly.
 *
 * @return 0 on successful execution.
 */
int main() {
    set SETA, SETB, SETC, SETD, SETE, SETF;

    /* Initializing sets and booting the simulation */
    boot_program(&SETA, &SETB, &SETC, &SETD, &SETE, &SETF);

    return 0;
}