#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Monsun(int year, int mon)
{
	static const leapyear[12] = { 31, 29, 31, 30, 31 ,30, 31, 31, 30, 31, 30, 31 };
	static const comyear[12] = { 31, 28, 31, 30, 31 ,30, 31, 31, 30, 31, 30, 31 };

	if (IsLeap(year))
	{
		return leapyear[mon - 1];
	}
	else
	{
		return comyear[mon - 1];
	}
}

int Daysum(int year, int mon , int day)
{
	int sum = 0;
	int i = 0;

	for (i = 1; i < mon; i++)
	{
		sum += Monsun(year, i);
	}

	return sum + day;

}

int GetWeek(int year, int mon, int day)
{
	int w = 0;
	if (mon == 1 || mon == 2)
	{
		mon += 12;
		year--;
	}
	w = (day + 2 * mon + 3 * (mon + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
	return w;
}

int PrintCalen(int *arr)
{
	int week = 0;
	int i = 0;
	int f = 1;
	int days = Monsun(arr[0], arr[1]);
	week = GetWeek(arr[0], arr[1], 1);
	color_(6);
	printf("SUN MON TUE WED THU FRI SAT \n");
	color_(11);
	if (week != 0)
	{
		printf("%*c", week * 4, ' ');
	}
	
	for (i = 1; i <= days; i++)
	{
		if (i == arr[2])
		{	
			color_(4);
			printf("%-4d", i);
			f = 0;
			color_(11);
		}
		if(f)
		{ 
			printf("%-4d", i);
		}
		if ((i + week) % 7 == 0)
		{
			printf("\n");
		}
		f = 1;
	}
	printf("\n");
	color_(7);
	return 0;
}

int PrintDate(int *arr)
{

	color_(14);
	printf("%-4d/%2d/%2d  ", arr[0], arr[1], arr[2]);
	color_(10);
	printf("%2d:%2d:%2d", arr[3], arr[4], arr[5]);
	color_(13);
	Printweek(GetWeek(arr[0], arr[1], arr[2]));
	printf("\n");
	color_(3);
	PrintMon(arr[1]);
	printf("\n");
	
	return 0;
}

int Printweek(int w)
{
	switch (w)
	{
		case 0: printf("  SUN") ; break;
		case 1: printf("  MON"); break;
		case 2: printf("  TUE"); break;
		case 3: printf("  WED"); break;
		case 4: printf("  THU"); break;
		case 5: printf("  FRI"); break;
		case 6: printf("  SAT"); break;
	}
	return 0;
}

int PrintMon(int mon)
{
	switch (mon)
	{
	case 1: printf("%12cJan",' '); break;
	case 2: printf("%12cFeb",' '); break;
	case 3: printf("%12cMar",' '); break;
	case 4: printf("%12cApr",' '); break;
	case 5: printf("%12cMay",' '); break;
	case 6: printf("%12cJun", ' '); break;
	case 7: printf("%12cJul", ' '); break;
	case 8: printf("%12cAug", ' '); break;
	case 9: printf("%12cSep", ' '); break;
	case 10: printf("%12cOct", ' '); break;
	case 11: printf("%12cNov", ' '); break;
	case 12: printf("%12cDec", ' '); break;
	}
	return 0;
}

int color_(int textColor)
{
	if (textColor >= 0 && textColor <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return 0;
}