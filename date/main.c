#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include "date.h"
#include "gettime.h"

int main(int argc, char* argv[])
{	
	int timearr[6] = { 0 };

	GetTime(timearr, 6);
	PrintDate(timearr);
	PrintCalen(timearr);

	return 0;
}
