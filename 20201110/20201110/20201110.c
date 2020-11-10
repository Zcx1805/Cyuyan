#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Sn(int a, int n)
{
	int i = 0;
	int temp = 0;
	int sum = 0;
	for (; i < n; i++)
	{
		temp = temp * 10 + a;
		sum += temp;
		if (i == n - 1)
		{
			printf("%d", temp);
		}
		else
		{
			printf("%d+", temp);
		}
	}
	return sum;

}
int main()
{
	int a = 0;
	int n = 0;
	printf("please enter a and n:>");
	scanf("%d %d", &a, &n);
	Sn(a, n);
	int result = 0;
	printf("=%d", result);
	system("pause");
	return 0;
}




