#include<stdio.h>
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	printf("请输入三个数:");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b){
		d = a;
		a = b;
		b = d;
	}
	else if (a > c){
		d = a;
		a = c;
		c = d;
	}
	else if (b>c){
		d = b;
		b = c;
		c = d;
	}
	printf("%d %d %d\n", c,b,a);
	system("pause");
	return 0;
}