#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[256];
    int ch;

    // Open a file for reading
    file = fopen("example.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    printf("Using fgets:\n");
    // Read a line using fgets
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    // Reset the file pointer to the beginning
    rewind(file);

    printf("\nUsing getc and ungetc:\n");
    // Read characters using getc and demonstrate ungetc
    while ((ch = getc(file)) != EOF) {
        if (ch == 'a') {
            // Push the character back into the stream
            ungetc(ch, file);
            // Read it again (but only once)
            ch = getc(file);
            printf("[ungetc: '%c'] ", ch);
        } else {
            putchar(ch);
        }
    }

    // Close the file
    fclose(file);
    return EXIT_SUCCESS;
}
