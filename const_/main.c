#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int a, int b);
int main(int argc, char* argv[])
{
	int (*pf) (int, int) = NULL;
	pf = sum;
	int arr[5] = { 1, 2, 3, 4, 5 };
	int(*pa)[5] = NULL;
	pa = &arr;
	printf("%d\n", *pa[0]);
	const int x = 10;
	int* p = (int *) & x;
	*p = 11;
	printf("%d\n", pf(2, 8));
	printf("%d\n", x);

	return 0;
}

int sum(int a, int b)
{
	return a + b;
}
