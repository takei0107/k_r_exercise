#include <stdio.h>

#define swap(t,x,y) \
{ \
	t tmp; \
	tmp = x; \
	x = y; \
	y = tmp; \
}

#define CHMIN(xp, y) \
{ \
	if (*xp > y) \
		*xp = y; \
}

int main()
{
	int x = 1;
	int y = 99;
	swap(int , x, y);
	printf("x:%d, y:%d\n", x, y);
}
