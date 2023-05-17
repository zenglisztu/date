#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpint(const void* pv1, const void* pv2);
int cmpdouble(const void* pv1, const void* pv2);
int print_arr(const void* arr, int size_t, int size);
void bsort(void* arr, int size_t, int size, int (*pfunc)(const void*, const void*));
int main(int argc, char* argv[])
{
	int arr_1[6] = { 21, 32, 54, 12, 8, 16 };
	double arr_2[6] = { 21.1, 32.1, 54.1, 12.1, 8.1, 16.1 };
	//qsort(arr_1, 6, sizeof(int), cmpint);
	//qsort(arr_2, 6, sizeof(double), cmpdouble);
	bsort(arr_1, 6, sizeof(int), cmpint);
	bsort(arr_2, 6, sizeof(double), cmpdouble);
	print_arr(arr_1, 6, sizeof(int));
	print_arr(arr_2, 6, sizeof(double));
	return 0;
}

/// <summary>
/// 接收两个整型地址，比较地址所在空间的数据大小
/// </summary>
/// <param name="pv1">整型1地址</param>
/// <param name="pv2">整型2地址</param>
/// <returns></returns>
int cmpint(const void* pv1, const void* pv2)
{
	return *(int*)pv1 - *(int*)pv2;
}
/// <summary>
/// 接收两个浮点型地址，比较地址所在空间的数据大小
/// </summary>
/// <param name="pv1">浮点型1地址</param>
/// <param name="pv2">浮点型2地址</param>
/// <returns>-1 小于 0 等于 1大于</returns>
int cmpdouble(const void* pv1, const void* pv2)
{
	if (*(double*)pv1 - *(double*)pv2 == 0)
	{
		return 0;
	}
	else if (*(double*)pv1 - *(double*)pv2 > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

/// <summary>
/// 打印数组
/// </summary>
/// <param name="arr">数组首地址</param>
/// <param name="size_t">数组元素个数</param>
/// <param name="size">每个数组元素字节数</param>
/// <returns>-1 打印失败 0 打印成功</returns>
int print_arr(const void* arr, int size_t, int size)
{
	if (arr == NULL || size_t <= 0 || size <= 0)
	{
		return -1;
	}
	if (size == sizeof(int))
	{
		int* p = (int*)arr;
		int i = 0;
		for (i = 0; i < size_t; i++)
		{
			printf("%-4d", p[i]);
		}
		printf("\n");
	}
	if (size == sizeof(double))
	{
		double* p = (double*)arr;
		int i = 0;
		for (i = 0; i < size_t; i++)
		{
			printf("%.2lf ", p[i]);
		}
		printf("\n");
	}
	return 0;
}

/// <summary>
/// 对数据进行排序
/// </summary>
/// <param name="arr">数组首地址</param>
/// <param name="size_t">数组元素</param>
/// <param name="size">每个数组元素字节数</param>
/// <param name="pfunc">排序函数</param>
void bsort(void* arr, int size_t, int size, int (*pfunc)(const void*, const void*))
{
	void* temp = NULL;
	temp = malloc(size);
	if (NULL == temp)
	{
		return;
	}
	memset(temp, 0, size);
	int i = 0;
	int j = 0;
	for (i = 0; i < size_t; i++)
	{
		for (j = 0; j < size_t - i - 1; j++)
		{
			if (pfunc((char*)arr + j * size,(char*)arr + (j + 1) * size) > 0)
			{
				memcpy(temp, (char*)arr + j * size, size);
				memcpy((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
				memcpy((char*)arr + (j + 1) * size, temp, size);
			}
		}
	}
	free(temp);
	temp = NULL;

}