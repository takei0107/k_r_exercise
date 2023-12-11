#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void clone(void);
void exchange(void);

int main()
{
	int type, mod;
	double op2;
	char s[MAXOP];

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
			case 'p':
				print_top();
				break;
			case 'c':
				clone();
				break;
			case 'x':
				exchange();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
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

void print_top(void)
{
	if (sp > 0)
		printf("\t%.8g\n", val[sp - 1]);
	else
		printf("stack empty\n");
}

void clone(void)
{
	if (sp > 0)
		push(val[sp - 1]);
	else
		printf("stack empty\n");
}

void exchange(void)
{
	double first, second;
	if (sp > 1)
	{
		first = val[sp - 1];
		second = val[sp - 2];

		val[sp - 1] = second;
		val[sp - 2] = first;
	}
	else
		printf("stack has not enough size\n");	
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

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

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
