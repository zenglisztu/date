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
    color(0); printf("��ɫ\n");
    color(1);  printf("��ɫ\n");
    color(2);  printf("��ɫ\n");
    color(3);  printf("����ɫ\n");
    color(4);   printf("��ɫ\n");
    color(5);   printf("��ɫ\n");
    color(6);  printf("��ɫ\n");
    color(7);   printf("��ɫ\n");
    color(8);   printf("��ɫ\n");
    color(9);  printf("����ɫ\n");
    color(10);  printf("����ɫ\n");
    color(11);  printf("��ǳ��ɫ\n");
    color(12);  printf("����ɫ\n");
    color(13);  printf("����ɫ\n");
    color(14);  printf("����ɫ\n");
    color(15);  printf("����ɫ\n");
    color(16);    //��Ϊ�������15���ָ�Ĭ�ϵ���ɫ 
    printf("�ص�ԭ����ɫ\n");   //ֱ��ʹ����ɫ����
}