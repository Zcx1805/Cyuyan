#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int Factorial1(int a) {//��a�Ľ׳�
		int sum = 1;//����һ�������洢�׳�ֵ
		for (int i = 1; i <= a; i++) {//����i��ѭ��
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

	//дһ��������ӡarr��������ݣ���ʹ��������
	//�꣬ʹ��ָ�롣arr��һ������һά���顣
	//int arr[] = { 1, 2, 3, 4 };
	//
	//int* p = arr;  // ����������������Ԫ�صĵ�ַ
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	//{
	//	printf("%p\n ", p);   
	//	++p;                 
	//}


	//дһ����������������һ���ַ��������ݡ�

	/*char arr[] = "Hello";
	inverted(arr);
	printf("%s\n", arr);*/
	







	/*int a;
	printf("������Ҫ��Ľ׳�����\n");
	scanf("%d", &a);
	printf("%d", Factorial1(a));

	int a;
	printf("������Ҫ��Ľ׳�����\n");
	scanf("%d", &a);
	printf("%d",Factorial2(a));*/

	

	//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
	//���磺2 + 22 + 222 + 2222 + 22222
	int a = 0;
	printf("���룺");
	scanf("%d", &a);
	int count = (a * 5) + (10*a * 4 )+ (100*a * 3) + (1000*a * 2 )+ (10000*a);
	printf("%d\n", count);

	system("pause");
	return 0;
}