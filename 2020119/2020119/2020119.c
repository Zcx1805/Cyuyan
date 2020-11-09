#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int main()
{
	int intput = 0;
	printf(" ÊäÈëÆ¿Êý£º:>");
	scanf("%d", &intput);
	int count = 0;
	int price = 1;

	if (intput>2)
	{
		count = (intput / price);
		int empty = count;
		int temp = count;
		while (empty>1)
		{
			count += (empty / 2);
			empty = empty / 2 + empty % 2;

		}
	}
	else
	{
		count = (intput / price);
	}
	printf("%d\n", count);


	system("pause");
	return 0;
}
