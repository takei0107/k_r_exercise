#include <stdio.h>

/*摂氏 -> 華氏 */
main()
{
	float fahr, celcius;
	int step, lower, upper;

	step = 20;
	lower = 0;
	upper = 300;

	celcius = lower;

	printf("celcius  fahr\n");
	while (celcius <= upper)
	{
		fahr = (9.0/5.0) * celcius + 32.0;
		printf("%7.0f %5.1f\n", celcius, fahr);
		celcius += step;
	}
}
