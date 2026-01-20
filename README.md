# get_next_line — reading a line from a file descriptor, one at a time

[![1337](https://img.shields.io/badge/1337-000000?style=for-the-badge&logoColor=white)](https://www.1337.ma/)
[![UM6P](https://img.shields.io/badge/UM6P-C1392B?style=for-the-badge)](https://um6p.ma/)
[![42 Badge](https://img.shields.io/badge/get__next__line-00babc?style=for-the-badge&logo=42)](https://42.fr) [![C](https://img.shields.io/badge/programming-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language)) [![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.kernel.org/) [![Makefile](https://img.shields.io/badge/Makefile-2C2D30?style=for-the-badge)](https://www.gnu.org/software/make/)

The implementation of a function that reads and returns a single line from a file descriptor, handling repeated calls to read an entire file line by line.

— Why this project matters

- Teaches static variables and their persistence across function calls
- Strengthens understanding of file descriptors and low-level I/O operations
- Develops skills in dynamic memory allocation and buffer management
- Introduces the concept of reading data in chunks efficiently

--------------------------------------------------------------------------------

## Quick highlights

- Reads from any valid file descriptor (files, stdin, network sockets, etc.)
- Handles variable buffer sizes defined at compile time
- Uses static variables to maintain state between function calls
- Bonus: supports multiple file descriptors simultaneously
- Memory-safe implementation with proper allocation and deallocation

--------------------------------------------------------------------------------

## Project goals

1. Implement `get_next_line()` to return one line at a time from a file descriptor.
2. Handle edge cases: empty files, files without newlines, varying buffer sizes.
3. Provide a bonus version that can manage multiple file descriptors concurrently.

--------------------------------------------------------------------------------

## Function prototype

```c
char *get_next_line(int fd);
```

| Parameter | Description |
|-----------|-------------|
| `fd` | The file descriptor to read from |
| **Return** | The line read (including `\n` if present), or `NULL` if EOF or error |

--------------------------------------------------------------------------------

## Implementation notes — what's under the hood

### Core Files

| File | Purpose |
|------|---------|
| `get_next_line.c` | Main function logic and helper functions |
| `get_next_line_utils.c` | Utility functions (`ft_strlen`, `ft_strchr`, `ft_strdup`, `ft_append`) |
| `get_next_line.h` | Header file with prototypes and `BUFFER_SIZE` definition |

### Bonus Files

| File | Purpose |
|------|---------|
| `get_next_line_bonus.c` | Multi-fd version using static array |
| `get_next_line_utils_bonus.c` | Same utilities for bonus |
| `get_next_line_bonus.h` | Bonus header file |

### How it works

1. **Reading**: Data is read from the file descriptor into a buffer of size `BUFFER_SIZE`.
2. **Stashing**: Read data is appended to a static "stash" variable that persists between calls.
3. **Line extraction**: When a newline is found, the line (including `\n`) is extracted and returned.
4. **Remainder handling**: Any characters after the newline remain in the stash for the next call.
5. **EOF handling**: When `read()` returns 0, remaining stash content is returned.

### Bonus feature

The bonus version uses a static array `stash[1024]` to maintain separate stashes for up to 1024 different file descriptors, allowing simultaneous reading from multiple sources.

--------------------------------------------------------------------------------

## Build & usage

### Using the Makefile

The project includes a Makefile for easy compilation:

```bash
# Build the mandatory version
make

# Build the bonus version (multi-fd support)
make bonus

# Clean compiled binaries
make clean

# Rebuild from scratch
make re
```

This will create:
- `program` — mandatory version executable
- `program_bonus` — bonus version executable

### Manual Compilation

Alternatively, compile manually with a custom `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 src/get_next_line.c src/get_next_line_utils.c src/main.c -o program
```

For the bonus (multiple fd support):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 src_bonus/get_next_line_bonus.c src_bonus/get_next_line_utils_bonus.c src_bonus/main_bonus.c -o program_bonus
```

### Example usage

Add your test code to `src/main.c` (or `src_bonus/main_bonus.c` for bonus):

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
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

Then compile and run:

```bash
make && ./program
```

### Reading from stdin

```c
char *line;

while ((line = get_next_line(0)) != NULL)
{
    printf("You typed: %s", line);
    free(line);
}
```

--------------------------------------------------------------------------------

## Buffer size considerations

The `BUFFER_SIZE` macro affects performance and memory usage:

| Buffer Size | Characteristics |
|-------------|-----------------|
| Small (1-10) | More `read()` calls, less memory, slower |
| Medium (42-1024) | Balanced performance |
| Large (10000+) | Fewer `read()` calls, more memory, faster for large files |

Default value in this implementation: **1337**

--------------------------------------------------------------------------------

## Edge cases handled

-  Empty files
-  Files with no final newline
-  Single character files
-  Very long lines
-  Invalid file descriptors
-  `BUFFER_SIZE` of 1
-  Very large `BUFFER_SIZE` values
-  Binary files (reads until `\n` or EOF)
-  Multiple file descriptors (bonus)

--------------------------------------------------------------------------------

## Project layout

```
get_next_line/
├── Makefile                      # Build automation
├── README.md
├── LICENSE
├── src/                          # Mandatory implementation
│   ├── get_next_line.c           # Main implementation
│   ├── get_next_line.h           # Header file
│   ├── get_next_line_utils.c     # Utility functions
│   └── main.c                    # Test entry point
└── src_bonus/                    # Bonus implementation (multi-fd)
    ├── get_next_line_bonus.c     # Multi-fd implementation
    ├── get_next_line_bonus.h     # Bonus header file
    ├── get_next_line_utils_bonus.c   # Bonus utilities
    └── main_bonus.c              # Bonus test entry point
```

--------------------------------------------------------------------------------

## Testing

Create a test file and run your program:

```bash
echo -e "Line 1\nLine 2\nLine 3" > test.txt
make && ./program
```

Test with different buffer sizes:

```bash
for size in 1 10 42 1000 10000; do
    echo "Testing BUFFER_SIZE=$size"
    cc -D BUFFER_SIZE=$size src/get_next_line.c src/get_next_line_utils.c src/main.c -o test_gnl
    ./test_gnl
done
```

Test the bonus version:

```bash
make bonus && ./program_bonus
```

--------------------------------------------------------------------------------

## Learning outcomes

- Static variables and their behavior across function calls
- File descriptor management and low-level I/O in C
- Dynamic memory allocation strategies
- Buffer management and efficient reading techniques
- Handling edge cases in I/O operations

--------------------------------------------------------------------------------

## Common pitfalls to avoid

- Memory leaks: always `free()` the returned line after use
- Not handling `read()` errors (returns -1)
- Forgetting to null-terminate strings
- Not preserving leftover data in the stash after returning a line

--------------------------------------------------------------------------------

## Resources

- 42 School project subject and documentation
- `man 2 read` — read from a file descriptor
- `man 2 open` — open a file
- `man 3 malloc` — dynamic memory allocation
- Understanding static variables in C

--------------------------------------------------------------------------------

## Contributing & contact

Suggestions, bug reports, or improvements are welcome — open an issue or reach out to `anasinda`.

---

## License

See `LICENSE` at repository root.
