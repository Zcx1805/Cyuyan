#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define DEFAULT_MINE_COUNT 10
int menu(){
	int choice = 0;
	printf("****************\n");
	printf("**1.play********\n");
	printf("**2.quit********\n");
	printf("****************\n");
	printf("输入你的选择：\n");
	scanf("%d", &choice);
	return choice;
}

void init(char showmap[MAX_ROW][MAX_COL],
	char minemap[MAX_ROW][MAX_COL]){
	
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			showmap[row][col] = ' *';
		}
	}
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			minemap[row][col] = '0';
		}
	}
	int n=DEFAULT_MINE_COUNT ;
	while (n>0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (minemap[row][col] == 1){
			continue;
		}
		minemap[row][col] ='1';
		n--;
	}
}

void printmap(char themap[MAX_ROW][MAX_COL]){
	printf("   |");
	for (int col = 0; col < MAX_COL; col++){
		printf("%d ", col);
	}
	printf("\n");
	printf("--+------------------\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf(" %d|",row);
		for (int col = 0; col < MAX_COL; col++){
			printf(" %c", themap[row][col]);
		}
		printf("\n");
	}
}

int updateshowmap(char showmap[MAX_ROW][MAX_COL] ,
char minemap[MAX_ROW][MAX_COL],int row,int col ){
	int count = 0;
	for (int R = row - 1; R <= row + 1; R++){
		for (int C = col - 1; C <= col + 1; C++){
			if (minemap[R][C] == '1'){
				count++;
			}
			if (R < 0 || R >= MAX_ROW
				|| C < 0 || C >= MAX_COL) {
				continue;
			}
		}
	}
	showmap[row][col] = count + '0';
}
	
void game(){
	char showmap[MAX_ROW][MAX_COL] = { 0 };
	char minemap[MAX_ROW][MAX_COL] = { 0 };
	init(showmap, minemap);
	int count = 0;
	while (1){
		printmap(minemap);
		printf("=================================\n");//辅助
		printmap(showmap);
		int row = 0;
		int col = 0;
		printf("请输入你的坐标：");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			continue;
		}
		if (showmap[row][col] !='*'){
			continue;
		}
		if (minemap[row][col] == '1'){
			printf("你输了！\n");
			break;
		}
		updateshowmap(showmap, minemap, row, col);
		count++;
		if (count == MAX_ROW * MAX_COL - DEFAULT_MINE_COUNT) {
			printf("游戏胜利!\n");
			printmap(minemap);
			break;
		}
	}
}
int main(){
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
		}
		else if (choice == 2){
			printf("bye\n");
			break;
		}
		else{ printf("输入错误\n");
		}	
	}
	system("pause");
	return 0;
}