#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// �������д���� C++ �е�д��
//#include <cstdlib>
// �������д���� C �����е�д��
#include <stdlib.h>
#include <time.h>

// ͨ��������������û����н���. 
int menu() {
	printf("=============================\n");
	printf(" 1. ��ʼ��Ϸ\n");
	printf(" 0. �˳���Ϸ\n");
	printf("=============================\n");
	printf(" ����������ѡ��: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

// ���ֺ���ʡ�Է���ֵ���͵�д��, ��һЩ�Ϲ�ʱ�������г��ֹ�. 
// ���������ʾ�����ķ���ֵ���;��� int . 
// ��������д����ʵ�Ǻ��Ϻ��ϵ� C ������֧�ֵ�. ���ڲ��Ƽ���ôд. 
void game() {
	// 1. �����Զ�����һ�� 1-100 ���������. 
	int toGuess = rand() % 100 + 1;
	while (1) {
		// 2. �ӿ���̨��ȡ�û�������. 
		printf("������Ҫ�µ�����: ");
		int input = 0;
		scanf("%d", &input);
		// 3. �Ƚ��û���������ֺ�ϵͳ���ɵ�����֮��Ĺ�ϵ, �����û���ʾ. 
		if (input < toGuess) {
			printf("����!\n");
		} else if (input > toGuess) {
			printf("����!\n");
		} else {
			printf("�¶���!\n");
			break;
		}
	}
}

int main() {
	// ��������Ϸ
	// �����Զ�����һ����������� (1-100)
	// �û�������һ������, ϵͳ������û���������
	// ����ʾ�û�, �ǲ¸��˻��ǵ���, ���ǲ¶���. 
	// ����һ����, ���Ǿ������������

	// ʹ�õ�ǰʱ����Ϊ�������. 
	//srand(time(0));
	//while (1) {
	//	// дһ����ӡ�˵��ĺ���, ���û����н���
	//	int choice = menu();
	//	if (choice == 1) {
	//		game();
	//	} else if (choice == 0) {
	//		printf("�����˳�, �ټ�!\n");
	//		break;
	//	} else {
	//		// д����һ��Ҫ���ǵ��û��ķǷ���������. 
	//		printf("������������, ����������!\n");
	//	}
	//}

	//int sum = 0;
	//for (int i = 0; i < 10; i++) {
	//	sum += i;
	//	printf("%d\n", i);
	//}
	//printf("sum = %d\n", sum);

	// �����������׳˵ĺ�. 
	// 1! + 2! + ... + n!
	int i = 0;
	int sum = 0;//�������ս��
	int n = 0;
	int ret = 1;//����n�Ľ׳�
	printf("������ n ��ֵ: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		// Ϊ�˽���ղŵ�����, ����Ҫ��ÿ����׳�֮ǰ, �� 
		// ret ������Ϊ 1
		ret = 1;
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);

	system("pause");
	return 0;
}