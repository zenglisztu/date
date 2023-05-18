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
/// �����������͵�ַ���Ƚϵ�ַ���ڿռ�����ݴ�С
/// </summary>
/// <param name="pv1">����1��ַ</param>
/// <param name="pv2">����2��ַ</param>
/// <returns></returns>
int cmpint(const void* pv1, const void* pv2)
{
	return *(int*)pv1 - *(int*)pv2;
}
/// <summary>
/// �������������͵�ַ���Ƚϵ�ַ���ڿռ�����ݴ�С
/// </summary>
/// <param name="pv1">������1��ַ</param>
/// <param name="pv2">������2��ַ</param>
/// <returns>-1 С�� 0 ���� 1����</returns>
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
/// ��ӡ����
/// </summary>
/// <param name="arr">�����׵�ַ</param>
/// <param name="size_t">����Ԫ�ظ���</param>
/// <param name="size">ÿ������Ԫ���ֽ���</param>
/// <returns>-1 ��ӡʧ�� 0 ��ӡ�ɹ�</returns>
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
/// �����ݽ�������
/// </summary>
/// <param name="arr">�����׵�ַ</param>
/// <param name="size_t">����Ԫ��</param>
/// <param name="size">ÿ������Ԫ���ֽ���</param>
/// <param name="pfunc">������</param>
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