// Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_life
{
    int *map;
    int *new_map;
    int width;
    int height;
    char *setup;
    int max_iterations;
} t_life;

void print_map(t_life *life)
{
    for (int y = 0; y < life->height; y++)
    {
        for (int x = 0; x < life->width; x++)
        {
            int cell = life->map[y * life->width + x];
            putchar(cell ? 'O' : ' ');
        }
        putchar('\n');
    }
}

void setup_cells(t_life *life)
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
        case 'a' : x--; break;
        case 'd' : x++; break;
        case 'x' : draw = !draw; break;
        default: break;
        }
        if (draw)
            life->map[y * life->width + x] = 1;
        i++;
    }
}

void init_life(t_life *life, char **argv, char *setup)
{
    life->width = atoi(argv[1]);
    life->height = atoi(argv[2]);
    life->max_iterations = atoi(argv[3]);
    life->setup = setup;
    life->map = calloc(life->width * life->height, sizeof(int));
    life->new_map = calloc(life->width * life->height, sizeof(int));
    setup_cells(life);
}

void free_life(t_life *life)
{
    free(life->map);
    free(life->new_map);
    free(life);
}

void detect_boundaries_count(t_life *life, int nx, int ny, int *count)
{
    if (nx >= 0 && nx < life->width && ny >= 0 && ny < life->height)
        if (life->map[ny * life->width + nx] == 1)
            *count = *count + 1;
}

int count_neighbours(t_life *life, int x, int y)
{
    int count = 0;
    for (int ny = y-1; ny <= y+1; ny++)
        for (int nx = x-1; nx <= x+1; nx++)
            if (!(ny ==y && nx == x)) // not midpoint
                detect_boundaries_count(life, nx, ny, &count);
    return count;    
}

void grow_life(t_life *life)
{
    for (int iterations = 0; iterations < life->max_iterations; iterations++)
    {
        for(int y = 0; y < life->height; y++)
        {
            for(int x = 0; x < life->width; x++)
            {
                int neighbours = count_neighbours(life, x, y);
                int alive = life->map[y * life->width + x];
                if ((alive && (neighbours == 2 || neighbours == 3)) || (!alive && neighbours == 3))
                    life->new_map[y * life->width + x] = 1;
                else life->new_map[y * life->width + x] = 0;
            }            
        }
        int *temp = life->map;
        life->map = life->new_map;
        life->new_map = temp;
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;
    char buffer[1024];
    int bytes_read = read(0, buffer, 1024);
    buffer[bytes_read] = '\0';
    t_life *life = calloc(1, sizeof(t_life));
    init_life(life, argv, buffer);
    grow_life(life);
    print_map(life);
    free(life);
    return 0;    
}