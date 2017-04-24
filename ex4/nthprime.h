#ifndef _EX4_GETPRIME_H_
#define _EX4_GETPRIME_H_

#include <stdint.h>

/* 
 * returns the n'th prime number 
 * n must be > 0.
 * nth_prime(1) ---> 2
 * nth_prime(2) ---> 3
 * nth_prime(3) ---> 5
 * nth_prime(4) ---> 7
 */
uint64_t nth_prime(uint16_t n);
#endif
