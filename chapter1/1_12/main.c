#include <stdio.h>

#define OUT 0
#define IN 1

main()
{
	int c;
	int state;

	state = OUT;

	while ((c = getchar()) != EOF)
		if (c == '\n' || c == '\t' || c == ' ')
		{
			if (state == IN)
				putchar('\n');

			state = OUT;
		}
		else
		{
			if (state == OUT)
				state = IN;
			putchar(c);
		}
}
