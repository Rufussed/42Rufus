/*
Assignment name              : bsq
Expected files               : *.c *.h
Allowed functions and globals: malloc, calloc, realloc, free, fopen, fclose,
getline, fscanf, fputs, fprintf, stderr, stdout, stdin, errno*/

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"

enum states {  EMPTY = 0, OBSTACLE = 1, FULL = 2 };

typedef struct s_bsq {
    int x, y, size;
} t_bsq;

typedef struct 
{
    int x, y;
    t_bsq bsq;
    char empty, obstacle, full;
    int map [100][200];
} t_data;

int read_map(t_data *data, FILE *file)
{
    // Read parameters directly from the file stream
    if (fscanf(file, "%d%c%c%c\n", &data->y, &data->empty, &data->obstacle, &data->full) != 4 || data->y < 1)
    {
        return 0;
    }
    
    // Check for duplicate characters
    if (data->empty == data->obstacle || data->empty == data->full || data->obstacle == data->full)
    {
        return 0;
    }
    
    // Now read the map lines with getline
    char *line = NULL;
    size_t len = 0;
    int read;
    int y = 0;
    int x = 0;
    
    while ((read = getline(&line, &len, file)) > 0 && y < data->y)
    {
        for (int i = 0; i < read - 1; i++)
        {
            if (line[i] == data->empty) data->map[y][x] = EMPTY;
            else if (line[i] == data->obstacle) data->map[y][x] = OBSTACLE;
            else
            {
                free(line);
                return 0;
            }
            x++;
        }
        if (y == 0) data->x = x; //set the x dimension on first pass
        y++;
        x = 0;
    }
    
    free(line);
    
    if (y != data->y)
    {
        return 0;
    }
    return 1;
}
            
    
void print_map(t_data *data)
{
    //fprintf(stdout, "%d %c %c %c", data->y, data->empty, data->obstacle, data->full);
    for (int y = 0; y < data->y; y++)
    {
        for (int x = 0; x < data->x; x++)
        {
            switch (data->map[y][x])  {
             case EMPTY: fprintf(stdout, "%c", data->empty); break;
             case OBSTACLE: fprintf(stdout, "%c", data->obstacle); break;
             case FULL: fprintf(stdout, "%c", data->full); break;
            }
        }      
        fprintf(stdout, "\n");
    }
}

void try_positions(t_data *data)
{
    for (int y = 0; y < data->y; y++)
    {
        for (int x = 0; x < data->x; x++)
            {
                if (data->map[y][x]== EMPTY)
                {
                    int valid = 1;
                    for(int size = 1; y + size < data->y && x + size < data->x; size ++)
                    {
                        for (int i = 0; i < size && valid; i++)
                        {
                            if (data->map[y + size - 1][x + i] == OBSTACLE ||
                                data->map[y + i][x + size - 1] == OBSTACLE)
                                valid = 0;
                        }
                        if (valid && data->bsq.size < size) {
                            data->bsq.size = size;
                            data->bsq.x = x; data->bsq.y = y;
                        }
                    }
                    
                }
            }
    }
    for (int j = 0; j < data->bsq.size; j++)
        for (int i = 0; i < data->bsq.size; i++)
            data->map[data->bsq.y + j][data->bsq.x + i] = FULL;
}

int main(int argc, char **argv)
{
    t_data data;
    FILE *file;

    if (argc != 2)
        file = stdin;
    else
        file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Map error");
        return (1);
    }
    if(!read_map(&data, file))// || !read_map(&data, file)) 
    {
        fprintf(stderr, "Map error");
        if (file != stdin)
            fclose(file);
        return (1);
    }
    try_positions(&data);
    print_map(&data);
    if (file != stdin)
        fclose(file);
    return (0);

}
