#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ((len = getline(line, MAXLINE)) > 0)
	{
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
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
