#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//int print(int a){
//	printf("输入一个数字：");
//	scanf("%d", &a);
//	printf("%d,%d", a, &a);
//	return 0;
//}
//int main()
//{
	//int n = 10;
	//char* pc = (char*)&n;
	//int* pi = &n;
	//printf("%p\n", &n);
	//printf("%p\n", pc);
	//printf("%p\n", pc + 1);
	//printf("%p\n", pi);
	//printf("%p\n", pi + 1);
	//system("pause");
	//return 0;


	//int a = 0;
	//print(a);

	//int arr[10] = { 0 };
	//int *p = arr;
	//int i = 0;
	//for (i = 0; i <= 11; i++)
	//{
	//	//当指针指向的范围超出数组arr的范围时，p就是野指针
	//	*(p++) = i;
	//}
//}
//#include <stdio.h>
//int main()
//{
//	int arr[3] = { 1, 2, 3 };
//	int* p = &arr[1];
//
//	printf("%d ", *p);
//	printf("%d ", *(p - 1));
//	printf("%d ", *(p + 1));
//	system("pause");
//	return 0;

//代码1

//int main()
//{
//
//		int arr[4] = { 1, 2, 3, 4 };
//		int* p1 = &arr[0];
//		int* p2 = &arr[2];
//		printf("%d\n", p2 - p1);
//		system("pause");
//		return 0;
//	}

//代码1
//int main()
//{
//	int num = 10;
//	int* p = &num;
//	if (p) {
//		printf("不是空指针\n");
//	}
//	else {
//		printf("是空指针!\n");
//	}
//	system("pause");
//	return 0;
//}
//代码2
//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int* p = &num;
//	if (p != NULL) {
//		printf("不是空指针\n");
//	}
//	else {
//		printf("是空指针!\n");
//	}
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr[3] = { 0, 1, 2 };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr + 0));
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	system("pause");
//	return 0;
//}
int main()
{
	int arr[4] = { 1, 2, 3, 4 };
	int* p = arr + 1;
	//这个操作是允许的，数组下标一定是 [0, size-1] 范围
	// 但是指针的下标不一定. 取决于指针初始情况下指向谁. 
	printf("%d\n", p[-1]);
	printf("%d\n", *(p - 1));
	system("pause");
	return 0;
}







