#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

main()
{
	float fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));

}
