//#include<stdio.h>
//#include<stdlib.h>
#pragma warning (disable:4996)
//
//	int isBigEnd(int a) {
//		int* p = &a;
//		char* p2 = (char*)p;
//		//�˴���ǿ������ת���������һ���ֽڵ�����
//		if (*p2 == 0x11) {
//			printf("����ֽ���");
//				return 1;
//		}
//		printf("С���ֽ���");
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
		printf("���!\n");
	}
	else {
		printf("�����\n");
	}
	system("pause");
	return 0;
}
