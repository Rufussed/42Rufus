/* 
Question 1 - TSP
 Write a program that will read a set of city coordinates 
 under the form '%f, %f\n' from the stdint and will print 
 the length of the shortest possible path containing all 
 these cities under the form %.2f
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the distance between two points
float	distance(float x0, float y0, float x1, float y1)
{
	float	diff_x = x1 - x0;
	float	diff_y = y1 - y0;

	return (sqrtf(diff_x * diff_x + diff_y * diff_y));
}

// Helper function to swap two integers
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Function to calculate the total distance for a given path
float	path_distance(float *coords, int *path, int num_cities)
{
	float	total_distance = 0.0;
	int		i;

	i = 0;
	while (i < num_cities - 1)
	{
		total_distance += distance(
			coords[2 * path[i]], coords[2 * path[i] + 1],
			coords[2 * path[i + 1]], coords[2 * path[i + 1] + 1]);
		i++;
	}
	total_distance += distance(
		coords[2 * path[num_cities - 1]], coords[2 * path[num_cities - 1] + 1],
		coords[2 * path[0]], coords[2 * path[0] + 1]);
	return (total_distance);
}

// Recursive function to find all permutations of paths
void	permute(float *coords, int *path, int start, int num_cities, float *min_dist)
{
	int	i;
	float	current_dist;

	if (start == num_cities)
	{
		current_dist = path_distance(coords, path, num_cities);
		if (current_dist < *min_dist || *min_dist == -1.0)
			*min_dist = current_dist;
		return ;
	}
	i = start;
	while (i < num_cities)
	{
		swap(&path[start], &path[i]);
		permute(coords, path, start + 1, num_cities, min_dist);
		swap(&path[start], &path[i]);
		i++;
	}
}

// Function to read input and store coordinates
int	parse_input(float **coords, int *num_cities)
{
	char	buffer[32];
	float	x, y;
	int		i = 0;

	*coords = NULL;
	while (fgets(buffer, sizeof(buffer), stdin))
	{
		if (sscanf(buffer, "%f, %f", &x, &y) != 2)
			return (-1);
		*coords = realloc(*coords, sizeof(float) * 2 * (i + 1));
		if (!*coords)
			return (-1);
		(*coords)[2 * i] = x;
		(*coords)[2 * i + 1] = y;
		i++;
	}
	*num_cities = i;
	return (i > 0 ? 0 : -1);
}

// Main function
int	main(void)
{
	float	*coords;
	int		*path;
	int		num_cities;
	float	min_dist;

	coords = NULL;
	if (parse_input(&coords, &num_cities) == -1 || num_cities > 11)
	{
		free(coords);
		return (1);
	}
	path = malloc(sizeof(int) * num_cities);
	if (!path)
	{
		free(coords);
		return (1);
	}
	for (int i = 0; i < num_cities; i++)
		path[i] = i;
	min_dist = -1.0;
	permute(coords, path, 0, num_cities, &min_dist);
	printf("%.2f\n", min_dist);
	free(coords);
	free(path);
	return (0);
}
