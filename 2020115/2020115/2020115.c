#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main(){
	char*a = NULL;
	int*b = NULL;
	double*c = NULL;
	//ָ��ͳ����Ӽ�����λ��һ���������͵��ֽ���
	printf("%p\n", a+1 );//1
	printf("%p\n", b +1);//4
	printf("%p\n", c +1);//8
	printf("%p\n", a + 2);//2
	printf("%p\n", b + 2);//8
	printf("%p\n", c + 2);//10��16����=10����16��
	system("pause");
	return 0;
}