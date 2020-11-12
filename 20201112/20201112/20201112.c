#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	return a / b;
}
int main(){
	typedef int(*Func)(int, int);
	Func arr[] = {
		NULL,
		add,
		sub,
		mul,
		Div,
	};

	while (1) {
		int choice = 0;
		int a = 0;
		int b = 0;
		int ret = 0;
		printf("请输入您的选择: ", &choice);
		scanf("%d", &choice);
		printf("请输入两个操作数: ");
		scanf("%d %d", &a, &b);
		/*if (choice == 1) {
			ret = add(a, b);
		} else if (choice == 2) {
			ret = sub(a, b);
		} else if (choice == 3) {
			ret = mul(a, b);
		} else if (choice == 4) {
			ret = Div(a, b);
		}*/
		 ret = arr[choice](a, b);
		printf("ret = %d\n", ret);
	}

	system("pause");
	return 0;
}