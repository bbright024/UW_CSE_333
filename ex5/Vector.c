#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

/* VectorCreate - mallocs space for a vector_t struct and mallocs "n" space
 *        for the "arry" pointer in the vector_t struct. 
 */
vector_t VectorCreate(size_t n)
{
	vector_t v = (vector_t)malloc(sizeof(struct vector_t));

	if (v == NULL)
		return NULL;
	
	v->arry = (element_t*)malloc(n*sizeof(element_t));

	if(v->arry == NULL)
		return NULL;

	v->length = n;
	
	/* this assumes the user wants "ints" in their vector. will comment out. */
	/* 
	for(uint32_t i = 0; i < n; i++)
		{
			int *x = (int *)malloc(sizeof(int));
			if(x == NULL)
				return NULL;
			*x = 0;
			VectorSet(v, i, x, NULL);
		}
    */
	
	return v;
}


/* VectorFree - frees the given vector_t 
 */
void VectorFree(vector_t v)
{
	assert(v != NULL);
	free(v->arry);
	free(v);
	
}


/* VectorSet - sets the 
 *
 */
// Sets the nth element of v to be e.  Returns the previous nth element_t in prev.
// Returns true iff successful.  Assumes v != NULL.
bool VectorSet(vector_t v, uint32_t index, element_t e, element_t *prev)
{
	assert(v != NULL);

	prev = v->arry[index];
	v->arry[index] = e;

	return true;
	

}

// Returns the element at the given index within v.  Assumes v != NULL.
element_t VectorGet(vector_t v, uint32_t index)
{
	assert(v != NULL);
	return v->arry[index];
	
}

// Returns the length of v.  Assumes v != NULL.
size_t VectorLength(vector_t v)
{
	assert(v != NULL);
	return v->length;	
}

