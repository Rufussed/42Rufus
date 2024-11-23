/*assignment :argo

allowed functions: getc, ungetc, printf, malloc, calloc, realloc, free, isdigit, fscanf, write.
Write a function argo that will parse a json file in the structure declared.
int argo(json* dst, FILE* stream);
dst     is the pointer to the AST that you will create.
stream  is the file to parse.
your function will return 1 on success and -1 on failure.
unexpected token should return "unexpected %c\n"
unexpected token EOF should return "unexpected end of input\n"
only handle numbers, strings and maps.
Numbers will only be basic ints like in scanf("%d")
Handle escaping in the strings only for backslashes and quotation marks (no \n \u ...)
Don't handle spaces -> consider them as invalid tokens.
$echo -n '1' | ./argo /dev/stdin | cat -e
1$
$echo -n '"bonjour"' | ./argo /dev/stdin | cat -e
"bonjour"$
$echo -n '"escape! \" "' | ./argo /dev/stdin | cat -e
"escape! \" "$
$echo -n '{"tomatoes":42,"potatoes":234}' | ./argo /dev/stdin | cat -e
{"tomatoes":42,"potatoes":234}$
$echo -n '{"recursion":{"recursion":{"recursion":{"recursion":"recursion"}}}}' | ./argo /dev/stdin | cat -e
{"recursion":{"recursion":{"recursion":{"recursion":"recursion"}}}}$
$echo -n '"unfinished string' | ./argo /dev/stdin | cat -e
unexpected end of input$
$echo -n '"unfinished string 2\"' | ./argo /dev/stdin | cat -e
unexpected end of input$
$echo -n '{"no value?":}' | ./argo /dev/stdin | cat -e
unexpected token '}'$ */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>



typedef struct json {
    enum { JSON_NUMBER, JSON_STRING, JSON_MAP } type;
    union {
        int number;
        char *string;
        struct json *map;
    } value;
    struct json *next; // For map key-value pairs, linked list
} json;

void write_string(const char *str) {
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

int parse_number(FILE *stream, json *dst) {
    int value = 0;
    int ch = getc(stream);
    if (!isdigit(ch)) {
        ungetc(ch, stream);
        return 0; // Not a number
    }

    // Parse the number
    do {
        value = value * 10 + (ch - '0');
        ch = getc(stream);
    } while (isdigit(ch));
    ungetc(ch, stream); // Push back the non-digit character

    dst->type = JSON_NUMBER;
    dst->value.number = value;
    return 1;
}

int parse_string(FILE *stream, json *dst) {
    int ch = getc(stream);
    if (ch != '"') {
        return 0; // Not a valid string
    }

    // Start reading the string
    size_t size = 0;
    size_t capacity = 10;
    char *str = malloc(capacity);
    if (!str) {
        return -1; // Memory allocation failure
    }

    while ((ch = getc(stream)) != '"') {
        if (ch == EOF) {
            free(str);
            return 0; // Unexpected end of input
        }

        if (ch == '\\') {
            // Escape sequence handling
            ch = getc(stream);
            if (ch == '\\' || ch == '"') {
                str[size++] = ch;
            } else {
                free(str);
                return 0; // Invalid escape sequence
            }
        } else {
            str[size++] = ch;
        }

        if (size >= capacity) {
            capacity *= 2;
            str = realloc(str, capacity);
            if (!str) {
                return -1; // Memory allocation failure
            }
        }
    }

    str[size] = '\0'; // Null-terminate the string
    dst->type = JSON_STRING;
    dst->value.string = str;
    return 1;
}

int parse_map(FILE *stream, json *dst) {
    int ch = getc(stream);
    if (ch != '{') {
        return 0; // Not a valid map
    }

    dst->type = JSON_MAP;
    dst->value.map = NULL;
    json *last = NULL;

    while (1) {
        // Skip spaces (invalid tokens)
        ch = getc(stream);
        if (ch == EOF) {
            return 0; // Unexpected end of input
        }

        if (isspace(ch)) {
            continue;
        }

        if (ch == '}') {
            break; // End of map
        }

        // Read the key (string)
        ungetc(ch, stream);
        json *key = malloc(sizeof(json));
        if (!key || !parse_string(stream, key)) {
            return 0; // Error parsing key or memory allocation
        }

        // Read the colon
        ch = getc(stream);
        if (ch != ':') {
            return 0; // Expected colon
        }

        // Read the value (number or string or another map)
        json *value = malloc(sizeof(json));
        if (!value) {
            return 0; // Memory allocation failure
        }

        if (parse_number(stream, value)) {
            value->type = JSON_NUMBER;
        } else if (parse_string(stream, value)) {
            value->type = JSON_STRING;
        } else if (parse_map(stream, value)) {
            value->type = JSON_MAP;
        } else {
            return 0; // Unexpected token
        }

        // Add the key-value pair to the map
        if (last) {
            last->next = key;
            key->next = value;
        } else {
            dst->value.map = key;
            key->next = value;
        }
        last = value;

        // Skip spaces (invalid tokens)
        ch = getc(stream);
        if (ch == EOF) {
            return 0; // Unexpected end of input
        }

        if (ch == '}') {
            break;
        }

        if (ch != ',') {
            return 0; // Expected comma or closing brace
        }
    }

    return 1;
}

int argo(json *dst, FILE *stream) {
    int ch = getc(stream);
    if (ch == EOF) {
        write_string("unexpected end of input\n");
        return -1;
    }

    if (isdigit(ch)) {
        ungetc(ch, stream);
        return parse_number(stream, dst);
    } else if (ch == '"') {
        ungetc(ch, stream);
        return parse_string(stream, dst);
    } else if (ch == '{') {
        ungetc(ch, stream);
        return parse_map(stream, dst);
    } else {
        write_string("unexpected token '");
        write(1, &ch, 1);
        write_string("'\n");
        return -1;
    }
}

int main(int ac, char **av) {
    if (ac != 2)
        return 1;
    char *filename = av[1];
    FILE *stream = fopen(filename, "r");
    json file;
    if (!stream) {
        perror("fmemopen");
        return 1;
    }
    if (argo(&file, stream) != 1) {
        return 1;
    }
	printf("\n");
    return 0;
}
