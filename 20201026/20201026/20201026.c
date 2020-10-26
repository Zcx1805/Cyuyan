#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void runnian(int year ){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		printf("是闰年\n");
	}
	else
	printf("不是闰年\n");
}
//实现一个函数来交换两个整数的内容。
void change(int *x, int *y){
	int sum;
	sum = *x;
	*x = *y;
	*y = sum;
}
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
int Cheng(int num){
	for (int a=1; a <= num; a++){
		for (int b=1; b <= a; b++){
			printf(" %d*%d=%d",b, a, a*b);
		}
		printf("\n");
	}
	return 0;
}
//递归方式实现打印一个整数的每一位
void Dg(int n){
	if (n > 9){
		Dg(n / 10);
	}
	printf("%d ", n % 10);
}
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
int Jc(int n){
	if (n==1){
		return 1;
	}
	return n*Jc(n - 1);
}
//实现一个函数，判断一个数是不是素数。
//利用上面实现的函数打印100到200之间的素数。
int Ss(int i){
	int i, n;
	for (i = 2; i < n; i++)
	{
		if (n%i == 0)
			break;
	}
	if (n <= 1) printf("既不是素数也不是合数\n");
	else  if (i < n) printf("合数.\n");
	else printf("素数.\n");
}
int main(){
	

	/*int a = 5;
	Jc(a);
	printf("%d", Jc(a));*/

	/*int a = 5;
	int b = 1;
	for (int i=1; i <= a; i++){
		b = b*i;
	}
	printf("%d", b);*/

	/*int i;
	printf("输入整数：\n");
	scanf(" %d", &i);
	Dg(i);*/
	
	/*int num=0;
	printf("输入乘法口诀数：\n");
	scanf("%d", &num);
	printf("%d",Cheng(num));*/

	//实现函数判断year是不是闰年。
	/*int year = 0;
	printf("输入年份判断是否是闰年：\n");
	scanf("%d", &year);
	Runnian(year);*/

	/*int a; int b;
	printf("输入2数字：\n");
	scanf("%d %d", &a,&b);
	Change(&a, &b);
	printf("%d %d", a, b);*/
	system("pause");
	return 0;
}