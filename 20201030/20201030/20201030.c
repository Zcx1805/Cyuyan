//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#pragma warning(disable:4996)
//int Prime(int num){
//		if (num <2){
//			return 0;
//		}
//		for (int i = 2; i <sqrt(num*1.0); i++){
//			if (num%i == 0){
//				return 0;
//			}
//		}
//				return 1; 
//	}
//	int main()
//	{
//		int num = 0;
//		/*printf("����һ�����ж��Ƿ���������");
//			scanf("%d", &num);
//			int a=Prime(num);
//			if (a == 1){
//				printf("������");
//			}
//			else
//				printf("��������");*/
//			
//
//		
//		
//			
//			for (num = 1; num <= 20; num++){//����100-200������
//				if (Prime(num) == 1){//������return 1�Ķ�������
//					printf("%d\n", num);
//				}
//			}
//			
//		system("pause");
//		return 0;
//	}

/*#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int IsPrime(int n){
	if (n == 1 || n <1){
		return 0;
	}
	for (int i = 2; i < n/2; i++){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
}
int main()
{
	int num = 0;
	for (num = 1; num <= 20; num++){
		if (IsPrime(num) == 1){
			printf("%d ", num);
		}
	}
	system("pause");
	return 0;

}
#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)
int max(int x, int y)
{
	int z;
	z = x > y ? x : y;
	return (z);
}
int main()
{
	int max(int x, int y);
	int a, b, c;
	printf("�����������֣�");
	scanf("%d, %d", &a, &b);
	c = max(a, b);
	printf("����� %d\n", c);
	return 0;
}


#pragma warning (disable:4996)

int max(int x, int y)
{
	int z;
	z = x > y ? x : y;
	return (z);
}
#include<stdio.h>


int main()
{
	int max(int x, int y);
	int a, b, c;
	printf("�����������֣�");
	scanf("%d, %d", &a, &b);
	c = max(a, b);
	printf("����� %d\n", c);
	system("pause");
	return 0;

}

int MAX(int x, int y)
{
	if (x >= y)
		(printf(x));
	else
		(printf(y));
	return 0;
}
#include<stdio.h>
#include<windows.h>
int main()
{
	int Max(int x, int y);
	int a, b;
	printf("�����������ݣ�");
	scanf(a, b);
	printf("max :\n")
		return 0;


}


#pragma warning(disable:4996)

int MAX(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
	return 0;
}
#include<stdio.h>
#include<windows.h>
int main()
{
	int MAX(int x, int y);
	int a, b;
	printf("�����������ݣ�");
	scanf("%d %d", &a, &b);
	system("pause");
	printf("%d\n", MAX(a, b));
	system("pause");
	return 0;


}

#pragma warning(disable:4996)
int BigSmall(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

# include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("please enter two numbers:");
	scanf("%d %d", &a, &b);
	printf(" %d\n", BigSmall(a, b));
	system("pause");
}
#pragma warning(disable:4996)
int BigSmall(int x, int y)
{
	if (x > y)
		printf("%d", &x);

	else
		printf("%d", &y);

	���������
#include<stdio.h>
#include<windows.h>
	{
		int Myjia(int x, int y) }
	return x + y;
	{
		int Myjian(int x, int y)}
	return x - y;
	{
		int Mycheng(int x, int y) }
	return x*y;
	{
		int Mychu(int x, int y) }
	return x / y;
	int main()
	{
		printf("���������֣�/n");
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		char abc = 'm';
		printf("����+-* /��/n");
		csanf("%c", &abc);
		if (abc == '+'); {
			printf("%d+%d=%d", a, b, Myjia(a, b));
		else if (abc == '-'); {
			printf("%d-%d=%d", a, b, Myjian(a, b));
		else if (abc == '*'); {
			printf("%d*%d=%d", a, b, Mycheng(a, b));
		else if (abc == '/'); {
			printf("%d/%d=%d", a, b, Mychu(a, b));
		}
		if printf("error;/n")
		}

		}
		׼ȷ
#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

			int Myjia(int x, int y){
				return x + y;
			}
		int Myjian(int x, int y){
			return x - y;
		}
		int Mycheng(int x, int y) {
			return x*y;
		}
		int Mychu(int x, int y) {
			return x / y;

		};
		int main(){
			printf("���������֣�");
			int a = 0;
			int b = 0;
			scanf("%d %d", &a, &b);
			char abc = 'm';
			printf("����+ - * /:");
			scanf(" %c", &abc);  //%cǰ�ո񻺳���
			if (abc == '+') {
				printf("%d +%d =%d", a, b, Myjia(a, b));
			}
			else if (abc == '-') {
				printf("%d-%d=%d", a, b, Myjian(a, b));
			}
			else if (abc == '*'){
				printf("%d*%d=%d", a, b, Mycheng(a, b));
			}
			else if (abc == '/') {
				printf("%d/%d=%d", a, b, Mychu(a, b));
			}
			else{
				printf("error;");
			}
			system("pause");
			return 0;
		}*/