#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void countone(int a)
{
	int count = 0;
	for (int i = 0; i < 32; i++){
		if (a&(1 << i)){
			count++;
		}
	}
	printf("%d\n",count);
}


void print(int n)

{
	int i = 0;
	printf(" ��ӡ����λ\n");
	for (i = 30; i >= 0; i = i - 2)
	{
		printf("%d ", (n >> i) & 1==1);
	}
	printf("\n");
	printf("��ӡż��λ\n");
	for (i = 31; i >= 1; i = i - 2)
	{
		printf("%d ", (n >> i) & 1==1);
	}

}

int main(){
//#define _CRT_SECURE_NO_WARNINGS 1
//�Լ�д����ͬλ��
	/*int a = 5; int b = 9;
	int count = 0;
	for (int i = 0; i < 32; i++){
		if ((a&(1 << i)) != (b&(1 << i))){
			count++;
		}
	}
	printf("%d ", count);*/

	//����1����ȡ��������������һһ�Աȣ�����ͬcount++ ---���㷨Ч�ʵ�
	//����2��������� --- ��ͬΪ1 
		//int n = 0;
		//int m = 0;
		//printf("��������������");
		//scanf("%d %d", &n, &m);
		//int temp = n^m; //����һ������
		//int count = 0;
		//while (temp)
		//{
		//	temp = temp&(temp - 1);//����λ�Ƚϣ�Ϊ1��ѭ����Ϊ0��� ---����ͳ�Ƹ������Ż�����
		//	count++;
		//}
		//printf("%d\n", count);
		
	
		/*int n = 0;
		int m = 0;
		printf("��������������");
		scanf("%d%d", &n, &m);
		int count = 0;
		unsigned int num = m^n;
		while (num)
		{
			if (num % 2 == 1)
			{
				count++;
			}
			num = num / 2;
		}
		printf("%d\n", count);
		return 0;*/

	//ͳ�ƶ�������1�ĸ��� ����ҵ���� ��дһ���������ز����������� 1 �ĸ�����
	//1.����
	//2.ֱ��д
	/*int a = 15;
	countone(a);*/

	/*int a = 15;
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++){
		if ((a >> i) & 1==1 )
			count++;
	//}
	printf("%d", count);*/

	/*int a = 1;
	int b = 2;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("%d %d", a, b);*/



	int num = 0;
	int count = 0;
	printf("�������֣�\n");
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}