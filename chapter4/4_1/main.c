#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int lim);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ea";

int main()
{
	char line[MAXLINE];
	int found = 0;
	int index;

	while (my_getline(line, MAXLINE) > 0)
		if ((index = strrindex(line, pattern)) >= 0)
		{
			printf("%d: %s",index, line);
			found++;
		}
	
	return found;
}
