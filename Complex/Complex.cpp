#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Complex
{
	double r;
	double v;
};

struct Complex add_1(struct Complex x1, struct Complex x2);
struct Complex add_2(struct Complex* p1, struct Complex* p2);
struct Complex* add_3(struct Complex* p1, struct Complex* p2, struct Complex* p3);
int GetComplex(struct Complex *p);
int main(int argc, char* argv[])
{

	struct Complex a = { 0 };
	struct Complex b = { 0 };
	struct Complex c = { 0 };
	
	GetComplex(&a);
	GetComplex(&b);
	//c = add_1(a, b);
	//c = add_2(&a, &b);
	add_3(&a, &b, &c);
	printf("c = %.1lf + %.1lfj", c.r, c.v);
	return 0;
}

struct Complex add_1(struct Complex x1, struct Complex x2)
{
	struct Complex y = { 0 };
	y.r = x1.r + x2.r;
	y.v = x1.v + x2.v;

	return y;
}

struct Complex add_2(struct Complex *p1, struct Complex *p2)
{
	struct Complex y = { 0 };
	y.r = p1->r + p2->r;
	y.v = p1->v + p2->v;

	return y;
}

struct Complex * add_3(struct Complex* p1, struct Complex* p2, struct Complex* p3)
{
	p3->r = p1->r + p2->r;
	p3->v = p1->v + p2->v;

	return p3;
}


int GetComplex(struct Complex *p)
{
	scanf("%lf", &(p->r));
	scanf("%lf", &(p->v));

	return 0;
}