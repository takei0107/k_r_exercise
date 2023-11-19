#include <stdio.h>

#define TABSTOP 4

void entab(int n);

main()
{
	entab(TABSTOP);
	return;
}

void entab(int n)
{
	int c, i;
	int nc, nspace;

	nc = nspace = 0;

	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == ' ')
		{
			nspace++;

			if (nc % n == 0)
			{
				if (nspace == n)
				{
					putchar('\t');
					nc = (nc - n) + 1;
				}
				else
				{
					for (i = 0; i < nspace; i++)
						putchar('_');
				}
				nspace = 0;
			}
		}	
		else if (c == '\n')
		{
			nc = nspace = 0;
			putchar(c);
		}
		else
		{
			if (nspace > 0)
			{
				for (i = 0; i < nspace; i++)
					putchar('_');

				nspace = 0;
			}
			
			putchar(c);
		}
	}
}
