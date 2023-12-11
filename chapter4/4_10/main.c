#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define MAXOP 100
#define NUMBER '0'

int getline(char[], int);
void resetline(void);
int getop(char s[], char line[]);
void push(double);
double pop(void);

int main()
{
	int type, mod, len;
	int i;
	double op2;
	char s[MAXOP], line[MAXLINE];

	/*while ((type = getop(s)) != EOF)*/
	while (getline(line, MAXLINE) > 0)
	{
		resetline();
		while ((type = getop(s, line)) != '\n' && type != EOF)
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
					/*
				case '\n':
					printf("\t%.8g\n", pop());
					break;
					*/
				default:
					printf("error: unknown command %s\n", s);
					break;
			}
		}
		printf("\t%.8g\n", pop());
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

int linep;

/*int getch(void);*/

void resetline(void)
{
	linep = 0;
}

int getop(char s[], char line[])
{
	int i, c;

	while ((s[0] = c = line[linep++]) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	i = 0;

	if (c == '-')
		if (!isdigit(c = line[linep++]))
		{
			/* 二項演算子のマイナス */
			linep--;
			return '-';
		}
		else
			/* 単項演算子のマイナス */
			s[++i] = c;

	/* 整数部 */
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[linep++]))
			;

	/* 小数部 */
	if (c == '.')
		while (isdigit(s[++i] = c = line[linep++]))
			;

	s[i] = '\0';
	if (c != EOF)
		linep--;

	return NUMBER;
}
/*
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
*/

int getline(char s[], int lim)
{
	int i,c;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}
