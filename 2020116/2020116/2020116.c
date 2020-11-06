#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int Factorial1(int a) {//求a的阶乘
		int sum = 1;//定义一个变量存储阶乘值
		for (int i = 1; i <= a; i++) {//定义i做循环
			sum = sum * i;
		}
		return sum;
	}

int Factorial2(int a){
	if (a == 1){
		return 1;
	}
	return a*Factorial2(a - 1);
}

void inverted(char* arr){
	char* start = arr;
	char* end = arr + strlen(arr) - 1;
	if (start < end){
		char a = *start;
		*start = *end;
		*end = a;
		start++;
		end--;
	}
}
int main(){

	//写一个函数打印arr数组的内容，不使用数组下
	//标，使用指针。arr是一个整形一维数组。
	//int arr[] = { 1, 2, 3, 4 };
	//
	//int* p = arr;  // 数组名代表数组首元素的地址
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	//{
	//	printf("%p\n ", p);   
	//	++p;                 
	//}


	//写一个函数，可以逆序一个字符串的内容。

	/*char arr[] = "Hello";
	inverted(arr);
	printf("%s\n", arr);*/
	







	/*int a;
	printf("请输入要求的阶乘数：\n");
	scanf("%d", &a);
	printf("%d", Factorial1(a));

	int a;
	printf("请输入要求的阶乘数：\n");
	scanf("%d", &a);
	printf("%d",Factorial2(a));*/

	

	//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
	//例如：2 + 22 + 222 + 2222 + 22222
	int a = 0;
	printf("输入：");
	scanf("%d", &a);
	int count = (a * 5) + (10*a * 4 )+ (100*a * 3) + (1000*a * 2 )+ (10000*a);
	printf("%d\n", count);

	system("pause");
	return 0;
}