#include <stdio.h>
#include <stdlib.h>
#include "nthprime.h"

int main(int argc, char *argv[])
{
	
	uint64_t desired;
	sscanf(argv[1], "%lu", &desired);
	printf("the %lu prime is %lu \n", desired, nth_prime(desired));
	return 0;
}
