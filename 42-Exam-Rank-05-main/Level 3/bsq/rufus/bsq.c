// Allowed functions and globals: malloc, calloc, realloc, free, fopen, fclose,
// getline, fscanf, fputs, fprintf, stderr, stdout, stdin, errno

// to generate a map try: gcc -Wall -Werror -Wextra gen_map.c -o map && ./map > map2.bsq
// to test the map try: gcc -Wall -Werror -Wextra bsq.c -o bsq && ./bsq map2.bsq

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

enum e_cell
{
    EMPTY = 0,
    OBSTACLE = 1,
    FULL = 2
};

typedef struct s_bsq
{
    int x;
    int y;
    int size;
} t_bsq;

typedef struct s_data
{
    int x;
    int y;
    int map[MAX_SIZE][MAX_SIZE];
    char empty;
    char obstacle;
    char full;
    t_bsq bsq;
} t_data;

int read_first_line(FILE *file, t_data *data)
{
    char *line = NULL;
    size_t len = 0;
    int read;  

    read = getline(&line, &len, file);
    if (read < 0 || line[read - 1] != '\n')  // Check for proper newline
    {
        free(line);
        return (0);
    }
    line[read - 1] = '\0';  // Remove newline for sscanf

    if (sscanf(line, "%d %c %c %c", &data->y, &data->empty, 
        &data->obstacle, &data->full) != 4 || data->y < 1)
    {
        free(line);
        return (0);
    }
    // Check for duplicate characters
    if (data->empty == data->obstacle || data->empty == data->full || 
        data->obstacle == data->full)
    {
        free(line);
        return (0);
    }
    free(line);
    return (1);
}

int read_map(FILE *file, t_data *data)
{
    char *line = NULL;
    size_t len = 0;
    int read;
    int y = 0;

    while ((read = getline(&line, &len, file)) > 0 && y < data->y)
    {
        if (line[read - 1] != '\n')  // Check for proper newline
            break;
        line[read - 1] = '\0';  // Remove newline for processing
        
        if (y == 0)
        {
            data->x = read - 1;
            if (data->x < 1)  // Check for at least one box
                break;
        }
        else if (read - 1 != data->x)  // Use read length instead of strlen
            break;

        for (int x = 0; x < data->x; x++)
        {
            if (line[x] == data->empty)
                data->map[y][x] = EMPTY;
            else if (line[x] == data->obstacle)
                data->map[y][x] = OBSTACLE;
            else
                break;  // Invalid character found
        }
        y++;
    }
    free(line);
    return (y == data->y);  // Return 0 if we didn't read all lines
}

void print_map(t_data *data)
{
    for (int y = 0; y < data->y; y++)
    {
        for (int x = 0; x < data->x; x++)
        {
            if (data->map[y][x] == EMPTY)
                putchar(data->empty);
            else if (data->map[y][x] == OBSTACLE)
                putchar(data->obstacle);
            else if (data->map[y][x] == FULL)
                putchar(data->full);
        }
        putchar('\n');
    }
}

void try_position(t_data *data)
{
    data->bsq.size = 0;
    
    for (int y = 0; y < data->y; y++)
    {
        for (int x = 0; x < data->x; x++)
        {
            if (data->map[y][x] == EMPTY)
            {
                for (int size = 1; y + size < data->y && x + size < data->x; size++) // iterate size less than boundaries
                {
                    int valid = 1; // last check was valid, assume it is valid until proven otherwise
                    for (int i = 1; i <= size && valid; i++) // Start from 1 since we're checking new edges
                    {
                        if (data->map[y + size][x + i] == OBSTACLE 
                        ||  data->map[y + i][x + size] == OBSTACLE)
                            valid = 0; //invalid
                    }
                    if (!valid)
                        break; // check if the square is valid
                    if (size > data->bsq.size) // add valid square to data if it is bigger than current biggest
                    {
                        data->bsq.size = size;
                        data->bsq.x = x;
                        data->bsq.y = y;
                    }
                } 
            }
        }
    }

    // Fill the square on the map
    for (int i = data->bsq.y; i < data->bsq.y + data->bsq.size; i++)
        for (int j = data->bsq.x; j < data->bsq.x + data->bsq.size; j++)
            data->map[i][j] = FULL;
}

int main(int argc, char **argv)
{
    t_data data;
    FILE *file;

    if (argc != 2)
        file = stdin;// in the case of no args we read from stdin instead of showing error 
    else
    {
        file = fopen(argv[1], "r");
        if (!file)
        {
            fprintf(stderr, "map error\n");
            return (1);
        }
    }
    if (!read_first_line(file, &data) || !read_map(file, &data))
    {
        fprintf(stderr, "map error\n");
        if (file != stdin)
            fclose(file);
        return (1);
    }
    try_position(&data);
    print_map(&data);
    if (file != stdin)
        fclose(file);
    return (0);
}