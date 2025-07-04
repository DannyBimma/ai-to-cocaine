# AI to Cocaine

Have you ever been reading yet another article about AI, but desperately found yourself wishing it was all about cocaine instead? According to a post on the r/ProgrammerHumor subreddit, you are not alone!! This is a simple and efficient C program that reads text from standard input, replaces all occurrences of "AI" with "cocaine", and saves the result to a text file.

The ai_to_cocaine program was created partly as a meme, but mostly to highlight the ridiculous nature of the claims, warnings, and predictions being made by overly bullish leaders in the industry. It is my personal belief that AI has a staunch place in the future of humanity, but it shall not wholely define it.

To pen an article or leaked internal memo suggesting that AI will produce either a utopia or a distopia for developers and humanity at large in the coming decade, sounds as ridiculous as the cocaine-laced output from this program... and therein lays it's use case 😉 

![Cocaine meme](https://scontent-ams4-1.cdninstagram.com/v/t51.2885-15/504006890_17916168687099317_7891265429953077634_n.jpg?stp=dst-jpg_e35_tt6&efg=eyJ2ZW5jb2RlX3RhZyI6InRocmVhZHMuRkVFRC5pbWFnZV91cmxnZW4uMTE2NHg3MDguc2RyLmY3NTc2MS5kZWZhdWx0X2ltYWdlIn0&_nc_ht=scontent-ams4-1.cdninstagram.com&_nc_cat=105&_nc_oc=Q6cZ2QFQxFu5d9hiF72VoklMaZ2FAz72UhwISEIKOAP3HcdcOvzwyivV1sv6Vn96U5tibAIZbloOu8AiG2DtkqPYVYUT&_nc_ohc=hF8SGmFTQxsQ7kNvwHC8q2y&_nc_gid=0YiVmFZ0o8GiKHlPSzeWuA&edm=AA3DLpEBAAAA&ccb=7-5&ig_cache_key=MzY0OTI2NTg2NzQxNTczNjk5Mg%3D%3D.3-ccb7-5&oh=00_AfNH1biQRHt_EjWPxIALzvgXlbJAfv6Xig_KoJL9QdBe0w&oe=68496D50&_nc_sid=d92198)

## Features

- **Memory-efficient**: Processes text stream line-by-line instead of loading entire file into memory
- **No memory leaks**: Proper memory management with every malloc being freed (I think)
- **C90/C89 standard**: Follows the guidance of Ritchie and Kernighan
- **Error handling**: Exit code Easter-egg, handling of memory allocation and file operation failures
- **Cross-platform**: Works on my machine and hopefully yours as well

## Sys Requirements

- C compiler (GCC, Clang, or Microsoft Visual C++)
- Standard C library
- A sense of humour

## Compilation

### Linux/macOS/Unix:
```bash
gcc -o ai_to_cocaine ai_to_cocaine.c
```

### Windows (using GCC/MinGW):
```bash
gcc -o ai_to_cocaine.exe ai_to_cocaine.c
```

### Windows (using Visual Studio):
```bash
cl ai_to_cocaine.c
```

## Usage

The program reads text from standard input (stdin) and writes the modified output to:
`the_cocaine_file.txt`

### Basic Usage Examples

**Modify a text file:**
```bash
cat input.txt | ./ai_to_cocaine
```

**Modify text from echo:**
```bash
echo "AI is amazing and AI helps everyone" | ./ai_to_cocaine
```

**Modify text from another command:**
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
The AI revolution is here! As AI systems are 
becoming more sophisticated, many tech companies 
are investing in AI technology.
```

**Output (saved to output.txt):**
```
The cocaine revolution is here! As cocaine systems are 
becoming more sophisticated, many tech companies 
are investing in cocaine technology.
```

## Program Architecture

### Algorithm Overview

The program uses a **two-pass replacement algorithm** for optimal memory efficiency:

1. **First Pass**: Counts occurrences of the target-term (AI) to calculate the exact memory requirements
2. **Second Pass**: Builds the output string with replacements

This approach minimises memory allocation overhead compared to dynamic string building.

### Memory Management

- **Line-by-line processing**: Only one line is held in memory at a time
- **Immediate cleanup**: Frees memory after processing each line, and accounts for use-after-free even if this program will never run into that particular problem
- **Error-safe**: Cleans up resources even when errors occur

### File Operations

- **Streaming input**: Reads from stdin using `fgets()` for efficient large file processing
- **Buffered output**: Writes to file using `fprintf()` with automatic buffering
- **Error handling**: Checks for file creation failures and reports errors if(any)

## Code Structure

### Constants
```c
#define BUFFER_SIZE 4096        // Input buffer size (4KB)
#define TARGET_STRING "AI"        // Text to find
#define REPLACEMENT_STRING "cocaine-to-ai"  // Replacement text
#define OUTPUT_FILE "output.txt"  // Output file name
```

### Key Functions

**`ai_cocainizer()`**
- Takes input string, target string, and replacement term
- Returns dynamically allocated string with replacements
- Handles memory allocation and string building

**`main()`**
- Manages file operations and input/output
- Processes text line by line
- Handles error conditions and cleanup

## Customisation

### Changing Search/Target Terms

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

- **Memory allocation failure**: Exits with error code 1
- **File creation failure**: Reports error and exits with error code 69 (the Easter-egg!!)
- **Resource cleanup**: Ensures files are closed and memory is freed even on errors

## Limitations

- **Line length**: Limited by `BUFFER_SIZE` (default 4KB per line)
- **Case sensitivity**: Searches are case-sensitive ("AI" vs "ai")
- **Full word matching**: Replaces partial matches found within other words ("SAIL" becomes "ScocaineL")
- **Fixed terms**: Target and replacement terms are compile-time constants

## Potential Enhancements

### For Learning Projects:
1. **Command-line arguments**: Accept target/replacement terms as command line arguments
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
- File management with `fopen()`/`fclose()`
- Error handling for file operations

## License

This project is provided partially as educational material, but it was mostly done to prove a point for the lolz. Feel free to use, modify, and distribute for learning and or shitposting purposes.

## Contributing

This is a learning project, but suggestions for educational or basic life improvements are welcome 🙂