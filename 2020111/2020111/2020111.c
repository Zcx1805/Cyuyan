#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3
int menu(){
	printf("*******************\n");
	printf("****1.开始游戏*****\n");
	printf("****2.结束游戏*****\n");
	printf("*******************\n");
	int choice = 0;
	printf("输入你的选择：\n");
	scanf("%d", &choice);
	return choice;
}

void init(char chessboard[MAX_ROW][MAX_COL]){

	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chessboard[row][col] = ' ';
		}
	}
}

void printfchessboard(char chessboard[MAX_ROW][MAX_COL]){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chessboard[row][0], 
			chessboard[row][1], chessboard[row][2]);
		printf("+---+---+---+\n");
	}
	
}

void playerdo(char chessboard[MAX_ROW][MAX_COL]){
	while (1){
		printf(" 请玩家输入坐标(row col): ");
		int row = 0; int col = 0;
		scanf("%d %d", &row, &col);
		if (chessboard[row][col]!=' '){
			continue;
		}
		if (row<0||col<0||row>=MAX_ROW||col>=MAX_COL){
			continue;
		}
		chessboard[row][col] = 'x';
		break;
	}
}

int isfull(char chessboard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (chessboard[row][col] == ' '){
				return 0;
			}
			
		}
	}
	return 1;
}

char iswin(char chessboard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW;row++){
		if (chessboard[row][0] != ' '
			&& chessboard[row][0] == chessboard[row][1]
			&& chessboard[row][0] == chessboard[row][2])
			return chessboard[row][0];
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chessboard[0][col] != ' '
			&& chessboard[0][col] == chessboard[1][col]
			&& chessboard[0][col] == chessboard[2][col]) {
			return  chessboard[0][col];
		}
		if (chessboard[0][0] != ' '
			&& chessboard[0][0] == chessboard[1][1]
			&& chessboard[0][0] == chessboard[2][2]) {
			return chessboard[0][0];
		}
		if (chessboard[2][0] != ' '
			&& chessboard[2][0] == chessboard[1][1]
			&& chessboard[2][0] == chessboard[0][2]) {
			return chessboard[0][0];
		}
	}
		if (isfull(chessboard)==1){
			return 'z';//成功和棋
		}
		return ' ';
}

void computerdo(char chessboard[MAX_ROW][MAX_COL]){
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessboard [row][col]!= ' '){
			continue;
		}
		chessboard[row][col] = 'o';
		break;	
	}
}

void game(){
	char chessboard[MAX_ROW][MAX_COL] = { 0 };
	init(chessboard);
	char win = 'a';
	while (1){
		printfchessboard(chessboard);
		playerdo(chessboard);
		win = iswin(chessboard);
		if (win != ' '){
			break;
		}
		computerdo(chessboard);
		win = iswin(chessboard);
		if (win != ' '){
			break;
		}
	}
	printfchessboard(chessboard);
	if (win == 'x') {
		printf("win!\n");
	}
	else if (win == 'o') {
		printf("lose!\n");
	}
	else {
		printf("five five open!\n");
	}
}

int main()
{
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();
		if (1 == choice){
			game();
		}
		else if (2 == choice){
			printf("再见！");
			break;
		}
		else{
			printf("请输入正确指令！\n");
		}
	}
	system("pause");
	return 0;
}