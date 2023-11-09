#include <stdio.h>

main()
{
	int c, lc;

	lc = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n')
			lc++;

	printf("%d\n", lc);
}
