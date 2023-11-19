#include <stdio.h>

#define FOLD_N 10

int getnchar(char s[], int n);
void copy(char to[], char from[]);
void reverse(char s[]);

main()
{
	int i, len, nwhite;
	char s[FOLD_N];
	char rev[FOLD_N];

	while((len = getnchar(s , FOLD_N)) > 0)
	{
		nwhite = 0;
		if (len < FOLD_N - 1)
			printf("%s", s);
		else
		{
			if (s[len - 1] != ' ' && s[len - 1] != '\t')
			{
				printf("%s", s);
				if (s[len - 1] != '\n')
					putchar('\n');
			}
			else
			{
				copy(rev, s);
				reverse(rev);

				for (i = 0; i < len && (rev[i] == ' ' || rev[i] == '\t'); i++)
						nwhite++;

				for (i = 0; i < len - nwhite; i++)
					putchar(s[i]);

				if (nwhite > 0)
				{
					putchar('\n');
					for (i = len - nwhite; i < len; i++)
						putchar(s[i]);
				}

			}
				
		
		}

	}
}

int getnchar(char s[], int n)
{
	int c, i;
	for (i = 0; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
		
	if (c == '\n')
	{
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}

void reverse(char s[])
{
	int i, j, k;
	char tmp;
	for (i = 0; s[i] != '\n' && s[i] != '\0'; i++)
		;

	for (j = i - 1, k = 0; j > k; j--, k++)
	{
		tmp = s[k];
		s[k] = s[j];
		s[j] = tmp;
	}	
}

