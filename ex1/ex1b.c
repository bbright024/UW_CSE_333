/* 
 * Insert sort, selection sort, and type printing in printf practice
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LEN (uint64_t)5
void insert_driver(uint64_t *origin, uint64_t *copy, uint64_t len);
void just_copy(uint64_t *origin, uint64_t *copy, uint64_t len);
void type_info(uint64_t x, uint64_t  origin[x], uint64_t  copy[x]);
void selection_sort(uint64_t x, uint64_t origin[x], uint64_t copy[x]);
void copy_driver(uint64_t x, uint64_t origin[x], uint64_t copy[x], uint64_t *copy2);
void print_two_arrays(uint64_t *origin, uint64_t *copy, uint64_t len);

void insert(uint64_t num, uint64_t *array, uint64_t len);
void copy_and_sort(uint64_t *source, uint64_t *dest, uint64_t length);

int main(int argc, char *argv[])
{
	uint64_t origin[MAX_LEN] = {5, 4, 3, 2, 1};
	uint64_t copy[MAX_LEN];
	uint64_t copy2[MAX_LEN];
	copy_driver(MAX_LEN, origin, copy, copy2);
	
	
	return 0;
}

void print_two_arrays(uint64_t *origin, uint64_t *copy, uint64_t len)
{
	uint64_t i;
	
	printf("\n");
	for(i = 0; i < len; i++)
		{
			printf(" %lu ", origin[i]);
		}
	printf("\n");
	for(i = 0; i < len; i++)
		{
			printf(" %lu ", copy[i]);
		}
	printf("\n");

}
void insert(uint64_t num, uint64_t *array, uint64_t len)
{
	uint64_t j = len;
	uint64_t replace;
	
	while(j > 0 && (num < array[j-1]))
		{
			replace = array[j-1];
			array[j-1] = num;
			array[j] = replace;
			j--;
		}
}

void insert_driver(uint64_t *origin, uint64_t *copy, uint64_t len)
{
	copy[0] = origin[0];
	unsigned int i;

	for(i = 0; i < len; i++)
		insert(origin[i], copy, i);
}
	
void just_copy(uint64_t *origin, uint64_t *copy, uint64_t len)
{

	unsigned int i = 0;
	for(i = 0; i < len; i++)
		{
			copy[i] = origin[i];
		}
}


/* choose which copy method to implement */
void copy_driver(uint64_t x, uint64_t  origin[x], uint64_t  copy[x], uint64_t *copy2)
{
	type_info(x, origin, copy);
	selection_sort(x, origin, copy);
	printf("\nSorted with selection sort: \n");
	print_two_arrays(origin, copy, MAX_LEN);
	printf("\n");

	just_copy(origin, copy, x);

	insert_driver(origin, copy2, x);
	
	printf("\nSorted with insert sort: \n");
	print_two_arrays(origin, copy2, MAX_LEN);
	

}
/* simple insertion sort */
void selection_sort(uint64_t x, uint64_t  origin[x], uint64_t  copy[x])
{
	uint64_t i;
	uint64_t j;
	
	just_copy(origin, copy, x);

	//	uint64_t  min = copy[0];
	uint64_t  left;
	uint64_t  right;
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

void type_info(uint64_t x, uint64_t  origin[x], uint64_t  copy[x])
{
	unsigned long long bytes = sizeof(origin[0]);
	unsigned long long ander = ((1 << (bytes*8)) - 1)-1 ;
	printf("\nmy type, uint64_t, is %zu bytes wide and the max value is %llu\n", sizeof(origin[0]), ander);
	
}
