#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Exchange1(int a,int b){
	//�������ݽ���1������ʾ��
	int num = 0;
	num = a;
	a = b;
	b = num;
}

int Exchange2(int *a, int *b){
	//�������ݽ���2��׼ȷʾ��
	int num = 0;
	num = *a;
	*a =* b;
	*b = num;
}
int IsPrime(int n){
	//����ʾ��
	if (n == 1 || n <1){
		return 0;
	}
	for (int i = 2; i < n; i++){
		if (n%i == 0){
			return 0;
		}
	}
	//��������ʱ�������ֿ���
	//������������ѭ������n>=i����������
	return 1;
}
int main(){
	int num = 0;
	for (num = 100; num <= 200; num++){
		if (IsPrime(num) == 1){
			printf("%d\n", num);
		}
	}

	/*int x = 5; int y = 6;
	Exchange2(&x, &y);
	printf("%d %d\n", x, y);*/


	/*Exchange1(x, y);
	printf("%d %d\n", x, y);*/
	/*int a = 5;int b = 6;int num = 0;
	num = a;
	a = b;
	b = num;
	printf("%d %d\n", a, b);*/
	system("pause");
	return 0;
}