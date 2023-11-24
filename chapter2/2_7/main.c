#include <stdio.h>

unsigned getbits(unsigned int x, int p, int n);
unsigned setbits(unsigned int x, int p, int n, unsigned int y);
unsigned invert(unsigned int x, int p, int n);

int main()
{
	printf("%d\n", invert(111, 5, 3));
}

unsigned getbits(unsigned int x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned invert(unsigned int x, int p, int n)
{
	int y;
	y = ~(getbits(x, p, n));
	return setbits(x, p, n, y);
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
