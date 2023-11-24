#include <stdio.h>

unsigned getbits(unsigned int x, int p, int n);
unsigned setbits(unsigned int x, int p, int n, unsigned int y);

unsigned rightrot(unsigned int x, int n);

int main()
{
	printf("%d\n", rightrot(12,5));
}

unsigned rightrot(unsigned int x, int n)
{
	int right, left;

	right = x >> n;
	left = getbits(x, n - 1, n) << 8 - n;

	printf("right:%b\n", right);
	printf("left :%b\n", left);

	return right | left;
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
