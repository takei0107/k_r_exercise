#include <stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	mid = (low + high) / 2;

	while (low <= high && v[(mid = ((low + high) / 2))] != x)
	{
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (v[mid] == x)
		return mid;
	else
		return -1;

}

int main()
{
	int v[] = {7, 8, 9, 10, 11, 12, 13};
	int n = 6;

	printf("%d\n", binsearch(8, v, n));
	printf("%d\n", binsearch(10, v, n));
	printf("%d\n", binsearch(12, v, n));
	printf("%d\n", binsearch(1, v, n));
}
