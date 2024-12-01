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

int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *ft_strdup(const char *str)
{
    int len = ft_strlen(str);
    char *new_str = malloc(len + 1);
    if (!new_str)
        return NULL;
    for (int i = 0; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return new_str;
}

int fail(FILE *stream)
{
        unexpected(stream);
        return 0;
}

// Parse a JSON string
int parse_string(json *dst, FILE *stream)
{
    char buffer[512];
    int length = 0;

    if(getc(stream) != '"') // get & check first quote
        return fail(stream);
    
    while (1)
    {
        int c = getc(stream);

        if (c == EOF) // Check for string termination
            return fail(stream);
        
        if (c == '"')
        {
            buffer[length] = '\0';
            dst->type = STRING;
            dst->string = ft_strdup(buffer);
            return 1;
        }
        if (c == '\\' && (peek(stream) == '"' || peek(stream) == '\\'))
        {
            c = getc(stream);
            printf("c: %c\n", c);
        }
        buffer[length++] = c;   // Store character
    }
}

// Parse an integer
int parse_integer(json *dst, FILE *stream)
{
    if (!isdigit(peek(stream)) && peek(stream) != '-')
     {
        unexpected(stream);
        return 0;
    }
    if (peek(stream) == '-')
    {
        getc(stream);
        if (!isdigit(peek(stream)))
            return fail(stream);
        ungetc('-', stream);
    }
    dst->type = INTEGER;
    fscanf(stream, "%d", &dst->integer);
    return 1;
}

int parse_map(json *dst, FILE *stream)
{
    if (getc(stream) != '{')
        return fail(stream);  

    dst->type = MAP;
    dst->map.data = NULL;
    dst->map.size = 0;
   
    if (peek(stream) == '}')
    {   
        getc(stream);
        return 1;
    }
    
    while (1)
    {
        dst->map.size++;
        dst->map.data = realloc(dst->map.data, dst->map.size*sizeof(pair));
        
        json *key = malloc(1);       
        if (!parse_string(key, stream)) // expect string
            return 0;        
        dst->map.data[dst->map.size - 1].key = key->string;
        
        if (getc(stream) != ':') // expect colon
            return fail(stream);

        json *value = &dst->map.data[dst->map.size - 1].value;
        if (!argo(value, stream)) // could be any new json
            return 0;

        if (peek(stream) == ',') // see it there are more pairs
        {
            getc(stream);
            continue;
        }

        if (peek(stream) == '}') //finish
        {
            getc(stream);
            return 1;
        }
        return fail(stream); // chars beside , or } are unexpected
    }
}



int argo(json *dst, FILE *stream)
{

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


//Parse a JSON map/object
// int parse_map(json *dst, FILE *stream)
// {
//     if (getc(stream) != '{')
//     {
//         unexpected(stream);
//         return 0;
//     }

//     dst->type = MAP;
//     dst->map.data = NULL;
//     dst->map.size = 0;

//     // Immediately check for empty map without allowing any whitespace
//     int next = peek(stream);
//     if (next == '}')
//     {
//         getc(stream);
//         return 1;
//     }

//     while (1)
//     {
//         // Resize map to add new pair
//         size_t new_size = dst->map.size + 1;
//         pair *new_data = realloc(dst->map.data, new_size * sizeof(pair));
//         if (!new_data)
//             return 0;
//         dst->map.data = new_data;

//         // Parse key (must be a string)
//         json key;
//         if (!parse_string(&key, stream))
//             return 0;
//         dst->map.data[dst->map.size].key = key.string;

//         // Expect immediate colon
//         if (getc(stream) != ':')
//         {
//             unexpected(stream);
//             return 0;
//         }

//         // Parse value
//         json *value = &dst->map.data[dst->map.size].value;
//         if (!argo(value, stream))
//             return 0;

//         // Increment size
//         dst->map.size++;

//         // Check for comma or closing brace
//         next = peek(stream);
//         if (next == '}')
//         {
//             getc(stream);
//             return 1;
//         }
//         if (next != ',')
//         {
//             unexpected(stream);
//             return 0;
//         }
//         getc(stream);
//     }
// }
