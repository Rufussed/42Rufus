#include "argo.h"

int peek(FILE *stream)
{
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}

void unexpected(FILE *stream)
{
    if (peek(stream) != EOF)
        printf("Unexpected token '%c'\n", peek(stream));
    else
        printf("Unexpected end of input\n");
}

int accept(FILE *stream, char c)
{
    if (peek(stream) == c)
    {
        (void)getc(stream);
        return 1;
    }
    return 0;
}

int expect(FILE *stream, char c)
{
    if (accept(stream, c))
    {
        return 1;
    }
    unexpected(stream);
    return 0;
}


//----------------------------------------------------------------

// Parse a JSON string
int parse_string(json *dst, FILE *stream) {
    if (getc(stream) != '"') {
        unexpected(stream);
        return 0;
    }

    size_t capacity = 16;
    size_t length = 0;
    char *buffer = malloc(capacity);
    if (!buffer) return 0;

    int escape = 0;
    while (1) {
        int c = getc(stream);
        
        if (c == EOF) {
            free(buffer);
            unexpected(stream);
            return 0;
        }

        // Handle escape sequences
        if (escape) {
            if (c == '"' || c == '\\') {
                if (length + 1 >= capacity) {
                    capacity *= 2;
                    char *new_buffer = realloc(buffer, capacity);
                    if (!new_buffer) {
                        free(buffer);
                        return 0;
                    }
                    buffer = new_buffer;
                }
                buffer[length++] = c;
                escape = 0;
                continue;
            }
            free(buffer);
            unexpected(stream);
            return 0;
        }

        // Check for string termination
        if (c == '"') {
            buffer[length] = '\0';
            dst->type = STRING;
            dst->string = buffer;
            return 1;
        }

        // Handle backslash escape
        if (c == '\\') {
            escape = 1;
            continue;
        }

        // Grow buffer if needed
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *new_buffer = realloc(buffer, capacity);
            if (!new_buffer) {
                free(buffer);
                return 0;
            }
            buffer = new_buffer;
        }

        // Store character
        buffer[length++] = c;
    }
}

// Parse an integer
int parse_integer(json *dst, FILE *stream) {
    int value = 0;
    int sign = 1;
    int first_digit = 1;

    while (1) {
        int c = peek(stream);

        // Handle optional sign
        if (first_digit && c == '-') {
            sign = -1;
            getc(stream);
            first_digit = 0;
            continue;
        }

        // Check for digit
        if (c >= '0' && c <= '9') {
            c = getc(stream);
            value = value * 10 + (c - '0');
            first_digit = 0;
            continue;
        }

        // End of integer
        if (!first_digit) {
            dst->type = INTEGER;
            dst->integer = sign * value;
            return 1;
        }

        // No valid integer found
        unexpected(stream);
        return 0;
    }
}

// Parse a JSON map/object
int parse_map(json *dst, FILE *stream) {
    if (getc(stream) != '{') {
        unexpected(stream);
        return 0;
    }

    dst->type = MAP;
    dst->map.data = NULL;
    dst->map.size = 0;

    // Immediately check for empty map without allowing any whitespace
    int next = peek(stream);
    if (next == '}') {
        getc(stream);
        return 1;
    }

    while (1) {
        // Resize map to add new pair
        size_t new_size = dst->map.size + 1;
        pair *new_data = realloc(dst->map.data, new_size * sizeof(pair));
        if (!new_data) return 0;
        dst->map.data = new_data;

        // Parse key (must be a string)
        json key;
        if (!parse_string(&key, stream)) return 0;
        dst->map.data[dst->map.size].key = key.string;

        // Expect immediate colon
        if (getc(stream) != ':') {
            unexpected(stream);
            return 0;
        }

        // Parse value
        json *value = &dst->map.data[dst->map.size].value;
        if (!argo(value, stream)) return 0;

        // Increment size
        dst->map.size++;

        // Check for comma or closing brace
        next = peek(stream);
        if (next == '}') {
            getc(stream);
            return 1;
        }
        if (next != ',') {
            unexpected(stream);
            return 0;
        }
        getc(stream);
    }
}


int argo(json *dst, FILE *stream) {
   
    int next = peek(stream);

    if (next == '"')
        return parse_string(dst, stream);
    
    if (next == '{')
        return parse_map(dst, stream);

    if (next == '-' || (next >= '0' && next <= '9'))
        return parse_integer(dst, stream);

    unexpected(stream);
    return 0;
}
