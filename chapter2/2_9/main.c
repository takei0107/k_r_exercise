#include <stdio.h>

int bitcount(unsigned int x);

int bitcount(unsigned int x)
{
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		b++;

	return b;
}

int main()
{
	printf("%d\n", bitcount(0));
	printf("%d\n", bitcount(1));
	printf("%d\n", bitcount(5));
	printf("%d\n", bitcount(7));
	printf("%d\n", bitcount(16));
}
