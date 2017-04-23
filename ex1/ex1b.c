#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void copy_while_sort(int x, int16_t origin[x], int16_t copy[x]);
void copy_then_sort(int x, int16_t origin[x], int16_t copy[x]);
void copy_driver(int x, int16_t origin[x], int16_t copy[x]);

int main(int argc, char *argv[])
{
	int x = 5;
	int16_t origin[5] = {5, 4, 3, 2, 1};
	int16_t copy[x];

	copy_driver(x, origin, copy);

	int i;
	
	printf("\n");
	for(i = 0; i < x; i++)
		{
			printf(" %d ", origin[i]);
		}
	printf("\n");
	for(i = 0; i < x; i++)
		{
			printf(" %d ", copy[i]);
		}
	printf("\n");

	return 0;
}

/* choose which copy method to implement */
void copy_driver(int x, int16_t origin[x], int16_t copy[x])
{
	copy_while_sort(x, origin, copy);
	//	copy_then_sort(x, origin, copy);

	

}
/* simple insertion sort */
void copy_then_sort(int x, int16_t origin[x], int16_t copy[x])
{
	int i;
	int j;
	
	for(i = 0; i < x; i++)
		{
			copy[i] = origin[i];
		}

	//	int16_t min = copy[0];
	int16_t left;
	int16_t right;
	for(i = 0; i < x; i++)
		{
			left = copy[i];
			for(j = i + 1; j < x; j++)
				{
					right = copy[j];
					if(left > right)
						{
							copy[i] = right;
							copy[j] = left;
							left = right;
						}
				}
		}
	

	
	
}
/* changed my mind, had fun exploring max values of random types */
void copy_while_sort(int x, int16_t origin[x], int16_t copy[x])
{
	unsigned long long bytes = sizeof(origin[0]);
	unsigned long long ander = (1 << (bytes*8)) - 1 ;
	printf("\nmy type is %zu bytes wide and the max value is %llu\n", sizeof(origin[0]), ander);
	
}
