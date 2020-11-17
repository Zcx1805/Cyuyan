#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//int arr[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(arr)); // 16
	//printf("%d\n", sizeof(arr + 0)); // 4 求 sizeof(int*)
	//printf("%d\n", sizeof(*arr)); // 4, 求 sizeof(int)
	//printf("%d\n", sizeof(arr + 1)); // 4, 求 sizeof(int*)
	//printf("%d\n", sizeof(arr[1])); // 4, 求 sizeof(int)
	//printf("%d\n", sizeof(&arr));// 4, 求 sizeof(int(*)[4]);
	//printf("%d\n", sizeof(*&arr));// 16, 求 sizeof(int[4]);
	//printf("%d\n", sizeof(&*arr));// 4, 求 sizeof(int*)
	//printf("%d\n", sizeof(&arr + 1)); // 4, 求 sizeof(int(*)[4])
	//printf("%d\n", sizeof(&arr[0])); // 4, 求 sizeof(int*)
	//printf("%d\n", sizeof(&arr[0] + 1)); // 4, 求 sizeof(int*)



	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr)); // 6, sizeof(char[6])
	//printf("%d\n", sizeof(arr + 0)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(*arr)); // 1, sizeof(char)
	//printf("%d\n", sizeof(arr + 1)); // 4
	//printf("%d\n", sizeof(arr[1]));// 1, sizeof(char)
	//printf("%d\n", sizeof(&arr));// 4, sizeof(char(*)[6])
	//printf("%d\n", sizeof(*&arr)); // 6, sizeof(char[6])
	//printf("%d\n", sizeof(&*arr));// 4, sizeof(char*)
	//printf("%d\n", sizeof(&arr[1] + 1)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(&arr + 1)); // 4, sizeof(char(*)[6]);

	 //此处的操作是未定义行为. arr 就不是一个 "字符串" 
	 //必须是带有 \0 的 char 数组才是字符串. 
	//printf("%d\n", strlen(arr)); // 未定义行为
	//printf("%d\n", strlen(arr + 0)); // 未定义行为
	//printf("%d\n", strlen(*arr)); // 
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));


	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr)); // 7, sizeof(char[7]);
	//printf("%d\n", sizeof(arr + 0)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(*arr)); // 1, sizeof(char)
	//printf("%d\n", sizeof(arr[1])); // 1, sizeof(char)
	//printf("%d\n", sizeof(&arr[0] + 1)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(&arr)); // 4 sizeof(char(*)[7])
	//printf("%d\n", sizeof(*&arr)); // 7 sizeof(char[7])
	//printf("%d\n", sizeof(&*arr)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(&arr + 1)); // 4 sizeof(char(*)[7])

	//printf("%d\n", strlen(arr)); // 6
	//printf("%d\n", strlen(arr + 1)); // 5
	//printf("%d\n", strlen(&arr + 1)); // 类型不匹配
	//printf("%d\n", strlen(&arr)); // 6  类型不匹配
	//printf("%d\n", strlen(&arr[0])); // 6
	//printf("%d\n", strlen(*&arr)); // 6
	//printf("%d\n", strlen(&*arr)); // 6
	//printf("%d\n", strlen(&arr[1] + 1));


	//char* p = "abcdef";

	//printf("%d\n", sizeof(p)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(p + 1)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(*p)); // 1 sizeof(char)
	//printf("%d\n", sizeof(p[0])); // 1 sizeof(char)
	//printf("%d\n", sizeof(&p)); // 4 sizeof(char**)
	//printf("%d\n", sizeof(&p[1] + 1)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(*&p)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(&*p)); // 4 sizeof(char*)

	//printf("%d\n", strlen(p)); // 6
	//printf("%d\n", strlen(p + 1)); // 5
	////printf("%d\n", strlen(*p)); // 类型不匹配
	////printf("%d\n", strlen(p[1])); // 类型不匹配
	////printf("%d\n", strlen(&p)); // 类型不匹配. 
	//printf("%d\n", strlen(&p[1] + 1)); // 4
	//printf("%d\n", strlen(*&p)); // 6
	//printf("%d\n", strlen(&*p)); // 6



	//int arr[3][4] = { 0 };
	//printf("%d\n", sizeof(arr)); // 48  sizeof(int[3][4])
	//printf("%d\n", sizeof(arr[0])); // 16 sizeof(int[4])
	//// arr[0] int[4], 再 + 1, 就把 int[4] 转成 int* 了
	//printf("%d\n", sizeof(arr[0] + 1)); // 4 sizeof(int*)
	//printf("%d\n", sizeof(&arr[0] + 1)); // 4 sizeof(int(*)[4])
	//printf("%d\n", sizeof(arr[0][0])); // 4 sizeof(int)
	//printf("%d\n", sizeof(*arr[0])); // 4, sizeof(int)
	//// arr 是二维数组 int[3][4] => int(*)[4] => * => int[4]
	// printf("%d\n", sizeof(*arr)); // 16 sizeof(int[4])
	//// arr + 1 => int(*)[4] => * => int[4]
	//printf("%d\n", sizeof(*(arr + 1))); // 16 sizeof(int[4])
	//// arr => int[3][4] => int(*)[4] => * => int[4] => +1 => int*
	//printf("%d\n", sizeof(*arr + 1));
	//// arr[0] => int[4] => & => int(*)[4] => +1 => int(*)[4]
	//printf("%d\n", sizeof(&arr[0] + 1)); // 4 sizeof(int(*)[4])
	// //arr[0] => int[4] => +1  => int*  => * => int
	//printf("%d\n", sizeof(*(arr[0] + 1)));



	//int a[5] = { 1, 2, 3, 4, 5 };
	//int *ptr = (int *)(&a + 1);
	//// *(a + 1) => a[1]
	//printf("%d,%d", *(a + 1), *(ptr - 1));


	// 由于后面的初始化语句都是 逗号表达式, 
	// 实际有效的值只是 1, 3, 5
	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//int *p;
	//p = a[0];
	//printf("%d", p[0]);


	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	system("pause");
	return 0;
}