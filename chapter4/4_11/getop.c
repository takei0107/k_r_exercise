#include <stdio.h>
#include <ctype.h>

#include "calc.h"

#define BUFSIZE 100

int getop(char s[])
{
	int i, c;

	static char buf[BUFSIZE];
	static int bufp = 0;

	s[0] = c = (bufp > 0) ? buf[--bufp] : getchar();
	while (c == ' ' || c == '\t')
		s[0] = c = (bufp > 0) ? buf[--bufp] : getchar();

	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;

	i = 0;

	if (isdigit(c))
	{
		s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar();
		while (isdigit(c))
			s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar();
	}

	if (c == '.')
	{
		s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar();
		while (isdigit(c))
			s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar();
	}

	s[i] = '\0';

	if (c != EOF)
		buf[bufp++] = c;

	return NUMBER;
}

