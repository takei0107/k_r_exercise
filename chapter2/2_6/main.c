#include <stdio.h>

unsigned getbits(unsigned int x, int p, int n);
unsigned setbits(unsigned int x, int p, int n, unsigned int y);

int main()
{
	printf("%d\n", setbits(7, 6, 3, 5));
	printf("%d\n", setbits(31, 4, 2, 5));
}

unsigned getbits(unsigned int x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned int x, int p, int n, unsigned int y)
{
	int yy, mask, masked;

	/* yの右端nビット*/
	yy = getbits(y, n - 1, n);

	/* マスクを作ってセットしたいビットは0,それ以外はxのビットを残す */
	mask = ~((~(~0 << n)) << p - n + 1);
	masked = x & mask;

	return masked | (yy << p - n + 1);
}
