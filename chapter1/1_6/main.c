#include <stdio.h>

main()
{
	int d;

	while (d = getchar() != EOF)
		printf("%d\n", d);
	printf("%d\n", d);
}
