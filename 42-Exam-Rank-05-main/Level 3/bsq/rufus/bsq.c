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
    if (read < 0)  
    {
        free(line);
        return (0);
    }

    if (sscanf(line, "%d %c %c %c", &data->y, &data->empty, 
        &data->obstacle, &data->full) != 4)
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
        if (y == 0)
            data->x = read - 1;
        else if (read - 1 != data->x)
        {
            free(line);
            return (0);
        }
        
        for (int x = 0; x < data->x; x++)
        {
            if (line[x] == data->obstacle)
                data->map[y][x] = OBSTACLE;
            else if (line[x] == data->empty)
                data->map[y][x] = EMPTY;
            else
            {
                free(line);
                return (0);
            }
        }
        y++;
    }
    free(line);
    return (y == data->y);
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
    int max_size = 0;
    int x = 0;
    int y = 0;

    for (y = 0; y < data->y; y++)
    {
        for (x = 0; x < data->x; x++)
        {
            if (data->map[y][x] == EMPTY)
            {
                int size = 1;
                while (y + size < data->y && x + size < data->x)
                {
                    int valid = 1; // square of size "size" is valid
                    for (int i = y; i <= y + size; i++)
                    {
                        for (int j = x; j <= x + size; j++)
                        {
                            if (data->map[i][j] == OBSTACLE)
                            {
                                valid = 0;
                                break;
                            }
                        }
                        if (!valid)
                            break;
                    }
                    if (valid)
                    {
                        if (size > max_size)
                        {
                            max_size = size;
                            data->bsq.x = x;
                            data->bsq.y = y;
                            data->bsq.size = size;
                        }
                    }
                    else
                        break;
                    size++; // we checked square of size+1 for obstacles, now we increase size
                }
            }
        }
    }

    for (int i = data->bsq.y; i < data->bsq.y + data->bsq.size; i++)
        for (int j = data->bsq.x; j < data->bsq.x + data->bsq.size; j++)
            data->map[i][j] = FULL;
}

int main(int argc, char **argv)
{
    t_data data; //make a data structure to hold the map and the first line
    FILE *file; // file pointer to hold the file

    if (argc != 2)
    {
        fprintf(stderr, "Error: wrong number of arguments\n");
        return (1);
    }

    file = fopen(argv[1], "r"); // fopen opens the file name passed in in read mode
    if (!file)
    {
        fprintf(stderr, "Error: cannot open file\n");
        return (1);
    }

    if (!read_first_line(file, &data) || !read_map(file, &data))
    {
        fprintf(stderr, "map error\n");
        fclose(file);
        return (1);
    }
    try_position(&data);
    print_map(&data);
    fclose(file);
    return (0);
}