
/* Brian Bright
 * 0725379 
 * tychocel@u.washington.edu
 * 4/21/2017
 * Estimating pi using Nilakantha's infinite series
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

static double estimatePi(int n, double pipi);
static void pi_driver(uint64_t n);
static void Usage();
static double nila_to_nth(uint64_t n, double base);
int main(int argc, char* argv[])
{
	if(argc != 2)
		Usage(argv[0]);

	/* convert given n value to a 64 bit unsigned int */
	uint64_t bign;
	if((sscanf(argv[1], "%llu", (unsigned long long *) &bign) != 1) || (bign == 0))
		Usage();

	pi_driver(bign);
	return 1;
}

/* prints error message if program invoked incorrectly */
static void Usage(char *prog)
{
	fprintf(stderr,
			"usage: %s n, where n>=0. Prints pi estimated " \
			" to n terms of the Nilakantha series.\n", prog);
	exit(EXIT_FAILURE);
}

/*
 * drives the estimation of pi using the nilakantha series 
 */
static void pi_driver(uint64_t n)
{
	double est_pi;
	printf("\n");
	printf("Estimating pi using infinite series: \n");

	//	est_pi = estimatePi(n, 3.0);
	est_pi = nila_to_nth(n, 3.0);
	printf("guess is %.20f\n\n", est_pi);

	//printf("%d = n      precurser = %f      pipi = %f\n", n, precurser, pipi);		
	//printf("3 + (4/ (2 x 3 x 4)) ");
	//char sign = (precurser > 0) ? '+' : '-';
	//printf(" %c (4 / (%d x %d x %d))", sign, 2*n, (2*n)+1, (2*n)+2);
	
}
static double nila_to_nth(uint64_t n, double base)
{
	double expo;
	double precurser;
	while(n >= 1)
		{
			expo = (double)n + 1.0;
			precurser = pow(-1.0, expo);
			base += precurser * (4.0 / ((2*n) * ((2*n) + 1) * ((2*n) + 2)));
			n--;
		}
	return base;
}
/* 
 * recursively works through the nilakantha series of estimating pi
 * base case: n = 1
 * honestly the recursion method only works for n<2000, because 
 * it will use up all the stack size :-(
 */
static double estimatePi(int n, double pipi)
{
	double expo = (double)n + 1.0;
	double precurser = pow(-1.0, expo);	

	pipi += precurser * (4.0 / ((2*n) * ((2*n) + 1) * ((2*n) + 2)));

	if(n <= 1)
		{
			return pipi;
		}
	else
		{
			pipi = estimatePi(n-1, pipi);
			return pipi;
		}

}
