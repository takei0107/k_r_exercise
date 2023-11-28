#include <stdio.h>

#define MAXLINE 100

#define UNESCAPED 0
#define ESCAPED 1

int getline(char s[], int lim);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
	char s[MAXLINE], t[MAXLINE];
	while (getline(s, MAXLINE) > 0)
	{
		/*
		escape(s, t);
		printf("%s\n", t);
		*/

		unescape(s, t);
		printf("%s\n", t);
				
	}
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}

void escape(char s[], char t[])
{
	int i, j;
	char c;

	i = j = 0;
	while ((c = s[i++]) != '\0')
	{
		switch(c) {
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			default:
				t[j++] = c;
				break;
		}
	}

	t[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i, j;
	char c;

	int status = UNESCAPED;

	i = j = 0;
	while ((c = s[i++]) != '\0')
	{
		switch(c) {
			case '\\':
				switch (status) {
					case UNESCAPED:
						status = ESCAPED;
						break;
					case ESCAPED:
						status = UNESCAPED;
						t[j++] = c;
						break;
				}
				break;
			case 'n':
				switch (status) {
					case UNESCAPED:
						t[j++] = c;
						break;
					case ESCAPED:
						status = UNESCAPED;
						t[j++] = '\n';
						break;
				}
				break;
			case 't':
				switch (status) {
					case UNESCAPED:
						t[j++] = c;
						break;
					case ESCAPED:
						status = UNESCAPED;
						t[j++] = '\t';
						break;
				}
				break;
			default:
				switch (status) {
					case UNESCAPED:
						t[j++] = c;
						break;
					case ESCAPED:
						status = UNESCAPED;
						t[j++] = '\\';
						t[j++] = c;
						break;
				}
				break;

		}
	}

	t[j] = '\0';
}
