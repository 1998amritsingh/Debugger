// Author: Amrit Singh (2020)
// 
// Main method for debugger that calls implementation
// based on language
//
// Examples usage:
//      ./debugger <lang> <line number start> <line number end> <debug message>
// Note that line numbers provided as args are inclusive.

#include "c_debugger.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Incorrect usage. Valid inputs must follow the format: "
               "./debugger <lang> <line number start> <line number end> "
               "<debug_message>. Note that line numbers provided as arguments "
               "are inclusive.\n");
        return -1;
    }

    char* programming_language = argv[1];
    if (strcmp(programming_language, "C") == 0) {
        c_debugger(argc, argv);
    } else {
        printf("Unsupported programming language");
    }
    return 0;
}
