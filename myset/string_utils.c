/**
 * @file string_utils.c
 * @brief A collection of utility functions for string manipulation.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Reads a line of input from stdin.
 *
 * @param prompt The prompt to display to the user.
 * @return A dynamically allocated string containing the input line.
 * @note It is the caller's responsibility to free this memory.
 */
char *read_line(char *prompt) {
    int size = 2, i = 0;
    /* Allocate initial memory */
    char c, *str = (char *)malloc(size), *tmp;

    /* Check if memory allocation was successful */
    if(!str){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    /* Display the prompt to the user */
    printf("%s", prompt);

    /* Read characters until EOF or newline */
    while((c = (char)getchar()) != EOF && c != '\n') {
        if(i == size - 1) {
            size *= 2;
            tmp = (char *)realloc(str, size);
            /* Check if memory reallocation was successful */
            if(!tmp) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(str);
                exit(EXIT_FAILURE);
            }
            str = tmp;
        }
        /* Store the character */
        str[i++] = c;
    }

    /* Handle EOF condition */
    if(c == EOF && i == 0) {
        printf("End of file reached\n");
        free(str);
        return NULL;
    }

    /* Null-terminate the string */
    str[i] = '\0';
    return str;
}

/**
 * @brief Extracts the first token from a string.
 *
 * @param str The input string.
 * @param dest The destination buffer to store the token.
 * @return 0 if successful, 1 if error occurred.
 */
int firstToken(char **str, char *dest) {
    int i = 0;

    /* Skip leading spaces */
    for(; **str && (**str == ' ' || **str == '\t'); *str += 1);
    /* Check for empty string */
    if(!(**str)) {
        printf("Non-content input\n");
        return 1;
    }

    /* Extract token */
    while(**str && **str != ' ' && **str != '\t' && **str != ',') {
        dest[i++] = **str;
        *str += 1;
    }
    /* Null-terminate the token */
    dest[i] = '\0';

    /* Skip trailing spaces */
    for(; **str && (**str == ' ' || **str == '\t'); *str += 1);
    /* Check for illegal comma */
    if(**str == ',') {
        printf("Illegal comma\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Extracts the next token from a string.
 *
 * @param str The input string.
 * @param dest The destination buffer to store the token.
 * @return 0 if successful, 1 if error occurred.
 */
int nextToken(char **str, char *dest) {
    int i = 0;
    int cntCommas = 0;

    /* Extract token */
    while(**str && **str != ' ' && **str != '\t' && **str != ',') {
        dest[i++] = **str;
        *str += 1;
    }
    /* Null-terminate the token */
    dest[i] = '\0';

    /* Skip spaces and commas */
    for(; **str && (**str == ' ' || **str == '\t' || **str == ','); *str += 1)
        /* Count commas */
        if(**str == ',') cntCommas++;
    /* Check for end of string */
    if(!(**str)) {
        /* Handle extraneous text */
        if(cntCommas > 0) {
            printf("Extraneous text after end of command\n");
            return 1;
        }
        return 0;
    }
    /* Handle different comma cases */
    switch(cntCommas) {
        case 0:
            printf("Missing comma\n");
            return 1;
        case 1: return 0;
        default:
            printf("Multiple consecutive commas\n");
            return 1;
    }
}

/**
 * @brief Allocates memory for an array of strings.
 *
 * @param ptrArr The array of string pointers.
 * @param len The length of the array.
 * @param allocSize The size to allocate for each string.
 * @note This function dynamically allocates memory for each string in ptrArr.
 *       It is the caller's responsibility to free this memory.
 */
void allocPtrArray(char *ptrArr[], int len, size_t allocSize) {
    int i;


    for(i = 0; i < len; i++) {
        /* Allocate memory for each string */
        ptrArr[i] = (char *)malloc(allocSize);
        /* Check if memory allocation was successful */
        if(!ptrArr[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            /* Free already allocated memory */
            while(i > 0) free(ptrArr[--i]);
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * @brief Frees memory allocated for an array of strings.
 *
 * @param ptrArr The array of string pointers.
 * @param len The length of the array.
 * @note This function frees memory allocated for each string in ptrArr.
 */
void freePtrArray(char *ptrArr[], int len) {
    int i;

    /* Free each string */
    for(i = 0; i < len; i++)
        free(ptrArr[i]);
}