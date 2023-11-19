#include <stdio.h>

#define MAX_COUNT 9

main()
{
	int c, i, j;
	int nwhite, nother;
	int ndigits[10];

	nwhite = nother = 0;

	for (i = 0; i < 10; i++)
		ndigits[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			ndigits[c - '0']++;
			if (ndigits[c - '0'] > MAX_COUNT)
				ndigits[c - '0'] = MAX_COUNT;
		}
		else if (c == ' ' || c == '\n' || c == '\t')
		{
			nwhite++;
			if (nwhite > MAX_COUNT)
				nwhite = MAX_COUNT;
		}
		else
		{
			nother++;
			if (nother > MAX_COUNT)
				nother = MAX_COUNT;
		}

		if (c == '\n')
		{
			for (i = 0; i < 10; i++)
			{
				if (i == MAX_COUNT)
					printf("   %2d+|", i);
				else
					printf("    %2d|", i);

				for (j = 0; j <= MAX_COUNT; j++)
					if (j == ndigits[i])
						printf(" * ");
					else
						printf("   ");
				putchar('\n');

			}

			printf("nwhite|");
			for (i = 0; i <= MAX_COUNT; i++)
				if (i == nwhite)
					printf(" * ");
				else
					printf("   ");
			putchar('\n');

			printf("nother|");
			for (i = 0; i <= MAX_COUNT; i++)
				if (i == nother)
					printf(" * ");
				else
					printf("   ");
			putchar('\n');

			printf("-------------------------------------\n");
			printf("        0  1  2  3  4  5  6  7  8  9 \n");
			putchar('\n');

			nwhite = nother = 0;

			for (i = 0; i < 10; i++)
				ndigits[i] = 0;
		}
	}
		

}
