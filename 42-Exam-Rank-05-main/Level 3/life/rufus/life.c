// Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 500

typedef struct s_life
{
    int map1[MAX_HEIGHT][MAX_WIDTH];
    int map2[MAX_HEIGHT][MAX_WIDTH];
    int width;
    int height;
    char *setup;
    int iterations;
} Life;

void print_map(Life *life)
{
    for (int y = 0; y < life->height; y++)
    {
        for (int x = 0; x < life->width; x++)
        {
            putchar(life->map1[y][x] ? 'O' : ' '); //if its true (1) print O else print space
        }
        putchar('\n');
    }
}

void setup_cells(Life *life)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int draw = 0;
    while (life->setup[i] != '\0')
    {
        switch(life->setup[i]) {
        case 'w': y--; break;
        case 's': y++; break;
        case 'a': x--; break;
        case 'd': x++; break;
        case 'x': draw = !draw; break;
        default: break;
        }
        if (draw)
            life->map1[y][x] = 1;
        i++;
    }
}

void init_life(Life *life, char **argv, char *setup)
{
    life->width = atoi(argv[1]);
    life->height = atoi(argv[2]);
    life->iterations = atoi(argv[3]);
    life->setup = setup;
    setup_cells(life);
}

void detect_boundaries_count(Life *life, int nx, int ny, int *count)
{
    if (nx >= 0 && nx < life->width && ny >= 0 && ny < life->height)
        if (life->map1[ny][nx] == 1)
            *count = *count + 1;
}

int count_neighbours(Life *life, int x, int y)
{
    int count = 0;
    for (int ny = y-1; ny <= y+1; ny++)
        for (int nx = x-1; nx <= x+1; nx++)
            if (!(ny ==y && nx == x)) // not midpoint
                detect_boundaries_count(life, nx, ny, &count);
    return count;    
}

void grow_life(Life *life)
{
    for (int i = 0; i < life->iterations; i++)
    {
        for(int y = 0; y < life->height; y++)
        {
            for(int x = 0; x < life->width; x++)
            {
                int neighbours = count_neighbours(life, x, y);
                int alive = life->map1[y][x]; //if cell contain 1 (true) then its alive
                if ((alive && (neighbours == 2 || neighbours == 3)) || (!alive && neighbours == 3))
                    life->map2[y][x] = 1; //lives
                else 
                    life->map2[y][x] = 0; //dies
            }            
        }
        for(int y = 0; y < life->height; y++) // copy new map to old map cell by cell (since we are not allocating seperately)
            for(int x = 0; x < life->width; x++)
                life->map1[y][x] = life->map2[y][x];
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;
    char buffer[1024];
    int bytes_read = read(0, buffer, 1024);
    buffer[bytes_read] = '\0';
    Life *life = calloc(1, sizeof(Life));
    init_life(life, argv, buffer);
    grow_life(life);
    print_map(life);
    free(life);    
    return 0;    
}
