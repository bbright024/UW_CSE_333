#include <stdio.h>
#include <stdlib.h>
#include "nthprime.h"

uint64_t nth_prime(uint16_t n)
{
	uint16_t i = n;
	uint16_t j = 3;
	uint64_t k;

	uint64_t maximum = ~0;
	uint16_t is_a_prime = 1;
	uint64_t nth = 2;

	/* get 2 out of the way */
	if (n == 1)
		return 2;
	i--;
	printf("max is %lu  \n", maximum);
	while(i > 0 && j < maximum )
		{
			for(k = 2; k < j; k++)
				{
					/* 0 if k is a multiple of j */
					if(!(j%k))
						{
							is_a_prime = 0;
							break;
						}
				}

			/* if multiples is zero, j is a prime */

			if(is_a_prime)
				{
					i--;
					nth = j;
					printf("a prime is %lu\n", nth);
				}

			/* skip even numbers */
			j += 2;
			is_a_prime = 1;
		}

	return nth;	

}
