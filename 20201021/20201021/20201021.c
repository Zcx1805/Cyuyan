#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main(){
	/*int num1 = 0;
	int num2 = 0;
	printf("�������������������Լ�����ÿո�����");
		scanf("%d %d", &num1, &num2);
	int min = num1;
	if (num1>num2){
		min = num2;
	}//����С�����ָ�ֵ��min
	int time = 0;
	for (int i = min; i >= 1; i--){
		time++;
		if (num1%i == 0 && num2%i == 0){
			printf("���ǵ����Լ���ǣ�%d\n ʱ�临�Ӷ���%d:\n", i, time);
			break;
		}
	}*/
	
	int num1, num2;
	printf("�������������������Լ�����ÿո�����");
	scanf("%d %d", &num1, &num2);
	int i ;
	int time = 0;
	while ((i = num1 % num2) != 0){
		num1 = num2;
		num2 = i;
		time++;
	}
	printf("���ǵ����Լ���ǣ�%d\n ʱ�临�Ӷ���%d:\n", num2, time);
	//������Լ����ʱ�临�Ӷ�	*/	
	/*int num1, num2, time=0;
	printf("�������������������Լ�����ÿո�����");
	scanf("%d %d", &num1, &num2);
	while (num1 != num2){
		if (num1>num2)
			num1 = num1 - num2;
		
		else
			num2 = num2 - num1;
		time++;
	}
	
	printf("���ǵ����Լ���ǣ�%d\n ʱ�临�Ӷ���%d:\n", num1, time);
*/

	system("pause");
	return 0;
}