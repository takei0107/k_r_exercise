#include <stdio.h>

#define MAXLINE 100

int htoi(char s[]);
int getline(char line[], int lim);

int main()
{
	char s[MAXLINE];
	
	while (getline(s, MAXLINE) > 0)
		printf("%d\n", htoi(s));

}

int htoi(char s[])
{
	int p = 0;
	int result = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		p = 2;	

	while(s[p] != '\0')
	{
		if (s[p] >= '0' && s[p] <= '9')
			result = (result * 16) + (s[p] - '0');
		else if (s[p] >= 'a' && s[p] <= 'f')
			result = (result * 16) + 10 + (s[p] - 'a');
		else if(s[p] >= 'A' && s[p] <= 'F')
			result = (result * 16) + 10 + (s[p] - 'A');

		p++;
	}

	return result;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;	

	if (c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}
