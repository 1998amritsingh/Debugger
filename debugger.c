// Author: Amrit Singh (2020)
// 
// Debugger implementation
//
// Examples usage:
//      ./debugger <lang> <filename> <line number start> <line number end> <debug message>
//                                   OR
//      ./debugger <lang> <filename> <line numbers> <debug message>
// Where <line numbers> is a comma separated string of line numbers.
//
// Note that line numbers provided as args are inclusive. See debugger.h for
// more details and example usage.

#include "debugger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void debugger_common(char* programming_language,
                     char* filename,
                     int line_numbers[],
                     int line_num_start,
                     int line_num_end,
                     char* debug_string) {
    return;
}

int debugger(int argc, char **argv) {
    if (argc < 5) {
        printf("Incorrect usage. See README.md for more details.\n");
        return -1;
    }

    char* programming_language = strdup(argv[1]);
    char* filename = strdup(argv[2]);
    
    if (argc == 5) {
        // User has specified line numbers, parse the input and convert it to
        // an integer array.
        int line_arr_size = 1;

        // Create a temporary variable to iterate and count the number of line
        // numbers provided.
        char* temp_line_nums = strdup(argv[3]);
        while (*temp_line_nums != '\0') {
            if (*temp_line_nums == ',') {
                line_arr_size++;
            }
        }

        // Initialize an integer array to store the line numbers.
        int line_numbers[line_arr_size];

        // Insert the line numbers into the array as integers.
        int line_num_idx = 0;
        const char delimeter[2] = ",";
        char* token;

        // Get the first entry.
        token = strtok(argv[3], delimeter);

        // Walk through other entries and insert them into the array.
        while (token != NULL) {
            line_numbers[line_num_idx] = atoi(token);
            line_num_idx++;
            token = strtok(NULL, delimeter);
        }

        char* debug_string = strdup(argv[4]);
        debugger_common(programming_language,
                        filename,
                        line_numbers,
                        -1  /* line_num_start */,
                        -1  /* line_num_end */,
                        debug_string);

        // Free allocated memory.
        free(programming_language);
        free(filename);
        free(temp_line_nums);
        free(debug_string);
        programming_language = NULL;
        filename = NULL;
        temp_line_nums = NULL;
        debug_string = NULL;
        return 0;
    }

    // User has specified a range of line numbers as input.
    int line_num_start = atoi(argv[3]);
    int line_num_end = atoi(argv[4]);
    char* debug_string = strdup(argv[5]);
    debugger_common(programming_language,
                    filename,
                    NULL  /* line_numbers */,
                    line_num_start,
                    line_num_end,
                    debug_string);

    // Free allocated memory.
    free(programming_language);
    free(filename);
    free(debug_string);
    programming_language = NULL;
    filename = NULL;
    debug_string = NULL;
    return 0;
}
