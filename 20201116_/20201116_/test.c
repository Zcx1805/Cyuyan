#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#pragma warning(disable:4996)
//void leftRound(char * src, int time)
//{
//	int i, j, tmp;
//	int len = strlen(src);
//	time %= len; //长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推。
//	for (i = 0; i < time; i++) //执行k次的单次平移
//	{
//		tmp = src[0];
//		for (j = 0; j < len - 1; j++) //单次平移
//		{
//			src[j] = src[j + 1];
//		}
//		src[j] = tmp;
//	}
//}
int aabb(int a, int b){
	int c = a^b;
	int count = 0;
	for (int i = 0; i < 32; i++){
		if (c&(1 << i)){
			count++;
		}
	}
	printf("%d\n", count);
	return c;

}
//int main(){
//	//实现一个函数，可以左旋字符串中的k个字符。
//	//puts("你好");
//
//		int num1 = 100;
//		int num2 = 200;
//		//aabb(num1, num2);
//		printf("%d\n", aabb(num1, num2));
//		
//	system("pause");
//	return 0;
//}
void print(int n)
{
	int i = 0;
	printf(" 打印奇数位\n");
	for (i = 30; i >= 0; i = i - 2)
	{
		printf("%d ", (n >> i) & 1 == 1);
	}
	printf("\n");
	printf("打印偶数位\n");
	for (i = 31; i >= 1; i = i - 2)
	{
		printf("%d ", (n >> i) & 1 == 1);
	}
}

//shuixainhua
int shuixianhua(){//pow(x,n)
	for (int i = 99; i < 1000; i++){
		for (int j = 1; j < 10; j++){
			int c = 0;
			c=(i / 100);//百
			int d = 0;
			d=	((i / 10)%10);//⑩位
			int b = (i % 10);
			if (pow(c, j) + pow(d, j) +pow(b,j)== i){
				printf("%d\n", i);			
			}
		}
	}

}

void lingxing(int a){
	

}
int main(){
	/*int num = 0;
	int count = 0;
	printf("输入数字：\n");
	scanf("%d", &num);
	print(num);*/

	//shuixianhua();



	system("pause");
	return 0;
}