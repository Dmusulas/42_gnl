# 42 Project: Get Next Line

## Summary

The `get_next_line` function is designed to simplify the process of reading lines from a file descriptor. This function is particularly useful in C programming, where reading from a file descriptor line by line can be quite tedious and error-prone. The function handles all the intricacies of reading and managing memory, providing a straightforward way to get the next line of text from a file or standard input.

## How It Works

1. **Reading a Line**: The `readline` function reads from a file descriptor into a buffer. It appends the read data to a provided string until a newline character is encountered or the end of the file is reached. It uses dynamic memory allocation to manage the buffer and the resulting string.

2. **Handling Remainder**: The `get_remainder` function extracts the part of the line that comes after the newline character, if any. This part is stored for the next call to `get_next_line`.

3. **Main Function**: The `get_next_line` function combines the above functionalities. It reads the next line from the file descriptor and returns it. It uses a static variable to remember the remainder of the previous read, ensuring that lines are read continuously across multiple calls.

### Function Prototypes

- `char *get_next_line(int fd);`

### Parameters

- `int fd`: The file descriptor to read from.

### Return Value

- Returns the next line read from the file descriptor.
- Returns `NULL` if there is nothing left to read or if an error occurs.

### External Functions

- `read`
- `malloc`
- `free`

## Usage

To use the `get_next_line` function in your program, follow these steps:

1. **Include the Header**: Ensure that your program includes the `get_next_line.h` header file.

2. **Compile the Program**: Compile the source files along with your program. You can compile your code with different buffer sizes using the `-D BUFFER_SIZE=n` flag.

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

3. **Call the Function**: In your code, call the `get_next_line` function in a loop to read lines from a file descriptor until it returns `NULL`.

```c
#include "get_next_line.h"
#include <fcntl.h> // For open
#include <unistd.h> // For close
#include <stdio.h> // For printf

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Compilation Instructions

- Ensure all source files (`get_next_line.c`, `get_next_line_utils.c`) and header files (`get_next_line.h`) are in the same directory.
- Compile your project with appropriate flags.
