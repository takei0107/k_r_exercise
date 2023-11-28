#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

void itoa(int n, char s[])
{
	int i, sign, tmp;

	if ((sign = n) < 0)
	{
		n = -n;
	}
	
	i = 0;
	do {
		tmp = n % 10;
		if (tmp < 0)
			tmp = -tmp;
		s[i++] = tmp + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main()
{
	char s[100];
	itoa(0, s);
	printf("%s\n", s);
	itoa(10, s);
	printf("%s\n", s);
	itoa(256, s);
	printf("%s\n", s);
	itoa(INT_MAX, s);
	printf("%s\n", s);
	itoa(INT_MIN, s);
	printf("%s\n", s);
}
