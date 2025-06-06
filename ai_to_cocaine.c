#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096 // Round about 40kb should do
#define TARGET_STRING "AI"
#define REPLACEMENT_STRING "cocaine"
#define OUTPUT_FILE "the_cocaine_file.txt

int main(void) {
    char buffer[BUFFER_SIZE];
    char* replaced_text;
    FILE* output_file;

    output_file = fopen(OUTPUT_FILE, "w");
    if (output_file == NULL) {
        fprintf(stderr, "FAILED SUCCESSFULLY: Could not create output!\n");
        return 69;
    }
}