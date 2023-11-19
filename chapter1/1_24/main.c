#include <stdio.h>

#define STRMAX 100000

#define CODE 0
#define IN_STRING 1
#define IN_CHAR 2

void uncomment(char str[]);
void skip(int prechar);

int main()
{
	int i, state;
	char str[STRMAX], c;

	int parenthes, braces, square;

	uncomment(str);

	state = CODE;
	parenthes = braces = square = 0;
	i = 0;

	while ((c = str[i++]) != '\0' && parenthes >= 0 && braces >= 0 && square >= 0)
	{
		if (c == '(' && state == CODE)
			parenthes++;
		else if (c == '{' && state == CODE)
			braces++;
		else if (c == '[' && state == CODE)
			square++;
		else if (c == ')' && state == CODE)
			parenthes--;
		else if (c == '}' && state == CODE)
			braces--;
		else if (c == ']' && state == CODE)
			square--;
		else if (c == '"' && state == CODE)
			state = IN_STRING;
		else if (c == '"' && state == IN_STRING)
			state = CODE;
		else if (c == '\'' && state == CODE)
			state = IN_CHAR;
		else if (c == '\'' && state == IN_CHAR)
			state = CODE;
	}

	printf("parenthes:%d\n", parenthes);
	printf("braces:%d\n", braces);
	printf("square:%d\n", square);
	if (parenthes != 0)
	{
		puts("()が不整合です。\n");
	}
	if (braces != 0)
	{
		puts("{}が不整合です。\n");
	}
	if (square != 0)
	{
		puts("[]が不整合です。\n");
	}
}

void uncomment(char str[])
{
	int c, i, state;

	i = 0;
	state = CODE;

	while ((c = getchar()) != EOF)
	{
		if (c == '/' && state == CODE)
		{
			skip(c);
			continue;
		}
		else if (c == '"' && state == CODE)
			state = IN_STRING;
		else if (c == '"' && state == IN_STRING)
			state = CODE;
		else if (c == '\'' && state == CODE)
			state = IN_CHAR;
		else if (c == '\'' && state == IN_CHAR)
			state = CODE;

		str[i++] = (char)c;
	}

	str[i] = '\0';

}

void skip(int prechar)
{
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c == '/' && prechar == '*')
			return;
		prechar = c;
	}
}
