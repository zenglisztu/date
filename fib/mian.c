#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int Fib(int num);
//int main(int argc, char* argv[])
//{
//	int n = 0;
//	printf("plaese enter:");
//	scanf("%d", &n);
//
//	printf("%d\n", Fib(n));
//
//	return 0;
//}
//
//int Fib(int num)
//{
//	if (num == 1 || num == 2)
//	{
//		return 1;
//	}
//	
//	return Fib(num - 1) + Fib(num - 2);
//
//}

#include<stdio.h>
#include <windows.h>

void color(const unsigned short textColor)
{
    if (textColor >= 0 && textColor <= 15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int main()
{
    color(0); printf("黑色\n");
    color(1);  printf("蓝色\n");
    color(2);  printf("绿色\n");
    color(3);  printf("湖蓝色\n");
    color(4);   printf("红色\n");
    color(5);   printf("紫色\n");
    color(6);  printf("黄色\n");
    color(7);   printf("白色\n");
    color(8);   printf("灰色\n");
    color(9);  printf("淡蓝色\n");
    color(10);  printf("淡绿色\n");
    color(11);  printf("淡浅绿色\n");
    color(12);  printf("淡红色\n");
    color(13);  printf("淡紫色\n");
    color(14);  printf("淡黄色\n");
    color(15);  printf("亮白色\n");
    color(16);    //因为这里大于15，恢复默认的颜色 
    printf("回到原来颜色\n");   //直接使用颜色函数
}