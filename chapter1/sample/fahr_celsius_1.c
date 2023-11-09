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
		celcius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celcius);
		fahr += step;
	}
}
