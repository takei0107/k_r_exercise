#include <string.h>
#include <stdio.h>

void itoa(int n, char s[], int digits);
void reverse(char s[]);

void itoa(int n, char s[], int digits)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;

	do {
		s[i++] = n % 10 + '0';
	} while((n /= 10) > 0);

	if (sign < 0)
		digits--;
	while (i < digits)
	{
		s[i++] = '0';
	}

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
	itoa(123, s, 8);
	printf("%s\n", s);

	itoa(999999999, s, 8);
	printf("%s\n", s);

	itoa(-123, s, 8);
	printf("%s\n", s);

	itoa(-999999999, s, 8);
	printf("%s\n", s);
}

