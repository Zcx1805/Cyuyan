#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#pragma warning(disable:4996)
//void leftRound(char * src, int time)
//{
//	int i, j, tmp;
//	int len = strlen(src);
//	time %= len; //����Ϊ5������£���ת6��11��16...���൱��1�Σ�7��12��17...���൱��2�Σ��Դ����ơ�
//	for (i = 0; i < time; i++) //ִ��k�εĵ���ƽ��
//	{
//		tmp = src[0];
//		for (j = 0; j < len - 1; j++) //����ƽ��
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
//	//ʵ��һ�����������������ַ����е�k���ַ���
//	//puts("���");
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
	printf(" ��ӡ����λ\n");
	for (i = 30; i >= 0; i = i - 2)
	{
		printf("%d ", (n >> i) & 1 == 1);
	}
	printf("\n");
	printf("��ӡż��λ\n");
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
			c=(i / 100);//��
			int d = 0;
			d=	((i / 10)%10);//��λ
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
	printf("�������֣�\n");
	scanf("%d", &num);
	print(num);*/

	//shuixianhua();



	system("pause");
	return 0;
}