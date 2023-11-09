#include <stdio.h>

/* 華氏 -> 摂氏 */
main()
{
	float fahr, celcius;
	int step, lower, upper;

	step = 20;
	lower = 0;
	upper = 300;

	fahr = lower;

	while (fahr <= upper)
	{
		celcius = (5.0/9) * (fahr - 32);
		printf("%3.0f %6.1f\n", fahr, celcius);
		fahr += step;
	}
}
