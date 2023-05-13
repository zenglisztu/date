#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	char stack[100];
	int top;
};

struct Stack* GetLine(struct Stack* p, int size);
int PrintStack(struct Stack* p);

int main(int argc, char* argv[])
{
	struct Stack stack = { {0} };
	PrintStack(GetLine(&stack, 100));

	return 0;
}


struct Stack* GetLine(struct Stack* p, int size)
{
	char ch = 0;
	printf("prease enter string:");
	while ((ch = getchar()) != '\n')
	{
		if (ch == '#')
		{
			if (p->top != 0)
			{
				p->top--;
			}
		}
		else if ((ch == '@'))
		{
			p->top = 0;
		}
		else
		{	
			if (p->top < size)
			{
				p->stack[p->top] = ch;
				p->top++;
			}
			else
			{
				printf("stack full!");
			}
		}
	}
	return p;
}

int PrintStack(struct Stack* p)
{	
	int i = 0;
	if (p->top == 0)
	{
		printf("stack void\n");
	}
	else
	{
		for (i = 0; i < p->top; i++)
		{
			printf("%c", p->stack[i]);
		}
		printf("\n");
	}
	return 0;
}