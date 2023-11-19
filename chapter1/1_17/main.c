#include <stdio.h>

#define MAXLINE 20

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len, overlen;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	overlen = 0;

	while ((len = getline(line, MAXLINE)) > 0)
		if (len == MAXLINE - 1)
		{
			if (line[len - 1] != '\n')
			{
				overlen += len;
				printf("%s", line);
			}
		}
		else if (overlen > 0)
		{
			printf("%s", line);
			overlen = 0;
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

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
