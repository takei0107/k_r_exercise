#include <stdio.h>

#define MAX 100

int itoa(int n, char s[], int i)
{
	if (n < 0)
	{
		s[i++] = '-';
		n = -n;
	}

	if (n / 10)
		i = itoa(n/10, s, i);

	s[i++] = n % 10 + '0';
	s[i] = '\0';

	return i;
}

int main()
{
	char s[MAX];

	itoa(123, s, 0);
	printf("%s\n", s);

	itoa(-456, s, 0);
	printf("%s\n", s);
}
