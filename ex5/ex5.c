#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "Vector.h"

/* Helper functions (assume not buggy)  */
// Returns a copy of arry with new length newLen.  If newLen < oldLen
// then the returned array is clipped.  If newLen > oldLen, then the
// resulting array will be padded with NULL elements.
static void place_ints(vector_t v, uint32_t n);
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen);
static void PrintIntVector(vector_t v);

#define N 10 // Test vector length.

int main(int argc, char *argv[]) {
	uint32_t i;
	vector_t v = VectorCreate(4);
	srand(time(NULL));
	
	if (v == NULL)
		return EXIT_FAILURE;

	/* check if enough space was allocated before assigning values.  should put in own method. */
	if(N > v->length)
		{
			size_t new_length = N;

			v->arry = ResizeArray(v->arry, v->length, new_length);
			v->length = new_length;
		}
	
	/* place elements inside the "v" struct */
	place_ints(v, N);
	
	PrintIntVector(v);
	for(i = 0; i < N; i++)
		{
			free(v->arry[i]);
		}
	VectorFree(v);
	return EXIT_SUCCESS;
}
static void place_ints(vector_t v, uint32_t n)
{
	for (uint32_t i = 0; i < n; ++i) {
		int *x = (int*)malloc(sizeof(int));
		*x = rand() % 100;
		element_t old;
		if(VectorSet(v, i, x, &old) == false)
			break;
	}
}
/* PrintIntVector - prints the elements in "v"
 *
 */
static void PrintIntVector(vector_t v) {
	uint32_t i;
	size_t length;
	assert(v != NULL);

	length = VectorLength(v);
	printf("%lu\n", length);

	if (length > 0) {
		printf("[%d", *((int*)VectorGet(v, 0)));
		for (i = 1; i < length; ++i)
			printf(",%d", *((int*)VectorGet(v, i)));
		printf("]\n");
	}
}
/* ResizeArray - malloc a new element_t array of length "newLen"
 *               and copy in data from "arry", initializing to zero
 *               any extra space
 */
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen) {
	uint32_t i;
	size_t copyLen = oldLen > newLen ? newLen : oldLen;
	element_t *newArry;

	assert(arry != NULL);

	newArry = (element_t*)malloc(newLen*sizeof(element_t));

	if (newArry == NULL)
		return NULL; 			/* out of memory */

	/* copy previous values */
	for (i = 0; i < copyLen; ++i)
		newArry[i] = arry[i];

	/* null init any remaining elements */
	if(newLen > oldLen)
		{
			for (; i < newLen; ++i)
				newArry[i] = NULL;
		}
	free(arry);
	return newArry;
}
