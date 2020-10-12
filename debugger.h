// Author: Amrit Singh (2020)

// Common debugger implementation to perform basic file manipulation. Language
// specific methods are called inside this function. The method functions by
// reading the contents of <filename>, writing the contents of the
// filename to a temp file with the specified user prints, copying the 
// contents of the temp file back to the original filename to preserve any
// filesystem metadata associated with the original file, and finally removing
// the temp file.
//
// Params:
//
// programming_language: String-specified value for the programming language
//                       used on the file of interest.
// filename: The filename the user wishes to run the debugger implementation
//           on.
// line_numbers: Specific line numbers provided by the user in which the user
//               wishes to insert the debug statements. Note that for each
//               provided value, a debug statement will be inserted BEFORE that
//               line number. If the value of this field is nullptr, it
//               indicates that the user has specified a range of line numbers
//               instead (See example below for more details).
// line_num_start: (inclusive) starting line number on which the debug
//                 statements will begin to be placed before. If the value of
//                 this field is -1, it indicates that the user has specified a
//                 list of line numbers instead
//                 (See example below for more details).
// line_num_end: (inclusive) ending line number on which the debug statements
//               will begin to be placed before. If the value of this field is
//               -1, it indicates that the user has specified a list of numbers
//               instead (See example below for more details).
// debug_string: The debug string the user wishes to input as a trace.
//               TODO(Amrit): Allow for program variables to be printed within
//               the scope of the provided line numbers. 
// 
// Example: 
//
// 1 int main(int argc, char** argv) {
// 2    char* test_string = ...
// 3    printf(%s, test_string);
// 4    return 0;
// 5 }
//
// Case 1: User specifies 2 as line_num_start and 4 as line_num_end and "DEBUG"
//         as the debug string.
// New Program:
// 1 int main(int argc, char** argv) {
// 2    printf(%s, "DEBUG");
// 3    char* test_string = ...
// 4    printf(%s, "DEBUG");
// 5    printf(%s, test_string);
// 6    printf(%s, "DEBUG");
// 7    return 0;
// 8 }
//
// Case 2: User specifies 2 as line_numbers and "DEBUG" as the debug string.
// New Program:
// 1 int main(int argc, char** argv) {
// 2    printf(%s, "DEBUG");
// 3    char* test_string = ...
// 4    printf(%s, test_string);
// 5    return 0;
// 6 }
void debugger_common(char* programming_language,
                     char* filename,
                     int line_numbers[],
                     int line_num_start,
                     int line_num_end,
                     char* debug_string);

// Main method for the debugger.
int debugger(int argc, char** argv);
