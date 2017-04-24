#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
	int64_t x;
	int64_t y;
	int64_t z;
} Point3d;

typedef Point3d* location;

location allocate_point(int64_t x, int64_t y, int64_t z);

int main(int argc, char *argv[])
{
	location goal = allocate_point(1, 2, 3);

	printf("this point is at (%lu, %lu, %lu) \n", goal->x, goal->y, goal->z);

	free(goal);
	
	return 0;
}

location allocate_point(int64_t x, int64_t y, int64_t z)
{
	location new_point = malloc(sizeof(Point3d));
	new_point->x  = x;
	new_point->y = y;
	new_point->z = z;
	return new_point;
}
	
