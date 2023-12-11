#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main()
{
	printf("%.10f\n", atof("123.45"));
	printf("%.10f\n", atof("123.45e+6"));
	printf("%.10f\n", atof("123.45e-6"));
}

double atof(char s[])
{
	double val, power, result;
	int i, j, sign, exp;

	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}	

	result = sign * val / power;
	
	if (s[i] == 'e' || s[i] == 'E')
		i++;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');

	power = 1.0;
	for (j = 1; j <= exp; j++)
		power = power * 10;

	if (sign < 0)
		result *= 1 / power;
	else
		result *= power;

	return result;
}

