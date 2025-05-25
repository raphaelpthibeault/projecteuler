#include <stdio.h>
#include <stdint.h>

int
main(int argc, char *argv[])
{
	// By considering the terms in the Fibonacci sequence whose values do not exceed N, find the sum of the even-valued terms.
	size_t N, k, j, tmp, sum;
	sscanf(argv[1], "%lu", &N);

	/* Fibonnaci number a_n = a_(n-1) + a_(n-2) 
	 * even fibs = 2, 8, 34, 144, 610, ...
	 * there's this pattern I noticed
	 * 2   = 2
	 * 8   = 4*2 (+ 0)
	 * 34  = 4*8 + 2
	 * 144 = 4*34 + 8
	 * 610 = 4*144 + 34
	 * where even fibs are a_n = 4 * a_(n-1) + a_(n-2)
	 **/
	k = 2, j = 0, sum = 0, tmp = 0;
	
	while (k <= N) {
		sum += k;	

		tmp = k;
		k = 4 * k + j;
		j = tmp;
	}

	printf("Sum of even Fibonacci numbers whose values do not exceed %lu: %lu\n", N, sum);

	return 0;
}
