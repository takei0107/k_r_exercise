#include <stdio.h>
#include <string.h>

#define STRMAX 100

void squeeze(char s1[], char s2[]);

int main()
{
	char s1[STRMAX], s2[STRMAX];
	strcpy(s1, "hoge");
	strcpy(s2, "fuga");

	squeeze(s1, s2);
	printf("%s\n", s1);
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	int match;
	for (i = k = 0; s1[i] != '\0'; i++)
	{
		match = 0;
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				match = 1;
		if (!match)
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
				

}
