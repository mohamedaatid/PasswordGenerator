#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SYMBOLS "!@#$%^&*()_+-=[]{}|;:,.<>?"

void generate_password(char *password, int length, const char *charset);
void print_usage(const char *program_name);
int validate_length(int length);

int main(int argc, char *argv[]) {
    int length = 12; 
    int use_lowercase = 1;
    int use_uppercase = 1;
    int use_digits = 1;
    int use_symbols = 0;
    
    srand(time(NULL));
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--length") == 0) {
            if (i + 1 < argc) {
                length = atoi(argv[++i]);
                if (!validate_length(length)) {
                    fprintf(stderr, "Error: Password length must be between 4 and 128\n");
                    return 1;
                }
            } else {
                fprintf(stderr, "Error: Length option requires a value\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--symbols") == 0) {
            use_symbols = 1;
        }
        else if (strcmp(argv[i], "--no-lowercase") == 0) {
            use_lowercase = 0;
        }
        else if (strcmp(argv[i], "--no-uppercase") == 0) {
            use_uppercase = 0;
        }
        else if (strcmp(argv[i], "--no-digits") == 0) {
            use_digits = 0;
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        }
        else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }
    
    char charset[256] = "";
    
    if (use_lowercase) {
        strcat(charset, LOWERCASE);
    }
    if (use_uppercase) {
        strcat(charset, UPPERCASE);
    }
    if (use_digits) {
        strcat(charset, DIGITS);
    }
    if (use_symbols) {
        strcat(charset, SYMBOLS);
    }
    
    if (strlen(charset) == 0) {
        fprintf(stderr, "Error: At least one character set must be enabled\n");
        return 1;
    }
    
    char *password = malloc(length + 1);
    if (password == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return 1;
    }
    
    generate_password(password, length, charset);
    printf("Generated password: %s\n", password);
    
    printf("Password length: %d\n", length);
    printf("Character set size: %zu\n", strlen(charset));
    printf("Character sets used: ");
    if (use_lowercase) printf("lowercase ");
    if (use_uppercase) printf("uppercase ");
    if (use_digits) printf("digits ");
    if (use_symbols) printf("symbols ");
    printf("\n");
    
    free(password);
    return 0;
}

void generate_password(char *password, int length, const char *charset) {
    int charset_len = strlen(charset);
    
    for (int i = 0; i < length; i++) {
        int random_index = rand() % charset_len;
        password[i] = charset[random_index];
    }
    password[length] = '\0'; 
}

int validate_length(int length) {
    return (length >= 4 && length <= 128);
}

void print_usage(const char *program_name) {
    printf("Password Generator\n");
    printf("Usage: %s [OPTIONS]\n\n", program_name);
    printf("Options:\n");
    printf("  -l, --length <num>    Set password length (default: 12, range: 4-128)\n");
    printf("  -s, --symbols         Include special symbols in password\n");
    printf("  --no-lowercase        Exclude lowercase letters\n");
    printf("  --no-uppercase        Exclude uppercase letters\n");
    printf("  --no-digits           Exclude digits\n");
    printf("  -h, --help            Show this help message\n\n");
    printf("Examples:\n");
    printf("  %s                    Generate 12-character password (default)\n", program_name);
    printf("  %s -l 16              Generate 16-character password\n", program_name);
    printf("  %s -s                 Generate password with symbols\n", program_name);
    printf("  %s -l 20 -s           Generate 20-character password with symbols\n", program_name);
}