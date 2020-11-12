#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main(){
	//杀手
	/*char killer;
	for (killer = 'A';killer <= 'D'; killer++){
		if (('A' != killer) + ('C' == killer) + ('D' == killer) + ('D' != killer) == 3){
			printf("%c\n", killer);
		}
	}*/

	//杨辉三角
	int arr[10][10] = { 0 };
	for (int a = 0; a < 10; a++){
		for (int b = 0; b < 10; b++){
			arr[a][0] = 1;
			arr[a][a] = 1;
		}
	}

	for (int a = 2; a < 10; a++){
		for (int b = 0; b < a; b++){
			arr[a][b] = arr[a - 1][b - 1] + arr[a - 1][b];
		}
	}

	for (int a = 0; a < 10; a++){
		for (int b = 0; b <= a; b++){
			printf("%4d", arr[a][b]);
		}
		printf("\n");
	}

	/*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
		A选手说：B第二，我第三；
		B选手说：我第二，E第四；
		C选手说：我第一，D第二；
		D选手说：C最后，我第三；
		E选手说：我第四，A第一；
		比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。*/
	/*for (int A = 1; A <= 5; A++){
		for (int B = 1; B <= 5; B++){
			for (int C = 1; C <= 5; C++){
				for (int D = 1; D <= 5; D++){
					for (int E = 1; E <= 5; E++){
						if ((B == 2 && A != 3) || (B != 2 && A == 3) == 1){
							if ((B == 2 && E != 4) || (B != 2 && E == 4) == 1){
								if ((C == 1 && D != 2) || (C != 1 && D == 2) == 1){
									if ((C == 5 && D != 3) || (C != 5 && D == 3) == 1){
										if ((E == 4 && A != 1) || (E != 4 && A == 1) == 1){
											if (A*B*C*D*E == 120){
												printf("A=%d\nB=%d\nC=%d\nD=%d\nE=%d\n", A, B, C, D, E);
											}
										}
									}
								}
							}
						}
					}
				}			
			}
		}
	}*/
	//100
	/*int student = 0x12345678;
	int student1 = 0x100;*/
	system("pause");
	return 0;
}