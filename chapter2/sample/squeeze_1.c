#include <stdio.h>

#define LINEMAX 100

int getline(char s[], int lim);
void squeeze(char s[], int c);

int main()
{
	char line[LINEMAX];

	int c;

	while (getline(line, LINEMAX) > 0)
	{
		c = getchar();	
		squeeze(line, c);
		printf("%s", line);

		while ((c = getchar()) != EOF && c != '\n')
			;
	}
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

void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
