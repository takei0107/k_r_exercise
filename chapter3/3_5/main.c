#include <string.h>
#include <stdio.h>

void itoa(unsigned int n, char s[], int b);
void reverse(char s[]);

void itoa(unsigned int n, char s[], int b)
{
	int i;
	unsigned int d;
	char c;

	i = 0;

	do {
		d = n % b;	
		if (d < 10)
			s[i++] = d + '0';
		else
		{
			c = d - 10 + 'a';
			s[i++] = c;
		}
	} while ((n /= b) > 0);

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

	itoa(8, s, 16);
	printf("%s\n", s);

	itoa(10, s, 16);
	printf("%s\n", s);

	itoa(32, s, 16);
	printf("%s\n", s);

	itoa(255, s, 16);
	printf("%s\n", s);

	itoa(256, s, 16);
	printf("%s\n", s);

	itoa(10, s, 8);
	printf("%s\n", s);

	itoa(255, s, 8);
	printf("%s\n", s);

	itoa(256, s, 8);
	printf("%s\n", s);
}
