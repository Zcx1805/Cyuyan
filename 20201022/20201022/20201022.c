#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
int menu() {
	printf("=============================\n");
	printf("==========1. ��ʼ��Ϸ========\n");
	printf("==========0. �˳���Ϸ========\n");
	printf("=============================\n");
	printf(" ����������ѡ��: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game() {
	int toGuess = rand() % 100 + 1;// 1. �����Զ�����һ�� 1-100 ���������. 
	while (1) {
		printf("������Ҫ�µ�����: ");
		int input = 0;
		scanf("%d", &input);
		// 3. �Ƚ��û���������ֺ�ϵͳ���ɵ�����֮��Ĺ�ϵ, �����û���ʾ. 
		if (input < toGuess) {
			printf("����!\n");
		}
		else if (input > toGuess) {
			printf("����!\n");
		}
		else {
			printf("�¶���!\n");
			break;
		}
	}
}
int main()
{
	srand(time(0));
	//�����ڵ�ʱ�����Ϊ���������
	while (1) {
		int choice = menu();//���û�һ�������Ĳ˵�
		if (choice == 1) {//�û���ʼ��Ϸ
			game();
		}
		else if (choice == 0) {
			printf("�����˳�, �ټ�!\n");
			break;
		}
		else {
			// д����һ��Ҫ���ǵ��û��ķǷ���������. 
			printf("������������, ����������!\n");
		}
	}
	system("pause");
	return 0;
}
