#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_life{
    int map1[500][1000];
    int map2[500][1000];
    int width, height, iterations;
} Life;

void init_life(Life *life, char** argv, char* setup)
{
    life->width = atoi(argv[1]);  life->height = atoi(argv[2]);  life->iterations = atoi(argv[3]);
   
    int i = 0; int x = 0; int y = 0; int draw=0;
    while (setup[i])
    {
        switch (setup[i]) {
            case 'w': y--; break;
            case 's': y++; break;
            case 'a': x--; break;
            case 'd': x++; break;
            case 'x': draw = !draw; break;
        }
        if (draw) life->map1[y][x] = 1;
        i++;
    }
}

void print_map(Life *life)
{
    for(int y = 0; y < life->height; y++)
    {
        for(int x = 0; x < life->width; x++)
            putchar(life->map1[y][x] ? 'O' : ' ');
        putchar('\n');
    }
}

int count_neighbours(Life *life, int y, int x)
{
    int neighbours = 0;
    for(int ny = y-1; ny <= y+1; ny++)
    {
        for(int nx = x-1; nx <= x+1; nx++)
        {
            if (ny >= 0 && ny < life->height 
                && nx >= 0 && nx< life->width 
                && (ny != y || nx != x)
                && life->map1[ny][nx])
                neighbours++;
        }
    }
    return neighbours;
}

void try_position(Life *life)
{
    for (int i = 0; i < life->iterations ; i++)
    {
        for(int y = 0; y < life->height; y++)
            for(int x = 0; x < life->width; x++) {
                int neighbours = count_neighbours(life, y, x);
                int alive = life->map1[y][x];
                if((alive && (neighbours == 2 || neighbours == 3)) || (!alive && neighbours == 3))
                    life->map2[y][x] = 1;
                else
                    life->map2[y][x] = 0;
            }
        for(int y = 0; y < life->height; y++)
            for(int x = 0; x < life->width; x++)
                life->map1[y][x] =  life->map2[y][x];
    }
}

int main(int argc, char** argv)
{
    char buffer[1024];
    int bytes_read;
    bytes_read = read(0, buffer, 1024);
    if (bytes_read < 0 || argc != 4)
        return 1;
    buffer[bytes_read] = '\0';
    Life *life;
    life = calloc(1, sizeof(Life));
    init_life(life, argv, buffer);
    try_position(life);
    print_map(life);
    free(life);
    return 0;
}
