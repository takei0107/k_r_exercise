#include <stdio.h>

#define MAXLINE 100

int any(char s1[], char s2[]);
int getline(char s[], int lim);

int main()
{
	char s1[100];
	char s2[100];
	int result;

	while (getline(s1, MAXLINE) > 0)
	{
		
		getline(s2, MAXLINE);

		result = any(s1, s2);
		printf("%d\n", result);	
	}
}

int any(char s1[], char s2[])
{
	int i, j;
	int result = -1;
	for (i = 0; s2[i] != '\0'; i++)
		for (j = 0; s1[j] != '\0'; j++)
			if (s1[j] == s2[i])
				if (result == -1 || result > j)
					result = j;

	return result;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	/*
	if (c == '\n')
		s[i++] = c;
		*/

	s[i] = '\0';
	return i;
}
