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
	printf(" 打印奇数位\n");
	for (i = 30; i >= 0; i = i - 2)
	{
		printf("%d ", (n >> i) & 1==1);
	}
	printf("\n");
	printf("打印偶数位\n");
	for (i = 31; i >= 1; i = i - 2)
	{
		printf("%d ", (n >> i) & 1==1);
	}

}

int main(){
//#define _CRT_SECURE_NO_WARNINGS 1
//自己写的求不同位数
	/*int a = 5; int b = 9;
	int count = 0;
	for (int i = 0; i < 32; i++){
		if ((a&(1 << i)) != (b&(1 << i))){
			count++;
		}
	}
	printf("%d ", count);*/

	//方法1：获取二进制数，进行一一对比，若不同count++ ---该算法效率低
	//方法2：利用异或 --- 不同为1 
		//int n = 0;
		//int m = 0;
		//printf("请输入两个数：");
		//scanf("%d %d", &n, &m);
		//int temp = n^m; //异或后一个整体
		//int count = 0;
		//while (temp)
		//{
		//	temp = temp&(temp - 1);//相邻位比较，为1则循环，为0输出 ---类似统计个数的优化方案
		//	count++;
		//}
		//printf("%d\n", count);
		
	
		/*int n = 0;
		int m = 0;
		printf("请输入两个数：");
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

	//统计二进制中1的个数 。作业内容 。写一个函数返回参数二进制中 1 的个数。
	//1.函数
	//2.直接写
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
	printf("输入数字：\n");
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}