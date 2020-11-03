#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main(){
	/*int num1 = 0;
	int num2 = 0;
	printf("请输入两个数字求最大公约数，用空格间隔：");
		scanf("%d %d", &num1, &num2);
	int min = num1;
	if (num1>num2){
		min = num2;
	}//把最小的数字赋值给min
	int time = 0;
	for (int i = min; i >= 1; i--){
		time++;
		if (num1%i == 0 && num2%i == 0){
			printf("它们的最大公约数是：%d\n 时间复杂度是%d:\n", i, time);
			break;
		}
	}*/
	
	int num1, num2;
	printf("请输入两个数字求最大公约数，用空格间隔：");
	scanf("%d %d", &num1, &num2);
	int i ;
	int time = 0;
	while ((i = num1 % num2) != 0){
		num1 = num2;
		num2 = i;
		time++;
	}
	printf("它们的最大公约数是：%d\n 时间复杂度是%d:\n", num2, time);
	//输出最大公约数和时间复杂度	*/	
	/*int num1, num2, time=0;
	printf("请输入两个数字求最大公约数，用空格间隔：");
	scanf("%d %d", &num1, &num2);
	while (num1 != num2){
		if (num1>num2)
			num1 = num1 - num2;
		
		else
			num2 = num2 - num1;
		time++;
	}
	
	printf("它们的最大公约数是：%d\n 时间复杂度是%d:\n", num1, time);
*/

	system("pause");
	return 0;
}