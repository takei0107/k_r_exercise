#include <stdio.h>

#define OUT 0
#define IN 1

main()
{
	int c;
	int nl, nw, nc;
	int state;

	nl = nw = nc = 0;
	state = OUT;

	while ((c = getchar()) != EOF)
	{
		nc++;

		if (c == '\n')
			nl++;
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			nw++;
		}
	}

	printf("%d %d %d\n", nl, nw, nc);
}
