# Password Generator

A robust command-line utility written in C for generating secure, customizable passwords. This tool provides granular control over password length and character composition, making it ideal for developers and users requiring strong, random passwords.

### Key Features

- **Customizable Length:** Define the password length, ranging from 4 to 128 characters.
    
- **Character Set Control:** Include or exclude lowercase letters, uppercase letters, digits, and special symbols to meet specific security requirements.
    
- **Command-Line Interface:** Seamlessly integrate password generation into scripts and workflows via a straightforward command-line interface.
    
- **Comprehensive Error Handling:** The program provides clear, descriptive error messages for invalid inputs or system failures.
    

### Compilation

To compile the source code, a standard C compiler such as GCC is required. Execute the following command in your terminal:

```
gcc -o password_generator password_generator.c
```

This command generates a single executable file named `password_generator`.

### Usage

The program can be executed with various command-line options to customize the password generation process.

```
./password_generator [OPTIONS]
```

#### Options

- `-l, --length <num>`: Specifies the desired password length. The default is 12.
    
- `-s, --symbols`: Enables the inclusion of special symbols.
    
- `--no-lowercase`: Excludes lowercase letters from the character set.
    
- `--no-uppercase`: Excludes uppercase letters from the character set.
    
- `--no-digits`: Excludes digits from the character set.
    
- `-h, --help`: Displays the help message and available options.
    

#### Examples

```
# Generate a default 12-character password
./password_generator

# Generate a 16-character password
./password_generator -l 16

# Generate a password including special symbols
./password_generator -s

# Generate a 20-character password with symbols
./password_generator -l 20 -s

# Generate a password using only uppercase letters and digits
./password_generator --no-lowercase --no-symbols
```

### Code Overview

The codebase is organized into modular functions for clarity and maintainability.

#### 1. Header Files and Macros

The program relies on standard C libraries for core functionalities such as string manipulation, input/output, and random number generation. Character sets are defined using `#define` macros for enhanced code readability.

#### 2. Main Function

The `main` function serves as the program's entry point, handling command-line argument parsing. It dynamically constructs the character set based on user-provided flags and allocates memory for the generated password before invoking the `generate_password` function.

#### 3. `generate_password` Function

This function implements the core password generation logic. It iterates over the specified length, selecting a random character from the compiled character set for each position. The function ensures the final output is a properly null-terminated string.

#### 4. Helper Functions

- `validate_length(int length)`: Validates that the user-specified length falls within the acceptable range of 4 to 128.
    
- `print_usage(const char *program_name)`: Provides a detailed usage guide, displayed when the help flag is used or when an invalid option is provided.
    

### License

This project is licensed under the MIT License.
