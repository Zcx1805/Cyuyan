#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++){
		if (year % 4 == 0){
			printf("ÈòÄê: %d", year);
		}
		else{
			continue;
		}
	}
	system("pause");
	return 0;
}