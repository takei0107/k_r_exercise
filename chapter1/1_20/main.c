#include <stdio.h>

#define TABSTOP 4

void detab(int n);

main()
{
	detab(TABSTOP);
	return;
}

void detab(int n)
{
	int c;
	int nc, i, r;

	nc = 0;

	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\t')
		{
			r = n - (nc % n) + 1;
			if (r == n + 1)
				r = 1;
			for (i = 0; i < r; i++)
			{
				putchar(' ');
			}
			nc += r - 1;
		}
		else if ( c == '\n')
		{
			/*printf(" %d\n", j);*/
			nc = 0;
			putchar('\n');
		}
		else
			putchar(c);
	}
}
