#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char *argv[])
{
	// largest prime factor of N
	size_t N;
	size_t N_orig;
	sscanf(argv[1], "%lu", &N);
	N_orig = N;

	/* idea 1: start sqrt(N) and go down and find first prime factor
	 * */

	// use hardware sqrt for a scalar
	// __builtin_sqrt
	
	// implement a fast next square root function (or use GMP)
	// this is an opportunity for Knuth's Seminumerical book
	

	// or, the lazy way:

	long max = -1;
	while (N % 2 == 0) {
		max = 2;
		N >>= 1;
	}
	while (N % 3 == 0) {
		max = 3;
		N /= 3;
	}
	for (int i = 5; i <= sqrt(N); i += 6) {
		while (N % i == 0) {
			max = i;
			N = N / i;
		}
		while (N % (i+2) == 0) {
				max = i+2;
				N = N / (i+2);
		}
	}
	if (N > 4) { // odd bug
		max = N;
	}

	printf("Largest prime factor of '%lu': '%ld'\n", N_orig, max);

	return 0;
}

