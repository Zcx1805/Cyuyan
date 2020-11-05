#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main(){
	char*a = NULL;
	int*b = NULL;
	double*c = NULL;
	//指针和常量加减就是位移一个数据类型的字节数
	printf("%p\n", a+1 );//1
	printf("%p\n", b +1);//4
	printf("%p\n", c +1);//8
	printf("%p\n", a + 2);//2
	printf("%p\n", b + 2);//8
	printf("%p\n", c + 2);//10（16进制=10进制16）
	system("pause");
	return 0;
}