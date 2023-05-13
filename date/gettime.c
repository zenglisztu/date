#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>

int GetTime(int *timeArr, int size)
{
	if (NULL == timeArr || size < 6)
	{
		return -1;
	}
	struct tm* timer = NULL;
	time_t time_stamp = time(NULL);
	timer = localtime(&time_stamp);

	timeArr[0] = timer->tm_year + 1900;
	timeArr[1] = timer->tm_mon + 1;
	timeArr[2] = timer->tm_mday;

	timeArr[3] = timer->tm_hour;
	timeArr[4] = timer->tm_min;
	timeArr[5] = timer->tm_sec;

	return 0;
}

/*
int year = timer->tm_year + 1900;
int mon = timer->tm_mon + 1;
int day = timer->tm_mday;

int hour = timer->tm_hour;
int min = timer->tm_min;
int sec = timer->tm_sec;
*/