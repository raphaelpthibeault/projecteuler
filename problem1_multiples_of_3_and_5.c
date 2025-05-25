#include <stdio.h>
#include <stdint.h>

/* Problem statement:
 * https://projecteuler.net/problem=1
 * Find the sum of all the multiples of 3 or 5 below some N (N=1000 in link)
 * */

uint64_t
main(int argc, char *argv[])
{
	size_t N, num_threes, num_fives, num_fifteens, answer;

	sscanf(argv[1], "%lu", &N);

	num_threes = (N-1)/3;
	num_fives = (N-1)/5;
	num_fifteens = (N-1)/15;

	answer = 
		3 * (num_threes*(num_threes+1)/2) +
		5 * (num_fives*(num_fives+1)/2) -
		15 * (num_fifteens*(num_fifteens+1)/2);

	printf("Sum of all the multiples of 3 or 5 below %lu: %lu\n", N, answer);

	return 0;
}
