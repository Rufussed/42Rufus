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

//-Your Code--------------------------------------------------------------

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return len;
}

char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *dup = malloc(len + 1);
    int i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

int quit(FILE *stream)
{
    if (peek(stream) == ':')
        return -1;
    unexpected(stream);
    return -1;
}

int parse_int(json *dst, FILE *stream)
{
    // check start is int
    if (!(peek(stream) == '-' || isdigit(peek(stream))))
        return quit(stream);

    // if start is minus, check next is digit
    if (peek(stream) == '-')
    {
        char c = getc(stream);
        if (!isdigit(peek(stream)))
            return quit(stream);
        ungetc(c, stream);
    }

    // scan integer to struct
    dst->type = INTEGER;
    fscanf(stream, "%d", &dst->integer);
    return 1;
}

int parse_string(json *dst, FILE *stream)
{
    if (!accept(stream,'"'))
        return quit(stream);
    
    dst->type = STRING;
    char buffer[512];
    int len = 0;
    char c;
    while (1)
    {
        c = getc(stream);

        if (c == EOF)
            return quit(stream);

        // check for end and store buffer in struct
        if (c == '"')
        {
            buffer[len] = '\0';
            dst->string = ft_strdup(buffer);
            return 1;
        }

        // handle escape
        if (c == '\\' && (peek(stream) == '"' || peek(stream) == '\\'))
            c = getc(stream);

        // add char to buffer with len increment
        buffer[len++] = c;
    }
    return -1;
}

int parse_map(json *dst, FILE *stream)
{
    if (!accept(stream, '{'))
        return quit(stream);
    if (accept(stream, '}'))
        return quit(stream);
    dst->type = MAP;
    dst->map.data = NULL;
    dst->map.size = 0;
    while (1)
    {
        // grow map
        dst->map.size++;

        // realloc
        dst->map.data = realloc(dst->map.data, dst->map.size * sizeof(pair));

        // expect string key
        json key = {0}; // Zero-initialize
        if (parse_string(&key, stream) == -1)
            return -1;
        if(key.string)
            dst->map.data[dst->map.size - 1].key = ft_strdup(key.string);
        free_json(key);

        // expect :
        if (!accept(stream, ':'))
            return quit(stream);

        // expect value        
        if (argo(&dst->map.data[dst->map.size - 1].value, stream) == -1)
            return -1;

        // check for }
        if (accept(stream, '}'))
        {
            if (peek(stream) == EOF || peek(stream) == ',' || peek(stream) == '}')
                return 1;            
        }

        // check for ,
        else if (!accept(stream, ','))
            return quit(stream);
    }
    return -1;
}

int argo(json *dst, FILE *stream)
{
    int c = peek(stream);

    if (c == '"')
        return parse_string(dst, stream);
    if (c == '{')
        return parse_map(dst, stream);
    if (c == '-' || isdigit(c))
        return parse_int(dst, stream);
    unexpected(stream);
    return -1;
}
