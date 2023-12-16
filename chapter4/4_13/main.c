#include <stdio.h>
#include <string.h>

void reverse(char s[], int, int);

int main()
{
	char s1[] = "hoge";
	char s2[] = "ABCDE";

	reverse(s1, 0, strlen(s1) - 1);
	printf("%s\n", s1);

	reverse(s2, 0, strlen(s2) - 1);
	printf("%s\n", s2);
}

void reverse(char s[], int left, int right)
{
	char tmp;

	if (left > right)
		return;

	tmp = s[left];
	s[left] = s[right];
	s[right] = tmp;

	reverse(s, left+1, right-1);

	return;
}
