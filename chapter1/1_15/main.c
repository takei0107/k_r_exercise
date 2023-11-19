#include <stdio.h>

/* 華氏 -> 摂氏 */
main()
{
	int fahr, celcius;
	int step, lower, upper;

	step = 20;
	lower = 0;
	upper = 300;

	fahr = lower;

	while (fahr <= upper)
	{
		printf("%d\t%d\n", fahr, to_celcius(fahr));
		fahr += step;
	}
}

int to_celcius(int fahr)
{
	return 5 * (fahr - 32) / 9;
}
