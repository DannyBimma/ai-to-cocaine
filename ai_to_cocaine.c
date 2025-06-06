#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096 // Round about 40kb should do
#define TARGET_STRING "AI"
#define REPLACEMENT_STRING "cocaine"
#define OUTPUT_FILE "the_cocaine_file.txt

// Prototypes
char* ai_cocainizer(const char* input, const char* search_term, const char* replace_term);

int main(void) {
    char buffer[BUFFER_SIZE];
    char* replaced_text;
    FILE* output_file;

    output_file = fopen(OUTPUT_FILE, "w");
    if (output_file == NULL) {
        fprintf(stderr, "FAILED SUCCESSFULLY: Could not create output!\n");
        return 69;
    }

    // Read stdin input
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        /* Replace occurrences in the current line */
        replaced_text = ai_cocainizer(buffer, TARGET_STRING, REPLACEMENT_STRING);

        if (replaced_text == NULL) {
            fclose(output_file);
            return 1;
        }
}

// Find and replace func
char* ai_cocainizer(const char* input, const char* search_term, const char* replace_term) {
    char* result;
    char* temp;
    char* pos;
    int search_len = strlen(search_term);
    int replace_len = strlen(replace_term);
    int count = 0;
    int result_len;
    int i, j;

    // First pass: calc mem needed
    temp = (char*)input;
    while ((pos = strstr(temp, search_term)) != NULL) {
        count++;
        temp = pos + search_len;
    }

    result_len = strlen(input) + count * (replace_len - search_len);

    result = (char*)malloc(result_len + 1);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Second pass: turn the AI into cocaine
    i = 0;  // Input
    j = 0;  // Output

    while (input[i] != '\0') {
        if (strncmp(&input[i], search_term, search_len) == 0) {
            strcpy(&result[j], replace_term);
            j += replace_len;
            i += search_len;  // Skip search term in input
        } else {
            result[j] = input[i];
            i++;
            j++;
        }
    }

    result[j] = '\0';  // Be safe
    return result;
}