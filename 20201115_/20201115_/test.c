//#include<stdio.h>
//#include<stdlib.h>
#pragma warning (disable:4996)
//
//	int isBigEnd(int a) {
//		int* p = &a;
//		char* p2 = (char*)p;
//		//此处是强制类型转换，仅输出一个字节的内容
//		if (*p2 == 0x11) {
//			printf("大端字节序");
//				return 1;
//		}
//		printf("小端字节序");
//			return 0;
//	}
//	int main()
//	{
//	/*	int a = 0x11223344;
//		printf("%d\n", isBigEnd(a));*/
//
//
//		int num = -10;
//		system("pause");
//		return 0;
//	}
#include <stdio.h>
int main()
{
	float a = 11.0;
	float b = a / 3.0;
	if (b * 3.0 == a) {
		printf("相等!\n");
	}
	else {
		printf("不相等\n");
	}
	system("pause");
	return 0;
}
