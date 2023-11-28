#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]);
int getline(char s[], int lim);

int main()
{
	char s1[MAXLINE], s2[MAXLINE];

	while (getline(s1, MAXLINE) > 0)
	{
		expand(s1, s2);
		printf("%s\n", s2);
	}
}

void expand(char s1[], char s2[])
{
	int i, j, k;
	char from, to;
	int start, end;

	char base;

	for (i = j = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == '-')
			if (i == 0)
				s2[j++] = '-';
			else if (i == (strlen(s1) - 1))
				s2[j++] = '-';
			else
			{
				from = s1[i - 1];
				to = s1[i + 1];
				printf("from:%c\n", from);
				printf("to  :%c\n", to);

				if (isdigit(from))
				{
					base = '0';
				} 
				else if (isalpha(from))
				{
					if (islower(from))
					{
						base = 'a';
					}
					else
					{
						base = 'A';
					}
				}

				start = from - base;
				end = to - base;

				for (k = start; k <= end; k++)
					s2[j++] = base + k;
			}
	}
	s2[j] = '\0';
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}
