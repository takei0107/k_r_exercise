#include <stdio.h>

int getline(char s[], int lim)
{
	int i = 0;
	int c;
	while(1)
		if (i < lim - 1)
			if ((c = getchar()) != '\n')
				if (c != EOF)
					s[i++] = c;
				else
					break;
			else
				break;
		else
			break;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int main()
{
	char line[100];
	int lim = 100;
	while (getline(line, lim) > 0)
		printf("%s", line);
}
