#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
int menu() {
	printf("=============================\n");
	printf("==========1. 开始游戏========\n");
	printf("==========0. 退出游戏========\n");
	printf("=============================\n");
	printf(" 请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game() {
	int toGuess = rand() % 100 + 1;// 1. 程序自动生成一个 1-100 的随机整数. 
	while (1) {
		printf("请输入要猜的数字: ");
		int input = 0;
		scanf("%d", &input);
		// 3. 比较用户输入的数字和系统生成的数字之间的关系, 并给用户提示. 
		if (input < toGuess) {
			printf("低了!\n");
		}
		else if (input > toGuess) {
			printf("高了!\n");
		}
		else {
			printf("猜对了!\n");
			break;
		}
	}
}
int main()
{
	srand(time(0));
	//将现在的时间戳作为随机数种子
	while (1) {
		int choice = menu();//给用户一个交互的菜单
		if (choice == 1) {//用户开始游戏
			game();
		}
		else if (choice == 0) {
			printf("程序退出, 再见!\n");
			break;
		}
		else {
			// 写程序一定要考虑到用户的非法输入的情况. 
			printf("您的输入有误, 请重新输入!\n");
		}
	}
	system("pause");
	return 0;
}
