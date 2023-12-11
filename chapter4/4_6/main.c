#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define VARIABLE_POP '1'
#define VARIABLE_PUSH '2'

int getop(char []);
void push(double);
double pop(void);

int main()
{
	int type, mod, i;
	double op2;
	char s[MAXOP];

	double vars[26];
	double last_printed = 0;

	for (i = 0; i < 26; i++)
		vars[i] = 0;

	while ((type = getop(s)) != EOF)
	{
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0)
					push(pop() / op2);
				else
					printf("error: zero divisior\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0)
				{
					mod = (int)pop() % (int)op2;
					push((double)mod);
				}
				else
					printf("error: zefo divisior\n");
				break;
			case VARIABLE_POP:
				vars[s[0] - 'a'] = pop();
				break;
			case VARIABLE_PUSH:
				if (s[0] == '#')
					push(last_printed);
				else
					push(vars[s[0] - 'a']);
				break;
				/*
			case 'a': case 'b': case 'c': case 'd': case 'e':
			case 'f': case 'g': case 'h': case 'i': case 'j':
			case 'k': case 'l': case 'm': case 'n': case 'o':
			case 'p': case 'q': case 'r': case 's': case 't':
			case 'u': case 'v': case 'w': case 'x': case 'y':
			case 'z':
				break;
				*/
			case '\n':
				last_printed = pop();
				printf("\t%.8g\n", last_printed);
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else 
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-' && c != 's' && c != 'l')
		return c;

	if (c == 's' || c == 'l')
	{
		s[0] = getch();
		return (c == 's') ? VARIABLE_POP : VARIABLE_PUSH;
	}

	i = 0;

	if (c == '-')
		if (!isdigit(c = getch()))
		{
			/* 二項演算子のマイナス */
			ungetch(c);
			return '-';
		}
		else
			/* 単項演算子のマイナス */
			s[++i] = c;

	/* 整数部 */
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	/* 小数部 */
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many charactors\n");
	else
		buf[bufp++] = c;
}
