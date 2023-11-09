#include <stdio.h>

#define OUT 0
#define IN 1

#define WORD_LEN_MAX 9
#define APPEALANCE_MAX 99

main()
{
	int i,j,c, wl;
	int nwords[WORD_LEN_MAX + 1], nlength[APPEALANCE_MAX + 1];
	int state;

	for (i = 0; i < WORD_LEN_MAX + 1; i++)
		nwords[i] = 0;

	for (i = 0; i < APPEALANCE_MAX + 1; i++)
		nlength[i] = 0;

	state = OUT;
	wl = 0;

	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				if (wl > WORD_LEN_MAX)
					wl = WORD_LEN_MAX;
				nwords[wl]++;
				if (nwords[wl] > APPEALANCE_MAX)
					nwords[wl] = APPEALANCE_MAX;
				wl = 0;
			}
			state = OUT;
		}
		else
		{
			if (state == OUT)
				state = IN;
			wl++;
		}

	for (i = APPEALANCE_MAX; i > 0; i--)
	{
		if (i == APPEALANCE_MAX)
			printf("%2d+", i);
		else
			printf("%2d ", i);
		printf(" | ");
		for (j = 1; j <= WORD_LEN_MAX; j++)
		{
			putchar(' ');
			if (nwords[j] == i)
				putchar('*');
			else
				putchar(' ');
			putchar(' ');
		}
		putchar('\n');
	}
	printf("---------------------------------\n");
	printf("       1  2  3  4  5  6  7  8  9+\n");
}
