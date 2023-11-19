#include <stdio.h>

main()
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
}

int power(int base, int n)
{
	int p, i;

	p = 1;

	for (i = 1; i <= n; i++)
		p *= base;

	return p;
}
