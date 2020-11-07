#include<stdio.h>
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int i = 1;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			printf("%d", i);
	}
	system("pause");
	return 0;
}