#include <stdio.h>
/*
 * /
 */

/*
 *
 * コメントを除去するるプログラム
 *
 */

#define COMMENT "/* COMMENT IN CONSTANT */"

#define CODE 0
#define IN_STRING 1
#define IN_CHAR 2


char *comment = "/* comment in string */";

void skip(int prechar);

int/* aaa  */ main()
{
	int c, state;

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

		putchar(c);
	}


	return 0;
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
