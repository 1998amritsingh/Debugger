// Author: Amrit Singh (2020)
// 
// Main method for debugger that calls implementation
// based on language
// 
// As of now, only C is supported. Plans to support other languages
// in the future

#include "debugger.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    debugger(argc, argv);
    return 0;
}
