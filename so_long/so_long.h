#ifndef SO_LONG_H
#define SO_LONG_H

#include "MLX42.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Function prototype for drawing a line
void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, uint32_t color);

#endif // SO_LONG_H
