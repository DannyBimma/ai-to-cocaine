# AI to Cocaine Text Processor

A simple and efficient C program that reads text from standard input, replaces all occurrences of "AI" with "cocaine", and saves the result to a text file.

## Features

- **Memory efficient**: Processes text line-by-line instead of loading entire file into memory
- **No memory leaks**: Proper memory management with malloc/free (I think)
- **C90/C89 compliant**: White Book C friendly
- **Error handling**: Graceful handling of memory allocation and file operation failures
- **Cross-platform**: Works on my machine and hopefully yours as well

## Requirements

- C compiler (CC, GCC, Clang, or Microsoft Visual C++)
- Standard C library

## Compilation

### Linux/macOS/Unix:
```bash
gcc -o ai_to_cocaine ai_to_cocaine.c
```

### Windows (using GCC/MinGW):
```bash
gcc -o ai_to_cocaine.exe findreplace.c
```

### Windows (using Visual Studio):
```bash
cl ai_to_cocaine.c
```

## Usage

The program reads text from standard input (stdin) and writes the processed output to `the_cocaine_file.txt`.

### Basic Usage Examples

**Process a text file:**
```bash
cat input.txt | ./ai_to_cocaine
```

**Process text from echo:**
```bash
echo "AI is amazing and AI helps everyone" | ./ai_to_cocaine
```

**Process text from another command:**
```bash
curl -s https://example.com/text.txt | ./ai_to_cocaine
```

**On Windows:**
```bash
type input.txt | ai_to_cocaine.exe
```

### Input/Output Examples

**Input:**
```
The AI revolution is here.
AI systems are becoming more sophisticated.
Many companies are investing in AI technology.
```

**Output (saved to output.txt):**
```
The cocaine revolution is here.
cocaine systems are becoming more sophisticated.
Many companies are investing in cocaine technology.
```

## Program Architecture

### Algorithm Overview

The program uses a **two-pass replacement algorithm** for optimal memory efficiency:

1. **First Pass**: Counts occurrences of the search term to calculate exact memory requirements
2. **Second Pass**: Builds the result string with replacements

This approach minimizes memory allocation overhead compared to dynamic string building.

### Memory Management

- **Line-by-line processing**: Only one line is held in memory at a time
- **Precise allocation**: Calculates exact memory needed for each replacement
- **Immediate cleanup**: Frees memory after processing each line
- **Error-safe**: Cleans up resources even when errors occur

### File Operations

- **Streaming input**: Reads from stdin using `fgets()` for efficient large file handling
- **Buffered output**: Writes to file using `fprintf()` with automatic buffering
- **Error handling**: Checks for file creation failures and reports errors appropriately

## Code Structure

### Constants
```c
#define BUFFER_SIZE 4096        // Input buffer size (4KB)
#define TARGET_STRING "AI"        // Text to find
#define REPLACEMENT_STRING "cutie-pies"  // Replacement text
#define OUTPUT_FILE "output.txt"  // Output file name
```

### Key Functions

**`ai_cocainizer()`**
- Takes input string, search term, and replacement term
- Returns dynamically allocated string with replacements
- Handles memory allocation and string building

**`main()`**
- Manages file operations and input/output
- Processes text line by line
- Handles error conditions and cleanup

## Customization

### Changing Search/Replace Terms

Edit the constants at the top of the source file:
```c
#define TARGET_STRING "your_search_term"
#define REPLACEMENT_STRING "your_replacement"
```

### Changing Output File

Modify the output filename:
```c
#define OUTPUT_FILE "your_output_file.txt"
```

### Adjusting Buffer Size

For very long lines, increase the buffer size:
```c
#define BUFFER_SIZE 8192  // 8KB buffer
```

## Error Handling

The program handles several error conditions:

- **Memory allocation failure**: Exits gracefully with error code 1
- **File creation failure**: Reports error and exits with error code 69
- **Resource cleanup**: Ensures files are closed and memory is freed even on errors

## Limitations

- **Line length**: Limited by `BUFFER_SIZE` (default 4KB per line)
- **Case sensitivity**: Searches are case-sensitive ("AI" vs "ai")
- **Whole word matching**: Replaces partial matches ("SAIL" becomes "cutie-piesSIL")
- **Fixed terms**: Search and replace terms are compile-time constants

## Potential Enhancements

### For Learning Projects:
1. **Command-line arguments**: Accept search/replace terms as program arguments
2. **Case-insensitive matching**: Add option for case-insensitive replacement
3. **Whole word matching**: Only replace complete words, not partial matches
4. **Multiple file support**: Process multiple input files
5. **In-place editing**: Option to modify files directly instead of creating new ones
6. **Regular expressions**: Support for pattern-based replacements
7. **Unicode support**: Handle international characters properly

## Performance Characteristics

- **Time Complexity**: O(n * m) where n is input size and m is average line length
- **Space Complexity**: O(k) where k is the longest line length after replacements
- **Memory Usage**: Minimal - only one line processed at a time
- **File Size**: Can handle files of any size due to streaming processing

## Learning Objectives

This project demonstrates several important C programming concepts:

### Memory Management
- Dynamic memory allocation with `malloc()`
- Proper cleanup with `free()`
- Memory leak prevention
- Error handling for allocation failures
- The dangers of both AI and cocaine

### String Processing
- String searching with `strstr()`
- String comparison with `strncmp()`
- String copying and manipulation
- Buffer management and bounds checking

### File I/O
- Reading from standard input with `fgets()`
- Writing to files with `fprintf()`
- File handle management with `fopen()`/`fclose()`
- Error handling for file operations

### Software Engineering
- Separation of concerns (separate functions for different tasks)
- Const correctness in function parameters
- Meaningful constants instead of magic numbers
- Comprehensive error handling and resource cleanup

## License

This project is provided partially as educational material, but it was mostly done for the lolz. Feel free to use, modify, and distribute for learning and or shitposting purposes.

## Contributing

This is a learning project, but suggestions for educational or basic life improvements are welcome:
- Better error messages
- Additional comments for clarity
- More comprehensive test cases
- Performance optimizations that maintain readability