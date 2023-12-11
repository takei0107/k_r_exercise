#include <stdio.h>

#define MAX 100

void itoa(int n, char s[])
{
	int i = 0;

	if (n < 0)
	{
		s[i++] = '-';
		n = -n;
	}

	s[i] = '\0';
}

int main()
{
	char s[MAX];

	itoa(123, s);
	printf("%s\n", s);

	itoa(-456, s);
	printf("%s\n", s);
}
