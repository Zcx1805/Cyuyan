#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int jc(int a){
	int result=1;
	for (int b = 1; b <= a; b++){
		result = result*b;
	}
	return result;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("ÊäÈëÊý×ÖÇó½×³Ë£º");
	scanf(" %d", &num1);
	for (int i = 0; i <= num1; i++){
		num2 = jc(i) + num2;
	}
	printf("%d", num2);
	system("pause");
	return 0;
}