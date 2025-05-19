#ifndef LIFE_H
#define LIFE_H
#include <stdio.h>

typedef struct 
{
    int *map;
    int *new_map;
    int width;
    int height;
    char *setup;
    int max_iterations;
} life;



#endif