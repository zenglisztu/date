#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#define PI 3.14

struct area
{
	int type;
	double len1;
	double len2;
	double (*parea)(double, double);
};

int select_type(struct area *graph);
int get_len(double* len1, double* len2);
double triangle_area(double len1, double len2);
double rectangle_area(double len1, double len2);
double ellipse_area(double len1, double len2);
int main(int argc, char* argv[])
{
	struct area graph = { 0 };

	select_type(&graph);
	if (graph.parea == NULL)
	{
		return -1;
	}
	get_len(&graph.len1, &graph.len2);
	printf("%.2lf", graph.parea(graph.len1, graph.len2));

	return 0;
}

int select_type(struct area* graph)
{
	int type = 0;

	printf("please seclet type:\n");
	printf("1-triangle\n");
	printf("2-rectangle\n");
	printf("3-ellipse\n");

	scanf("%d", &type);
	if (type < 1 || type > 3)
	{
		return -1;
	}

	switch (type)
	{
		case 1: graph->parea = triangle_area; break;
		case 2: graph->parea = rectangle_area; break;
		case 3: graph->parea = ellipse_area; break;
	}
	graph->type = type;
	return 0;

}

int get_len(double* len1, double* len2)
{
	if (NULL == len1 || NULL == len2)
	{
		return -1;
	}
	printf("penase enter 'len1' 'len2':");
	scanf("%lf%lf", len1, len2);
	return 0;
}

double triangle_area(double len1, double len2)
{
	return len1 * len2 * 0.5;
}

double rectangle_area(double len1, double len2)
{
	return len1 * len2;
}

double ellipse_area(double len1, double len2)
{
	return len1 * len2 * PI;
}

