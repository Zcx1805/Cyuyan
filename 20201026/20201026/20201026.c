#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void runnian(int year ){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		printf("������\n");
	}
	else
	printf("��������\n");
}
//ʵ��һ�������������������������ݡ�
void change(int *x, int *y){
	int sum;
	sum = *x;
	*x = *y;
	*y = sum;
}
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
int Cheng(int num){
	for (int a=1; a <= num; a++){
		for (int b=1; b <= a; b++){
			printf(" %d*%d=%d",b, a, a*b);
		}
		printf("\n");
	}
	return 0;
}
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void Dg(int n){
	if (n > 9){
		Dg(n / 10);
	}
	printf("%d ", n % 10);
}
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
int Jc(int n){
	if (n==1){
		return 1;
	}
	return n*Jc(n - 1);
}
//ʵ��һ���������ж�һ�����ǲ���������
//��������ʵ�ֵĺ�����ӡ100��200֮���������
int Ss(int i){
	int i, n;
	for (i = 2; i < n; i++)
	{
		if (n%i == 0)
			break;
	}
	if (n <= 1) printf("�Ȳ�������Ҳ���Ǻ���\n");
	else  if (i < n) printf("����.\n");
	else printf("����.\n");
}
int main(){
	

	/*int a = 5;
	Jc(a);
	printf("%d", Jc(a));*/

	/*int a = 5;
	int b = 1;
	for (int i=1; i <= a; i++){
		b = b*i;
	}
	printf("%d", b);*/

	/*int i;
	printf("����������\n");
	scanf(" %d", &i);
	Dg(i);*/
	
	/*int num=0;
	printf("����˷��ھ�����\n");
	scanf("%d", &num);
	printf("%d",Cheng(num));*/

	//ʵ�ֺ����ж�year�ǲ������ꡣ
	/*int year = 0;
	printf("��������ж��Ƿ������꣺\n");
	scanf("%d", &year);
	Runnian(year);*/

	/*int a; int b;
	printf("����2���֣�\n");
	scanf("%d %d", &a,&b);
	Change(&a, &b);
	printf("%d %d", a, b);*/
	system("pause");
	return 0;
}