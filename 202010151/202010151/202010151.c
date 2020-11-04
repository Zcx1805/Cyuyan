#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	/*int num[] = { 3, 4, 5, 6, 7, 8, 9 };
	int left = 0;
	int right = sizeof(num)/sizeof(num[0]) - 1;
	int a = 8;
	int mid = 0;
	while (left <= right){
		mid = (left + right) / 2;

		if (a > num[mid]){
			left = mid + 1;
		}
		else if (a < num[mid]){
			right = mid - 1;
		}
		else
			break;
	}
	if (left <= right)
		printf("%d", mid);
	else
		printf("ÕÒ²»µ½/n");*/
	/*int count = 0;

	for (int i = 0; i <= 100; i++)
	{
		if ((i % 10) == 9 || (i / 10) == 9) 
		{
			printf("%d\n", i);
			count++;
		}
	}
	printf("%d\n", count);*/
	/*int a = 0;
	double b = 0;
	for (a = 1; a < 101; a++)
	{
		b = (1.0 / a) * (pow(-1, (a + 1))) + b;
	}
	printf("%f\n", b);*/
	/*int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= i - 1; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j >= i)
		{
			printf("%d", i);

	}*/

	int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;
		if (b % 3 == 1)
		{
			b = b + 3;
			continue;
		}
		b = b - 5;
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}