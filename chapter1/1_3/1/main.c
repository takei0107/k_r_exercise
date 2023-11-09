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

	printf("fahr celcius\n");
	while (fahr <= upper)
	{
		celcius = (5.0/9) * (fahr - 32);
		printf("%4.0f %7.1f\n", fahr, celcius);
		fahr += step;
	}
}
