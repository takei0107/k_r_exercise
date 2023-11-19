#include <stdio.h>

#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int c;
	int len;
	int max;
	int skip;
	char line[MAXLINE];
	/*char longest[MAXLINE];*/

	skip = 0;
	max = 0;

	while ((len = getline(line, MAXLINE)) > 0)

		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n')
		{
			printf("%2d %s\n", len, line);
			while((c = getchar()) != EOF && c != '\n')
				;
		}
		else if (line[len - 1] == '\n')
			printf("%2d %s", len, line);
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
